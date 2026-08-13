#include <tamtypes.h>
#include <librac1/pad.h>
#include <librac1/game.h>
#include <librac1/graphics.h>
#include <librac1/interop.h>
#include <librac1/stdio.h>
#include <librac1/ui.h>

extern VariableAddress_t vaVU1FlipAndExpireTimers;
extern VariableAddress_t vaVU1FinalizeFramePacketChain;
extern VariableAddress_t vaUiVTable_Draw;
extern VariableAddress_t vaUiElementSelect_DrawList;
extern VariableAddress_t vaFontSet;
extern VariableAddress_t vaFontPrintWindow;

#define MOD_COLOR_SHADOW 0x80000000
#define MOD_STATE_MAGIC 0x4d4d3046
#define MOD_OPTION_COUNT 5
#define MOD_PTR_UNSET ((UiMenu_t *)0xffffffff)
#define MOD_MENU_ID UI_MENU_CUSTOM
#define MOD_STOCK_HELP_MENU ((UiMenu_t *)0x001b3e18)
#define MOD_UI_FRAME_ENABLES ((int *)0x001b2840)
#define MOD_TITLE_FONT_LINE_HEIGHT 0x10

typedef struct ModFontWindow {
    s16 clipTop;
    s16 clipBottom;
    s16 clipLeft;
    s16 clipRight;
    s16 x;
    s16 y;
    u32 pad0;
    s16 lineHeight;
    u16 flags;
    u16 pad1;
    s16 scrollOffset;
} ModFontWindow_t;

typedef void (*ModVu1FlipFn)(int ui);
typedef void (*ModVu1FinalizeFn)(void);
typedef u64 (*ModUiTextDrawFn)(UiElementBase_t *element);
typedef u64 (*ModUiListDrawFn)(UiElementList_t *element);
typedef int (*ModFontSetFn)(int font);
typedef int (*ModFontPrintWindowFn)(void *window, u32 color, const char *string, int length, u32 font, void *fontTable);

static u32 TitleColor = 0x80ffa888;
static u32 SelectedColor = 0x80006060;
static u32 NotSelectedColor = 0x80303030;

static int modmenuStateMagic = MOD_STATE_MAGIC;
static int modmenuSelected = 0;
static int modmenuLastRawButtons = 0xffff;
static UiMenu_t *modmenuOriginalHelpMenu = MOD_PTR_UNSET;
static UiMenu_t modmenuMenu;
static UiElementText_t modmenuTitle;
static UiElementList_t modmenuList;
static UiElementFooter_t modmenuFooter;
static M1138_MenuItem_Pvar_t modmenuTitleFrame;
static M1138_MenuItem_Pvar_t modmenuListFrame;
static M1138_MenuItem_Pvar_t modmenuFooterFrame;
static int modmenuFrameEnablesSaved = 0;
static int modmenuSavedFrameEnables[UI_MENU_MAX_ELEMENTS];
static int modmenuTitleDrawHits = 0;
static int modmenuListDrawHits = 0;
static int modmenuListUpdateHits = 0;
static int modmenuFooterDrawHits = 0;
static int modmenuTitleScreenX = 21;
static int modmenuTitleScreenY = 28;
static int modmenuTitleWindowW = 192;
static int modmenuTitleWindowH = 38;
static UiOptionEntry_t modmenuEntries[MOD_OPTION_COUNT + 1];
static UiOptionEntry_t modmenuFooterEntries[3];
static int modmenuOptionEnabled[MOD_OPTION_COUNT] = { 0, 0, 0, 0, 0 };
static const char *modmenuOptionLabels[MOD_OPTION_COUNT] = {
    "Help Log",
    "Controls",
    "Moves",
    "Weapons",
    "Gadgets"
};

static void modmenuSetVector(VECTOR output, float x, float y, float z)
{
    output[0] = x;
    output[1] = y;
    output[2] = z;
    output[3] = 1.0f;
}

static void modmenuRectVectors(VECTOR tl, VECTOR tr, VECTOR bl, VECTOR br, float x, float y, float w, float h)
{
    modmenuSetVector(tl, x, y, 0.0f);
    modmenuSetVector(tr, x + w, y, 0.0f);
    modmenuSetVector(bl, x, y + h, 0.0f);
    modmenuSetVector(br, x + w, y + h, 0.0f);
}

static int modmenuRawButtons(void)
{
    return (~P1_PAD->btns) & 0xffff;
}

static int modmenuRawPressed(int raw, int mask)
{
    return (raw & mask) && !(modmenuLastRawButtons & mask);
}

static int modmenuTextLength(const char *text)
{
    int length = 0;
    if (!text) {
        return 0;
    }
    while (text[length]) {
        length++;
    }
    return length;
}

static void modmenuAppendText(char *line, int *index, const char *text)
{
    int i = 0;
    while (text && text[i] && *index < 63) {
        line[*index] = text[i];
        (*index)++;
        i++;
    }
    line[*index] = 0;
}

static void modmenuOptionLine(char *line, int option)
{
    int index = 0;
    modmenuAppendText(line, &index, modmenuSelected == option ? "> " : "  ");
    modmenuAppendText(line, &index, modmenuOptionLabels[option]);
}

static int modmenuFontWindowBegin(void)
{
    ModVu1FlipFn vu1Flip;

    vu1Flip = (ModVu1FlipFn)GetAddressImmediate(&vaVU1FlipAndExpireTimers);
    if (!vu1Flip || !gfxAddRegister(0x42, 0x44) || !gfxAddRegister(0x47, 0x0b)) {
        return 0;
    }
    vu1Flip(0);
    return 1;
}

static void modmenuFontWindowEnd(void)
{
    ModVu1FinalizeFn vu1Finalize;

    vu1Finalize = (ModVu1FinalizeFn)GetAddressImmediate(&vaVU1FinalizeFramePacketChain);
    if (vu1Finalize) {
        vu1Finalize();
    }
}
static int modmenuUiFontWindowBegin(void)
{
    ModVu1FlipFn vu1Flip;

    vu1Flip = (ModVu1FlipFn)GetAddressImmediate(&vaVU1FlipAndExpireTimers);
    if (!vu1Flip || !gfxAddRegister(0x42, 0x44) || !gfxAddRegister(0x47, 0x2004b)) {
        return 0;
    }
    vu1Flip(0);
    return 1;
}

static int modmenuWindowTextRaw(int clipX, int clipY, int clipW, int clipH, int textX, int textY, u32 color, int fontId, void *fontTable, const char *text, int flags)
{
    ModFontWindow_t window;
    int font;

    if (!text) {
        return 0;
    }

    window.clipTop = (s16)clipY;
    window.clipBottom = (s16)(clipY + clipH);
    window.clipLeft = (s16)clipX;
    window.clipRight = (s16)(clipX + clipW);
    window.x = (s16)textX;
    window.y = (s16)textY;
    window.pad0 = 0;
    window.lineHeight = MOD_TITLE_FONT_LINE_HEIGHT;
    window.flags = (u16)flags;
    window.pad1 = 0;
    window.scrollOffset = 0;

    font = FontSet(fontId);
    if ((UI_FRAME_COUNTER & 0x3f) == 1) {
        printf("\nmod-menu FontWindow textxy=%d,%d clip=%d,%d,%d,%d flags=%04x text=%08x", textX, textY, window.clipTop, window.clipBottom, window.clipLeft, window.clipRight, window.flags, (u32)text);
    }
    FontPrintWindow(&window, color, text, -1, font, fontTable);
    return 1;
}

static int modmenuWindowTextShadow(int clipX, int clipY, int clipW, int clipH, int textX, int textY, u32 color, int fontId, void *fontTable, const char *text, int flags)
{
    modmenuWindowTextRaw(clipX, clipY, clipW, clipH, textX + 1, textY + 1, MOD_COLOR_SHADOW, fontId, fontTable, text, flags);
    return modmenuWindowTextRaw(clipX, clipY, clipW, clipH, textX, textY, color, fontId, fontTable, text, flags);
}

static int modmenuApproxSmallTextWidth(const char *text)
{
    return modmenuTextLength(text) * 9 + 4;
}

static void modmenuCacheTitleBounds(void)
{
    if (modmenuTitle.base.windowW > 0 && modmenuTitle.base.windowH > 0) {
        modmenuTitleScreenX = modmenuTitle.base.screenX;
        modmenuTitleScreenY = modmenuTitle.base.screenY;
        modmenuTitleWindowW = modmenuTitle.base.windowW;
        modmenuTitleWindowH = modmenuTitle.base.windowH;
    }
}

static void modmenuDrawTitleText(void)
{
    const char *title = "Help";
    int textX;
    int textY;

    textX = modmenuTitleScreenX + ((modmenuTitleWindowW - modmenuApproxSmallTextWidth(title)) / 2);
    textY = modmenuTitleScreenY + 11;
    FontPrintSmallHud(textX + 1, textY + 1, MOD_COLOR_SHADOW, title, modmenuTextLength(title));
    FontPrintSmallHud(textX, textY, 0x80ffffff, title, modmenuTextLength(title));
}

static u64 modmenuUiTitleDraw(UiElementText_t *element)
{
    const char *title = "Mod Menu";
    ModFontSetFn fontSet;
    ModFontPrintWindowFn fontPrintWindow;
    ModFontWindow_t window;
    int font;

    modmenuTitleDrawHits++;
    if (!element) {
        return 0;
    }

    window.clipTop = 4;
    window.clipBottom = (s16)(element->base.windowH - 4);
    window.clipLeft = 1;
    window.clipRight = (s16)(element->base.windowW - 4);
    window.x = (s16)(element->base.windowW / 2);
    window.y = (s16)(element->base.windowH / 2);
    window.pad0 = 0;
    window.lineHeight = MOD_TITLE_FONT_LINE_HEIGHT;
    window.flags = 0x000b;
    window.pad1 = 0;
    window.scrollOffset = 0;

    if ((UI_FRAME_COUNTER & 0x1f) == 1) {
        printf("\nmod-menu title custom window elem=%08x win=%d,%d pos=%d,%d textxy=%d,%d clip=%d,%d,%d,%d",
            (u32)element,
            element->base.windowW,
            element->base.windowH,
            element->base.screenX,
            element->base.screenY,
            window.x,
            window.y,
            window.clipTop,
            window.clipBottom,
            window.clipLeft,
            window.clipRight);
    }

    fontSet = (ModFontSetFn)GetAddressImmediate(&vaFontSet);
    fontPrintWindow = (ModFontPrintWindowFn)GetAddressImmediate(&vaFontPrintWindow);
    if (!fontSet || !fontPrintWindow || !modmenuUiFontWindowBegin()) {
        return 0;
    }

    font = fontSet(3);
    fontPrintWindow(&window, TitleColor, title, -1, font, (void *)0x001c3d10);
    modmenuFontWindowEnd();
    return UI_DRAW_RESULT_EXACT_SIZE;
}

static u64 modmenuUiFooterDraw(UiElementFooter_t *element)
{
    u64 result;

    modmenuFooterDrawHits++;
    if ((UI_FRAME_COUNTER & 0x1f) == 1) {
        printf("\nmod-menu footer stock pDraw elem=%08x win=%d,%d pos=%d,%d mode=%08x entries=%08x sel=%d",
            (u32)element,
            element ? element->base.windowW : -1,
            element ? element->base.windowH : -1,
            element ? element->base.screenX : -1,
            element ? element->base.screenY : -1,
            element ? element->modeFlags : 0,
            element ? (u32)element->pEntries : 0,
            element ? element->selectedIndex : -1);
        if (element && element->pEntries) {
            printf(" first=%04x,%04x second=%04x,%04x",
                element->pEntries[0].labelStringId.id,
                element->pEntries[0].labelStringId.flags,
                element->pEntries[1].labelStringId.id,
                element->pEntries[1].labelStringId.flags);
        }
    }
    {
        ModUiListDrawFn fn = (ModUiListDrawFn)GetAddressImmediate(&vaUiElementSelect_DrawList);
        result = fn ? fn((UiElementList_t *)element) : 0;
    }
    if ((UI_FRAME_COUNTER & 0x1f) == 1) {
        printf(" ret=%08x", (u32)result);
    }
    return result;
}

static u64 modmenuUiListDraw(UiElementList_t *element)
{
    u64 result;

    modmenuListDrawHits++;
    if ((UI_FRAME_COUNTER & 0x1f) == 1) {
        printf("\nmod-menu list stock pDraw elem=%08x win=%d,%d pos=%d,%d mode=%08x entries=%08x sel=%d first=%04x,%04x",
            (u32)element,
            element ? element->base.windowW : -1,
            element ? element->base.windowH : -1,
            element ? element->base.screenX : -1,
            element ? element->base.screenY : -1,
            element ? element->modeFlags : 0,
            element ? (u32)element->pEntries : 0,
            element ? element->selectedIndex : -1,
            element && element->pEntries ? element->pEntries[0].labelStringId.id : 0,
            element && element->pEntries ? element->pEntries[0].labelStringId.flags : 0);
    }
    {
        ModUiListDrawFn fn = (ModUiListDrawFn)GetAddressImmediate(&vaUiElementSelect_DrawList);
        result = fn ? fn(element) : 0;
    }
    if ((UI_FRAME_COUNTER & 0x1f) == 1) {
        printf(" ret=%08x", (u32)result);
    }
    return result;
}
static void modmenuReturnToPauseMenu(void)
{
    if (modmenuMenu.pParent) {
        UI_CHANGE_TO_POINTER = modmenuMenu.pParent;
    }
}

static void modmenuUiFrameUpdate(UiElementBase_t *element)
{
    int raw = modmenuRawButtons();

    if (modmenuRawPressed(raw, PAD_TRIANGLE | PAD_CIRCLE)) {
        modmenuReturnToPauseMenu();
        modmenuLastRawButtons = raw;
        return;
    }

    modmenuLastRawButtons = raw;
    uiVTableHandleExit(element);
}

static u64 modmenuUiUpdate(UiElementList_t *element)
{
    int raw = modmenuRawButtons();

    modmenuListUpdateHits++;

    if (modmenuRawPressed(raw, PAD_START | PAD_R3 | PAD_SELECT)) {
        modmenuLastRawButtons = raw;
        return 1;
    }
    if (modmenuRawPressed(raw, PAD_TRIANGLE | PAD_CIRCLE)) {
        modmenuReturnToPauseMenu();
        modmenuLastRawButtons = raw;
        return 0;
    }
    if (modmenuRawPressed(raw, PAD_UP)) {
        modmenuSelected--;
        if (modmenuSelected < 0) {
            modmenuSelected = MOD_OPTION_COUNT - 1;
        }
    }
    if (modmenuRawPressed(raw, PAD_DOWN)) {
        modmenuSelected++;
        if (modmenuSelected >= MOD_OPTION_COUNT) {
            modmenuSelected = 0;
        }
    }
    if (modmenuRawPressed(raw, PAD_CROSS)) {
        modmenuOptionEnabled[modmenuSelected] = !modmenuOptionEnabled[modmenuSelected];
    }

    if (element) {
        element->selectedIndex = modmenuSelected;
    }
    modmenuLastRawButtons = raw;
    return 0;
}

static void modmenuSetProbeFrame(M1138_MenuItem_Pvar_t *frame, float x, float y, float w, float h)
{
    if (!frame) {
        return;
    }
    uiFramePvarSetCorners2D(frame, x, y, 0.0f, w, h);
}

static void modmenuUpdateVisualProbe(void)
{
    modmenuSetProbeFrame(&modmenuTitleFrame, 275.0f, 28.0f, 260.0f, 20.0f);
    modmenuSetProbeFrame(&modmenuListFrame, 300.0f, 56.0f, 210.0f, 96.0f);
    modmenuSetProbeFrame(&modmenuFooterFrame, 300.0f, 160.0f, 210.0f, 24.0f);
}

static void modmenuRestoreFrameEnables(void)
{
    int i;

    if (!modmenuFrameEnablesSaved) {
        return;
    }
    for (i = 0; i < UI_MENU_MAX_ELEMENTS; i++) {
        MOD_UI_FRAME_ENABLES[i] = modmenuSavedFrameEnables[i];
    }
    modmenuFrameEnablesSaved = 0;
}

static void modmenuSetActiveFrameState(void)
{
    int i;

    if (!modmenuFrameEnablesSaved) {
        for (i = 0; i < UI_MENU_MAX_ELEMENTS; i++) {
            modmenuSavedFrameEnables[i] = MOD_UI_FRAME_ENABLES[i];
        }
        modmenuFrameEnablesSaved = 1;
    }

    for (i = 0; i < UI_MENU_MAX_ELEMENTS; i++) {
        MOD_UI_FRAME_ENABLES[i] = 0;
        modmenuMenu.pElements[i] = 0;
    }

    MOD_UI_FRAME_ENABLES[0] = 1;
    MOD_UI_FRAME_ENABLES[3] = 1;
    MOD_UI_FRAME_ENABLES[4] = 1;

    uiMenuSetElement(&modmenuMenu, 0, (UiElementBase_t *)&modmenuTitle);
    uiMenuSetElement(&modmenuMenu, 3, (UiElementBase_t *)&modmenuList);
    uiMenuSetElement(&modmenuMenu, 4, (UiElementBase_t *)&modmenuFooter);
    modmenuMenu.pSelectedElement = (UiElementBase_t *)&modmenuList;
    modmenuTitle.base.pDraw = (void *)modmenuUiTitleDraw;
    modmenuList.base.pDraw = (void *)modmenuUiListDraw;
    modmenuFooter.base.pDraw = (void *)modmenuUiFooterDraw;
    modmenuTitle.base.renderFlags = 0;
    modmenuList.base.renderFlags = 0;
    modmenuFooter.base.renderFlags = 0;
}

static UiPauseMenu_t *modmenuGetPauseMenu(void)
{
    UiMenu_t *activeMenu = (UiMenu_t *)UI_ACTIVE_POINTER;
    if (!activeMenu || activeMenu->menuId != UI_MENU_PAUSE_MAIN) {
        return 0;
    }
    return (UiPauseMenu_t *)activeMenu;
}

static int modmenuIsActiveMenu(void)
{
    return UI_ACTIVE_POINTER == &modmenuMenu;
}

static void modmenuCreateTitle(void)
{
    VECTOR tl;
    VECTOR tr;
    VECTOR bl;
    VECTOR br;

    modmenuRectVectors(tl, tr, bl, br, 275.0f, 28.0f, 260.0f, 20.0f);
    uiCreateTitle(&modmenuTitle, &modmenuTitleFrame, tl, tr, bl, br, 0x4f5e);
    modmenuTitle.base.pUpdate = (void *)uiVTableHandleExit;
    modmenuTitle.base.pInit = (void *)uiVTableUseResourceTableOff;
    modmenuTitle.base.pDraw = (void *)modmenuUiTitleDraw;
    modmenuTitle.base.renderFlags = 0;
}

static void modmenuCreateList(void)
{
    VECTOR tl;
    VECTOR tr;
    VECTOR bl;
    VECTOR br;
    int i;

    int ids[MOD_OPTION_COUNT] = { 0x4fd5, 0x4ef1, 0x4ef2, 0x4ee2, 0x4ee3 };
    UiMenu_t *nextMenus[MOD_OPTION_COUNT] = {
        (UiMenu_t *)0x001b40e0,
        (UiMenu_t *)0x001b4980,
        (UiMenu_t *)0x001b4ac8,
        (UiMenu_t *)0x001b51a0,
        (UiMenu_t *)0x001b5528
    };

    for (i = 0; i < MOD_OPTION_COUNT; i++) {
        modmenuEntries[i].labelStringId.flags = 3;
        modmenuEntries[i].labelStringId.id = ids[i];
        modmenuEntries[i].pNextMenu = nextMenus[i];
        modmenuEntries[i].timeSelected = 0;
    }
    modmenuEntries[MOD_OPTION_COUNT].labelStringId.flags = 0;
    modmenuEntries[MOD_OPTION_COUNT].labelStringId.id = 0;
    modmenuEntries[MOD_OPTION_COUNT].pNextMenu = 0;
    modmenuEntries[MOD_OPTION_COUNT].timeSelected = 0;

    modmenuRectVectors(tl, tr, bl, br, 300.0f, 56.0f, 210.0f, 96.0f);
    uiCreateSelectList(&modmenuList, &modmenuListFrame, tl, tr, bl, br, 0x1000, modmenuEntries, 0, 0, modmenuSelected);
    modmenuList.base.pUpdate = (void *)modmenuUiUpdate;
    modmenuList.base.pDraw = (void *)modmenuUiListDraw;
    modmenuList.base.renderFlags = 0;
}

static void modmenuCreateFooter(void)
{
    VECTOR tl;
    VECTOR tr;
    VECTOR bl;
    VECTOR br;
    int i;

    for (i = 0; i < 3; i++) {
        modmenuFooterEntries[i].labelStringId.id = 0;
        modmenuFooterEntries[i].labelStringId.flags = 0;
        modmenuFooterEntries[i].pNextMenu = 0;
        modmenuFooterEntries[i].timeSelected = 0;
    }

    modmenuFooterEntries[0].labelStringId.id = 0x4edf;
    modmenuFooterEntries[1].labelStringId.id = 0x4ee0;

    modmenuRectVectors(tl, tr, bl, br, 300.0f, 160.0f, 210.0f, 24.0f);
    uiCreateFooter(&modmenuFooter, &modmenuFooterFrame, tl, tr, bl, br, 0x4002, modmenuFooterEntries, 0, 0, 0);
    modmenuFooter.base.pUpdate = 0;
    modmenuFooter.base.pDraw = (void *)modmenuUiFooterDraw;
    modmenuFooter.base.renderFlags = 0;
}

static void modmenuPrepareCustomMenu(UiMenu_t *parent)
{
    int i;

    uiMenuInit(&modmenuMenu, parent, MOD_MENU_ID);
    modmenuCreateTitle();
    modmenuCreateList();
    modmenuCreateFooter();
    uiMenuCopyFrameAnims(&modmenuMenu, MOD_STOCK_HELP_MENU);
    for (i = 0; i < UI_MENU_MAX_ELEMENTS; i++) {
        uiMenuSetElement(&modmenuMenu, i, 0);
    }
    uiMenuSetElement(&modmenuMenu, 0, (UiElementBase_t *)&modmenuTitle);
    uiMenuSetElement(&modmenuMenu, 3, (UiElementBase_t *)&modmenuList);
    uiMenuSetElement(&modmenuMenu, 4, (UiElementBase_t *)&modmenuFooter);
    modmenuMenu.pSelectedElement = (UiElementBase_t *)&modmenuList;
}

static void modmenuPatchHelpEntry(void)
{
    UiMenuOption_t *help;
    UiPauseMenu_t *pauseMenu = modmenuGetPauseMenu();

    if (!pauseMenu) {
        return;
    }

    help = &pauseMenu->entries.help;
    if (modmenuOriginalHelpMenu == MOD_PTR_UNSET) {
        modmenuOriginalHelpMenu = help->pNextMenu ? help->pNextMenu : MOD_STOCK_HELP_MENU;
    }

    if (modmenuMenu.pParent != &pauseMenu->menu || help->pNextMenu != &modmenuMenu) {
        modmenuPrepareCustomMenu(&pauseMenu->menu);
    }
    help->pNextMenu = &modmenuMenu;
}

static void modmenuEnsureState(void)
{
    int i;

    if (modmenuStateMagic == MOD_STATE_MAGIC) {
        return;
    }

    modmenuStateMagic = MOD_STATE_MAGIC;
    modmenuSelected = 0;
    modmenuLastRawButtons = modmenuRawButtons();
    modmenuOriginalHelpMenu = MOD_PTR_UNSET;
    uiMenuInit(&modmenuMenu, 0, MOD_MENU_ID);
    for (i = 0; i < MOD_OPTION_COUNT; i++) {
        modmenuOptionEnabled[i] = 0;
    }
}

static int modmenuHasUiState(void)
{
    return UI_ACTIVE_POINTER != 0 || gameMode == GAME_MODE_PAUSE || gameMode_startMenu != 0;
}

static void modmenuDraw(void)
{
    if (!modmenuHasUiState()) {
        return;
    }

    modmenuEnsureState();
    modmenuPatchHelpEntry();

    if (modmenuIsActiveMenu()) {
        modmenuSetActiveFrameState();
        return;
    }

    modmenuRestoreFrameEnables();
}

int main(void)
{
    (void)SelectedColor;
    (void)NotSelectedColor;
    modmenuDraw();
    return 0;
}
