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
#define MOD_ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))
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

typedef struct ModMenuOption {
    const char *label;
    UiMenu_t *pNextMenu;
} ModMenuOption_t;

typedef enum ModMenuSettingType {
    MOD_SETTING_TOGGLE,
    MOD_SETTING_TOGGLE_INVERTED,
    MOD_SETTING_LIST,
    MOD_SETTING_NUMBER
} ModMenuSettingType_t;

typedef struct ModMenuSetting {
    const char *label;
    ModMenuSettingType_t type;
    const char **choices;
    int choiceCount;
    int minValue;
    int maxValue;
    const char *description;
} ModMenuSetting_t;

static u32 TitleColor = 0x80ffa888;
static u32 SelectedColor = 0x8000ffff;
static u32 NotSelectedColor = 0x80ffb080;

static int modmenuStateMagic;
static int modmenuSelected;
static int modmenuLastRawButtons;
static int modmenuLastPressureButtons;
static int modmenuLastHudButtons;
static int modmenuDpadRepeatTimer;
static int modmenuLastDirection;
static UiMenu_t *modmenuOriginalHelpMenu;
static UiMenu_t modmenuMenu;
static UiElementText_t modmenuTitle;
static UiElementList_t modmenuList;
static UiElementFooter_t modmenuFooter;
static M1138_MenuItem_Pvar_t modmenuTitleFrame;
static M1138_MenuItem_Pvar_t modmenuListFrame;
static M1138_MenuItem_Pvar_t modmenuFooterFrame;
static int modmenuFrameEnablesSaved;
static int modmenuSavedFrameEnables[UI_MENU_MAX_ELEMENTS];
static int modmenuTitleDrawHits;
static int modmenuListDrawHits;
static int modmenuListUpdateHits;
static int modmenuFooterDrawHits;
static int modmenuTitleScreenX = 21;
static int modmenuTitleScreenY = 28;
static int modmenuTitleWindowW = 192;
static int modmenuTitleWindowH = 38;
static ModMenuOption_t modmenuOptions[] = {
    { "Submenu 1", 0 },
    { "Submenu 2", 0 },
    { "Submenu 3", 0 },
    { "Submenu 4", 0 },
    { "Submenu 5", 0 },
    { "Submenu 6", 0 },
};
#define MOD_OPTION_COUNT ((int)MOD_ARRAY_COUNT(modmenuOptions))
#define MOD_SUBMENU_DEFAULT_OPTION_COUNT 4
#define MOD_SUBMENU_MAX_OPTION_COUNT 12
#define MOD_SUBMENU_MIN_ROW_HEIGHT 34
#define MOD_SUBMENU_ROW_BG_PADDING 4
#define MOD_SUBMENU_SHADOW_COLOR 0x80000000
#define MOD_OPTION_TERMINATOR_COUNT 1

static UiOptionEntry_t modmenuEntries[MOD_ARRAY_COUNT(modmenuOptions) + MOD_OPTION_TERMINATOR_COUNT];
#define MOD_OPTION_ENTRY_COUNT ((int)MOD_ARRAY_COUNT(modmenuEntries))
static UiOptionEntry_t modmenuFooterEntries[3];
static int modmenuOptionEnabled[MOD_ARRAY_COUNT(modmenuOptions)];
static const char *modmenuFooterLabels[2] = {
    "\x11 Select",
    "\x12 Exit"
};
static const char *modmenuSubmenuFooterText = "\x11 Toggle  \x12 Back";
static UiMenu_t modmenuSubmenus[MOD_ARRAY_COUNT(modmenuOptions)];
static UiElementText_t modmenuSubmenuTitles[MOD_ARRAY_COUNT(modmenuOptions)];
static UiElementText_t modmenuSubmenuBodies[MOD_ARRAY_COUNT(modmenuOptions)];
static UiElementText_t modmenuSubmenuFooters[MOD_ARRAY_COUNT(modmenuOptions)];
static UiElementText_t modmenuSubmenuDescriptions[MOD_ARRAY_COUNT(modmenuOptions)];
static M1138_MenuItem_Pvar_t modmenuSubmenuTitleFrames[MOD_ARRAY_COUNT(modmenuOptions)];
static M1138_MenuItem_Pvar_t modmenuSubmenuBodyFrames[MOD_ARRAY_COUNT(modmenuOptions)];
static M1138_MenuItem_Pvar_t modmenuSubmenuFooterFrames[MOD_ARRAY_COUNT(modmenuOptions)];
static M1138_MenuItem_Pvar_t modmenuSubmenuDescriptionFrames[MOD_ARRAY_COUNT(modmenuOptions)];
static int modmenuSubmenuSelected[MOD_ARRAY_COUNT(modmenuOptions)];
static int modmenuSubmenuValues[MOD_ARRAY_COUNT(modmenuOptions)][MOD_SUBMENU_MAX_OPTION_COUNT];
static char modmenuListLabels[MOD_ARRAY_COUNT(modmenuOptions)][64];
static char modmenuSubmenuValueLabels[MOD_SUBMENU_MAX_OPTION_COUNT][32];
static int modmenuForceCustomMenuFrames;

static const char *modmenuSettingSpeedChoices[] = { "Slow", "Normal", "Fast" };
static const char *modmenuSettingModeChoices[] = { "Off", "Low", "High", "Max" };
static const ModMenuSetting_t modmenuSubmenuSettings[MOD_SUBMENU_MAX_OPTION_COUNT] = {
    { "Infinite Health", MOD_SETTING_TOGGLE, 0, 0, 0, 0, "Prevents Ratchet from losing health while this option is enabled." },
    { "Disable Damage", MOD_SETTING_TOGGLE_INVERTED, 0, 0, 0, 0, "Inverted toggle example. ON stores zero, OFF stores one." },
    { "Movement Speed", MOD_SETTING_LIST, modmenuSettingSpeedChoices, (int)MOD_ARRAY_COUNT(modmenuSettingSpeedChoices), 0, 0, "Cycles between several named speed presets." },
    { "Bolt Multiplier", MOD_SETTING_NUMBER, 0, 0, 1, 9, "Cycles a numeric multiplier value without drawing a range bar." },
    { "Moon Jump", MOD_SETTING_TOGGLE, 0, 0, 0, 0, "Example boolean option for testing longer submenu lists." },
    { "Unlock Weapons", MOD_SETTING_TOGGLE, 0, 0, 0, 0, "Example boolean option for testing longer submenu lists." },
    { "Quick Select Mode", MOD_SETTING_LIST, modmenuSettingModeChoices, (int)MOD_ARRAY_COUNT(modmenuSettingModeChoices), 0, 0, "Cycles through multiple named modes." },
    { "Ammo Level", MOD_SETTING_NUMBER, 0, 0, 0, 10, "Cycles a number from zero to ten." },
    { "Armor Upgrade", MOD_SETTING_TOGGLE, 0, 0, 0, 0, "Example boolean option for testing scrolling." },
    { "Planet Flags", MOD_SETTING_LIST, modmenuSettingModeChoices, (int)MOD_ARRAY_COUNT(modmenuSettingModeChoices), 0, 0, "Another multi-choice placeholder setting." },
    { "Debug Camera", MOD_SETTING_TOGGLE, 0, 0, 0, 0, "Example toggle used to keep Submenu 1 scrollable." },
    { "Test Number", MOD_SETTING_NUMBER, 0, 0, 0, 5, "Small numeric cycle test option." },
};
static const int modmenuHelpTopicAnimIds[][UI_MENU_MAX_ELEMENTS] = {
    { 185, 186, 187, 188, 189, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
    { 57, 58, 59, 60, 61, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
    { 62, 63, 64, 65, 66, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
};
#define MOD_HELP_TOPIC_ANIM_SET_COUNT ((int)MOD_ARRAY_COUNT(modmenuHelpTopicAnimIds))

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

static void modmenuCopyAnimIds(UiMenu_t *menu, const int *animIds)
{
    int i;

    if (!menu || !animIds) {
        return;
    }

    for (i = 0; i < UI_MENU_MAX_ELEMENTS; i++) {
        menu->mobyAnimIds[i] = animIds[i];
    }
}

static void modmenuMoveSelection(UiElementList_t *element, int delta);
static void modmenuSetActiveFrameState(void);

static int modmenuRawButtons(void)
{
    return (~P1_PAD->btns) & 0xffff;
}

static int modmenuRawPressed(int raw, int mask)
{
    return (raw & mask) && !(modmenuLastRawButtons & mask);
}

static int modmenuPressureButtons(void)
{
    int buttons = 0;

    if (P1_PAD->up_p) {
        buttons |= PAD_UP;
    }
    if (P1_PAD->down_p) {
        buttons |= PAD_DOWN;
    }
    if (P1_PAD->left_p) {
        buttons |= PAD_LEFT;
    }
    if (P1_PAD->right_p) {
        buttons |= PAD_RIGHT;
    }

    return buttons;
}

static int modmenuPressurePressed(int buttons, int mask)
{
    return (buttons & mask) && !(modmenuLastPressureButtons & mask);
}

static int modmenuHudPressed(int buttons, int mask)
{
    return (buttons & mask) && !(modmenuLastHudButtons & mask);
}

static int modmenuDirectionPressed(int hud, int pressure, int rawMask, int hudMask)
{
    if (modmenuPressurePressed(pressure, rawMask)) {
        return 1;
    }
    return modmenuHudPressed(hud, hudMask);
}
static int modmenuDpadHeld(int rawMask, int hudMask, unsigned char pressure)
{
    if (modmenuRawButtons() & rawMask) {
        return 1;
    }
    if (pressure) {
        return 1;
    }
    if (P1_PAD->hudBits & hudMask) {
        return 1;
    }
    if (P1_PAD->hudBitsOn & hudMask) {
        return 1;
    }
    return 0;
}

static int modmenuReadDirection(void)
{
    if (modmenuDpadHeld(PAD_UP, PAD_REVERSED_UP, P1_PAD->up_p)) {
        return -1;
    }
    if (modmenuDpadHeld(PAD_DOWN, PAD_REVERSED_DOWN, P1_PAD->down_p)) {
        return 1;
    }
    return 0;
}

static void modmenuApplyDirection(UiElementList_t *element, int direction)
{
    if (direction == 0) {
        modmenuLastDirection = 0;
        modmenuDpadRepeatTimer = 0;
        return;
    }

    if (direction != modmenuLastDirection || modmenuDpadRepeatTimer <= 0) {
        modmenuMoveSelection(element, direction);
        modmenuDpadRepeatTimer = direction == modmenuLastDirection ? 5 : 14;
        modmenuLastDirection = direction;
        return;
    }

    modmenuDpadRepeatTimer--;
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

static void modmenuAppendInt(char *line, int *index, int value)
{
    char digits[10];
    int count = 0;

    if (value <= 0) {
        if (*index < 63) {
            line[*index] = '0';
            (*index)++;
            line[*index] = 0;
        }
        return;
    }

    while (value > 0 && count < (int)sizeof(digits)) {
        digits[count] = (char)('0' + (value % 10));
        value /= 10;
        count++;
    }

    while (count > 0 && *index < 63) {
        count--;
        line[*index] = digits[count];
        (*index)++;
    }
    line[*index] = 0;
}

static void modmenuOptionLine(char *line, int option, int selected)
{
    int index = 0;

    (void)selected;
    modmenuAppendText(line, &index, modmenuOptions[option].label);
}

static const char *modmenuOptionDrawLabel(int option, int selected)
{
    if (option < 0 || option >= MOD_OPTION_COUNT) {
        return "";
    }

    modmenuOptionLine(modmenuListLabels[option], option, selected);
    return modmenuListLabels[option];
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
    ModFontSetFn fontSet;
    ModFontPrintWindowFn fontPrintWindow;
    ModFontWindow_t window;
    int font;
    int rowHeight;
    int i;

    modmenuFooterDrawHits++;
    if (!element) {
        return 0;
    }

    if ((UI_FRAME_COUNTER & 0x1f) == 1) {
        printf("\nmod-menu footer custom pDraw elem=%08x win=%d,%d pos=%d,%d labels=%s/%s",
            (u32)element,
            element->base.windowW,
            element->base.windowH,
            element->base.screenX,
            element->base.screenY,
            modmenuFooterLabels[0],
            modmenuFooterLabels[1]);
    }

    fontSet = (ModFontSetFn)GetAddressImmediate(&vaFontSet);
    fontPrintWindow = (ModFontPrintWindowFn)GetAddressImmediate(&vaFontPrintWindow);
    if (!fontSet || !fontPrintWindow || !modmenuUiFontWindowBegin()) {
        return 0;
    }

    font = fontSet(3);
    rowHeight = element->base.windowH / 2;
    if (rowHeight < 1) {
        rowHeight = element->base.windowH;
    }

    window.clipLeft = 1;
    window.clipRight = (s16)(element->base.windowW - 4);
    window.x = (s16)(element->base.windowW / 2);
    window.pad0 = 0;
    window.lineHeight = MOD_TITLE_FONT_LINE_HEIGHT;
    window.flags = 0x000b;
    window.pad1 = 0;
    window.scrollOffset = 0;

    for (i = 0; i < 2; i++) {
        window.clipTop = (s16)(i * rowHeight);
        window.clipBottom = (s16)((i + 1) * rowHeight);
        window.y = (s16)((window.clipTop + window.clipBottom) / 2);
        fontPrintWindow(&window, MOD_COLOR_SHADOW, modmenuFooterLabels[i], -1, font, (void *)0x001c3d10);
        window.y = (s16)(window.y - 1);
        fontPrintWindow(&window, TitleColor, modmenuFooterLabels[i], -1, font, (void *)0x001c3d10);
    }

    modmenuFontWindowEnd();
    return UI_DRAW_RESULT_EXACT_SIZE;
}

static u64 modmenuUiListDraw(UiElementList_t *element)
{
    ModFontSetFn fontSet;
    ModFontPrintWindowFn fontPrintWindow;
    ModFontWindow_t window;
    int font;
    int rowHeight;
    int listTop;
    int i;

    modmenuListDrawHits++;
    if (!element) {
        return 0;
    }

    fontSet = (ModFontSetFn)GetAddressImmediate(&vaFontSet);
    fontPrintWindow = (ModFontPrintWindowFn)GetAddressImmediate(&vaFontPrintWindow);
    if (!fontSet || !fontPrintWindow || !modmenuUiFontWindowBegin()) {
        return 0;
    }

    font = fontSet(1);
    rowHeight = element->base.windowH / (MOD_OPTION_COUNT + 1);
    if (rowHeight < 1) {
        rowHeight = element->base.windowH;
    }
    listTop = (element->base.windowH - (rowHeight * MOD_OPTION_COUNT)) / 2;
    if (listTop < 0) {
        listTop = 0;
    }

    if ((UI_FRAME_COUNTER & 0x1f) == 1) {
        printf("\nmod-menu list custom pDraw elem=%08x win=%d,%d pos=%d,%d sel=%d row=%d top=%d hud=%08x hudOn=%08x digOn=%08x raw=%04x up=%02x down=%02x",
            (u32)element,
            element->base.windowW,
            element->base.windowH,
            element->base.screenX,
            element->base.screenY,
            modmenuSelected,
            rowHeight,
            listTop,
            P1_PAD->hudBits,
            P1_PAD->hudBitsOn,
            P1_PAD->digitalBitsOn,
            modmenuRawButtons(),
            P1_PAD->up_p,
            P1_PAD->down_p);
    }

    window.clipLeft = 1;
    window.clipRight = (s16)(element->base.windowW - 4);
    window.x = (s16)(element->base.windowW / 2);
    window.pad0 = 0;
    window.lineHeight = 0x0c;
    window.flags = 0x000b;
    window.pad1 = 0;
    window.scrollOffset = 0;

    for (i = 0; i < MOD_OPTION_COUNT; i++) {
        int selected = (i == modmenuSelected);
        const char *shadowLabel = modmenuOptions[i].label;
        const char *label = modmenuOptionDrawLabel(i, selected);
        u32 color = selected ? SelectedColor : NotSelectedColor;
        window.clipTop = (s16)(listTop + (i * rowHeight));
        window.clipBottom = (s16)(listTop + ((i + 1) * rowHeight));
        window.y = (s16)((window.clipTop + window.clipBottom) / 2);
        fontPrintWindow(&window, MOD_COLOR_SHADOW, shadowLabel, -1, font, (void *)0x001c35d0);
        window.y = (s16)(window.y - 1);
        fontPrintWindow(&window, color, label, -1, font, (void *)0x001c35d0);
    }

    modmenuFontWindowEnd();
    return UI_DRAW_RESULT_EXACT_SIZE;
}
static void modmenuSyncSelection(UiElementList_t *element)
{
    if (modmenuSelected < 0) {
        modmenuSelected = MOD_OPTION_COUNT - 1;
    }
    if (modmenuSelected >= MOD_OPTION_COUNT) {
        modmenuSelected = 0;
    }
    if (element) {
        element->selectedIndex = modmenuSelected;
    }
}

static void modmenuPlayMoveSound(UiElementList_t *element)
{
    Moby *sourceMoby = element ? element->base.pMoby : modmenuList.base.pMoby;

    if (!sourceMoby) {
        sourceMoby = uiMenuGetFrameMoby(3);
    }
    if (sourceMoby) {
        mobyPlaySoundByIndex(1, 0x11, sourceMoby);
    }
}

static void modmenuMoveSelection(UiElementList_t *element, int delta)
{
    int previous = modmenuSelected;

    modmenuSelected += delta;
    modmenuSyncSelection(element);
    if (modmenuSelected != previous) {
        modmenuPlayMoveSound(element);
    }
}

static int modmenuChooseSelection(void)
{
    UiMenu_t *nextMenu;

    modmenuSyncSelection(&modmenuList);
    if (modmenuSelected < 0 || modmenuSelected >= MOD_OPTION_COUNT) {
        return 0;
    }

    nextMenu = &modmenuSubmenus[modmenuSelected];
    printf("\nmod-menu choose sel=%d next=%08x optNext=%08x active=%08x change=%08x",
        modmenuSelected,
        (u32)nextMenu,
        (u32)modmenuOptions[modmenuSelected].pNextMenu,
        (u32)UI_ACTIVE_POINTER,
        (u32)UI_CHANGE_TO_POINTER);
    if (!nextMenu) {
        return 0;
    }

    UI_CHANGE_TO_POINTER = nextMenu;
    printf(" -> %08x", (u32)UI_CHANGE_TO_POINTER);
    return 1;
}
static void modmenuReturnToPauseMenu(void)
{
    if (modmenuMenu.pParent) {
        UI_CHANGE_TO_POINTER = modmenuMenu.pParent;
    }
}

static u64 modmenuUiFrameUpdate(UiElementBase_t *element)
{
    (void)element;

    if (modmenuHudPressed(P1_PAD->hudBitsOn, PAD_REVERSED_TRIANGLE)) {
        modmenuReturnToPauseMenu();
    }

    if (modmenuHudPressed(P1_PAD->hudBitsOn, PAD_REVERSED_START)) {
        return 1;
    }

    return 0;
}

static u64 modmenuUiUpdate(UiElementList_t *element)
{
    int pressed;
    int debugButtons;

    if (!element) {
        element = &modmenuList;
    }

    modmenuListUpdateHits++;
    modmenuSyncSelection(element);
    pressed = (element->modeFlags & 0x1) ? P1_PAD->digitalBitsOn : P1_PAD->hudBitsOn;
    debugButtons = PAD_REVERSED_UP | PAD_REVERSED_DOWN | PAD_REVERSED_CROSS | PAD_REVERSED_TRIANGLE | PAD_REVERSED_START;
    if (((UI_FRAME_COUNTER & 0x1f) == 1) || (pressed & debugButtons)) {
        printf("\nmod-menu select idx custom=%d list=%d elem=%d pressed=%08x hudOn=%08x digOn=%08x mode=%08x",
            modmenuSelected,
            modmenuList.selectedIndex,
            element->selectedIndex,
            pressed,
            P1_PAD->hudBitsOn,
            P1_PAD->digitalBitsOn,
            element->modeFlags);
    }

    if (pressed & PAD_REVERSED_START) {
        return 1;
    }
    if (pressed & PAD_REVERSED_TRIANGLE) {
        modmenuReturnToPauseMenu();
        return 0;
    }
    if (pressed & PAD_REVERSED_CROSS) {
        modmenuChooseSelection();
        return 0;
    }
    if (pressed & PAD_REVERSED_UP) {
        modmenuMoveSelection(element, -1);
        return 0;
    }
    if (pressed & PAD_REVERSED_DOWN) {
        modmenuMoveSelection(element, 1);
        return 0;
    }

    return 0;
}

static void modmenuPollActiveInput(void)
{
    int pressed = P1_PAD->hudBitsOn;
    int direction = modmenuReadDirection();

    if (pressed & PAD_REVERSED_TRIANGLE) {
        modmenuReturnToPauseMenu();
    }
    else if (direction != 0) {
        modmenuApplyDirection(&modmenuList, direction);
    }
    else if (pressed & PAD_REVERSED_CROSS) {
        modmenuChooseSelection();
    }
    else {
        modmenuApplyDirection(&modmenuList, 0);
    }
}
static void modmenuPlaySubmenuSound(UiElementBase_t *element, int soundIndex)
{
    Moby *sourceMoby = element ? element->pMoby : 0;

    if (!sourceMoby) {
        sourceMoby = uiMenuGetFrameMoby(3);
    }
    if (sourceMoby) {
        mobyPlaySoundByIndex(soundIndex, 0x11, sourceMoby);
    }
}

static int modmenuSubmenuOptionCount(int submenuIndex)
{
    if (submenuIndex == 0) {
        return MOD_SUBMENU_MAX_OPTION_COUNT;
    }
    return MOD_SUBMENU_DEFAULT_OPTION_COUNT;
}
static void modmenuSyncSubmenuSelection(int submenuIndex)
{
    int optionCount;

    if (submenuIndex < 0 || submenuIndex >= MOD_OPTION_COUNT) {
        return;
    }

    optionCount = modmenuSubmenuOptionCount(submenuIndex);
    if (optionCount < 1) {
        optionCount = 1;
    }
    if (modmenuSubmenuSelected[submenuIndex] < 0) {
        modmenuSubmenuSelected[submenuIndex] = optionCount - 1;
    }
    if (modmenuSubmenuSelected[submenuIndex] >= optionCount) {
        modmenuSubmenuSelected[submenuIndex] = 0;
    }
}

static void modmenuMoveSubmenuSelection(UiElementBase_t *element, int submenuIndex, int delta)
{
    int previous;

    if (submenuIndex < 0 || submenuIndex >= MOD_OPTION_COUNT) {
        return;
    }

    previous = modmenuSubmenuSelected[submenuIndex];
    modmenuSubmenuSelected[submenuIndex] += delta;
    modmenuSyncSubmenuSelection(submenuIndex);
    if (modmenuSubmenuSelected[submenuIndex] != previous) {
        modmenuPlaySubmenuSound(element, 1);
    }
}

static void modmenuToggleSubmenuOption(UiElementBase_t *element, int submenuIndex)
{
    int option;
    int value;
    const ModMenuSetting_t *setting;

    if (submenuIndex < 0 || submenuIndex >= MOD_OPTION_COUNT) {
        return;
    }

    modmenuSyncSubmenuSelection(submenuIndex);
    option = modmenuSubmenuSelected[submenuIndex];
    setting = &modmenuSubmenuSettings[option];
    value = modmenuSubmenuValues[submenuIndex][option];

    if (setting->type == MOD_SETTING_LIST) {
        value++;
        if (value >= setting->choiceCount) {
            value = 0;
        }
    }
    else if (setting->type == MOD_SETTING_NUMBER) {
        value++;
        if (value > setting->maxValue) {
            value = setting->minValue;
        }
    }
    else {
        value ^= 1;
    }

    modmenuSubmenuValues[submenuIndex][option] = value;
    modmenuPlaySubmenuSound(element, 0);
}

static const char *modmenuSubmenuOptionLabel(int option)
{
    if (option < 0 || option >= MOD_SUBMENU_MAX_OPTION_COUNT) {
        return "";
    }
    return modmenuSubmenuSettings[option].label ? modmenuSubmenuSettings[option].label : "";
}

static const char *modmenuSubmenuValueLabel(int submenuIndex, int option)
{
    const ModMenuSetting_t *setting;
    char *label;
    int index = 0;
    int value;

    if (submenuIndex < 0 || submenuIndex >= MOD_OPTION_COUNT || option < 0 || option >= modmenuSubmenuOptionCount(submenuIndex)) {
        return "";
    }

    setting = &modmenuSubmenuSettings[option];
    value = modmenuSubmenuValues[submenuIndex][option];
    if (setting->type == MOD_SETTING_TOGGLE_INVERTED) {
        return value ? "OFF" : "ON";
    }
    if (setting->type == MOD_SETTING_TOGGLE) {
        return value ? "ON" : "OFF";
    }
    if (setting->type == MOD_SETTING_LIST) {
        if (value < 0 || value >= setting->choiceCount || !setting->choices) {
            return "";
        }
        return setting->choices[value];
    }

    label = modmenuSubmenuValueLabels[option];
    modmenuAppendInt(label, &index, value);
    return label;
}

static const char *modmenuSubmenuDescription(int submenuIndex)
{
    int option;

    if (submenuIndex < 0 || submenuIndex >= MOD_OPTION_COUNT) {
        return "";
    }

    modmenuSyncSubmenuSelection(submenuIndex);
    option = modmenuSubmenuSelected[submenuIndex];
    if (option < 0 || option >= modmenuSubmenuOptionCount(submenuIndex)) {
        return "";
    }

    return modmenuSubmenuSettings[option].description ? modmenuSubmenuSettings[option].description : "";
}
static int modmenuFindSubmenuIndex(UiElementBase_t *element)
{
    int i;

    for (i = 0; i < MOD_OPTION_COUNT; i++) {
        if (element == (UiElementBase_t *)&modmenuSubmenuTitles[i] ||
            element == (UiElementBase_t *)&modmenuSubmenuBodies[i] ||
            element == (UiElementBase_t *)&modmenuSubmenuFooters[i] ||
            element == (UiElementBase_t *)&modmenuSubmenuDescriptions[i]) {
            return i;
        }
    }

    return 0;
}

static u64 modmenuSubmenuUpdate(UiElementBase_t *element)
{
    int index = modmenuFindSubmenuIndex(element);
    int pressed = P1_PAD->hudBitsOn;

    if (pressed & PAD_REVERSED_START) {
        return 1;
    }
    if (pressed & PAD_REVERSED_TRIANGLE) {
        modmenuSyncSelection(&modmenuList);
        modmenuMenu.pSelectedElement = (UiElementBase_t *)&modmenuList;
        modmenuForceCustomMenuFrames = 4;
        modmenuSetActiveFrameState();
        UI_CHANGE_TO_POINTER = &modmenuMenu;
        return 0;
    }
    if (pressed & PAD_REVERSED_UP) {
        modmenuMoveSubmenuSelection(element, index, -1);
        return 0;
    }
    if (pressed & PAD_REVERSED_DOWN) {
        modmenuMoveSubmenuSelection(element, index, 1);
        return 0;
    }
    if ((pressed & PAD_REVERSED_CROSS) || (pressed & PAD_REVERSED_LEFT) || (pressed & PAD_REVERSED_RIGHT)) {
        modmenuToggleSubmenuOption(element, index);
        return 0;
    }

    return 0;
}

static u64 modmenuSubmenuTitleDraw(UiElementText_t *element)
{
    ModFontSetFn fontSet;
    ModFontPrintWindowFn fontPrintWindow;
    ModFontWindow_t window;
    int index;
    int font;

    if (!element) {
        return 0;
    }

    index = modmenuFindSubmenuIndex((UiElementBase_t *)element);
    fontSet = (ModFontSetFn)GetAddressImmediate(&vaFontSet);
    fontPrintWindow = (ModFontPrintWindowFn)GetAddressImmediate(&vaFontPrintWindow);
    if (!fontSet || !fontPrintWindow || !modmenuUiFontWindowBegin()) {
        return 0;
    }

    font = fontSet(3);
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
    fontPrintWindow(&window, MOD_COLOR_SHADOW, modmenuOptions[index].label, -1, font, (void *)0x001c3d10);
    window.y = (s16)(window.y - 1);
    fontPrintWindow(&window, TitleColor, modmenuOptions[index].label, -1, font, (void *)0x001c3d10);
    modmenuFontWindowEnd();
    return UI_DRAW_RESULT_EXACT_SIZE;
}

static u64 modmenuSubmenuBodyDraw(UiElementText_t *element)
{
    ModFontSetFn fontSet;
    ModFontPrintWindowFn fontPrintWindow;
    ModFontWindow_t window;
    int index;
    int font;
    int rowHeight;
    int listTop;
    int valueLeft;
    int valueRight;
    int optionCount;
    int comfortableCount;
    int visibleCount;
    int firstOption;
    int rowTop;
    int rowBottom;
    int rowClipTop;
    int rowClipBottom;
    int drawRow;
    int option;

    if (!element) {
        return 0;
    }

    index = modmenuFindSubmenuIndex((UiElementBase_t *)element);
    if (index < 0 || index >= MOD_OPTION_COUNT) {
        index = 0;
    }
    modmenuSyncSubmenuSelection(index);

    fontSet = (ModFontSetFn)GetAddressImmediate(&vaFontSet);
    fontPrintWindow = (ModFontPrintWindowFn)GetAddressImmediate(&vaFontPrintWindow);
    if (!fontSet || !fontPrintWindow || !modmenuUiFontWindowBegin()) {
        return 0;
    }

    font = fontSet(1);
    optionCount = modmenuSubmenuOptionCount(index);
    if (optionCount < 1) {
        optionCount = 1;
    }

    comfortableCount = element->base.windowH / MOD_SUBMENU_MIN_ROW_HEIGHT;
    if (comfortableCount < 1) {
        comfortableCount = 1;
    }

    visibleCount = optionCount;
    firstOption = 0;
    if (visibleCount > comfortableCount) {
        visibleCount = comfortableCount;
        rowHeight = MOD_SUBMENU_MIN_ROW_HEIGHT;
        firstOption = modmenuSubmenuSelected[index] - (visibleCount / 2);
        if (firstOption < 0) {
            firstOption = 0;
        }
        if (firstOption > optionCount - visibleCount) {
            firstOption = optionCount - visibleCount;
        }
    }
    else {
        rowHeight = element->base.windowH / (visibleCount + 1);
    }
    if (rowHeight < 1) {
        rowHeight = element->base.windowH;
    }

    listTop = (element->base.windowH - (rowHeight * visibleCount)) / 2;
    if (listTop < 0) {
        listTop = 0;
    }
    valueLeft = (element->base.windowW * 2) / 3;
    valueRight = element->base.windowW - 4;
    if (valueLeft < 48) {
        valueLeft = 48;
    }

    window.pad0 = 0;
    window.lineHeight = 0x0c;
    window.pad1 = 0;
    window.scrollOffset = 0;

    for (drawRow = 0; drawRow < visibleCount; drawRow++) {
        const char *label;
        const char *value;
        u32 color;

        option = firstOption + drawRow;
        label = modmenuSubmenuOptionLabel(option);
        value = modmenuSubmenuValueLabel(index, option);
        color = (option == modmenuSubmenuSelected[index]) ? SelectedColor : NotSelectedColor;

        rowTop = listTop + (drawRow * rowHeight);
        rowBottom = listTop + ((drawRow + 1) * rowHeight);
        rowClipTop = rowTop + MOD_SUBMENU_ROW_BG_PADDING;
        rowClipBottom = rowBottom - MOD_SUBMENU_ROW_BG_PADDING;
        if (rowClipBottom <= rowClipTop) {
            rowClipTop = rowTop;
            rowClipBottom = rowBottom;
        }

        window.clipTop = (s16)rowClipTop;
        window.clipBottom = (s16)rowClipBottom;
        window.y = (s16)((rowClipTop + rowClipBottom) / 2);

        window.clipLeft = 8;
        window.clipRight = (s16)(valueLeft - 2);
        window.x = 14;
        window.flags = 0x0002;
        fontPrintWindow(&window, MOD_COLOR_SHADOW, label, -1, font, (void *)0x001c35d0);
        window.y = (s16)(window.y - 1);
        fontPrintWindow(&window, color, label, -1, font, (void *)0x001c35d0);

        window.y = (s16)(window.y + 1);
        window.clipLeft = (s16)valueLeft;
        window.clipRight = (s16)valueRight;
        window.x = (s16)((valueLeft + valueRight) / 2);
        window.flags = 0x000b;
        fontPrintWindow(&window, MOD_COLOR_SHADOW, value, -1, font, (void *)0x001c35d0);
        window.y = (s16)(window.y - 1);
        fontPrintWindow(&window, color, value, -1, font, (void *)0x001c35d0);
    }

    modmenuFontWindowEnd();
    return UI_DRAW_RESULT_EXACT_SIZE;
}
static u64 modmenuSubmenuDescriptionDraw(UiElementText_t *element)
{
    ModFontSetFn fontSet;
    ModFontPrintWindowFn fontPrintWindow;
    ModFontWindow_t window;
    const char *description;
    int index;
    int font;

    if (!element) {
        return 0;
    }

    index = modmenuFindSubmenuIndex((UiElementBase_t *)element);
    description = modmenuSubmenuDescription(index);
    fontSet = (ModFontSetFn)GetAddressImmediate(&vaFontSet);
    fontPrintWindow = (ModFontPrintWindowFn)GetAddressImmediate(&vaFontPrintWindow);
    if (!fontSet || !fontPrintWindow || !modmenuUiFontWindowBegin()) {
        return 0;
    }

    font = fontSet(1);
    window.clipTop = 6;
    window.clipBottom = (s16)(element->base.windowH - 6);
    window.clipLeft = 8;
    window.clipRight = (s16)(element->base.windowW - 6);
    window.x = 10;
    window.y = 8;
    window.pad0 = 0;
    window.lineHeight = 0x0c;
    window.flags = 0x0000;
    window.pad1 = 0;
    window.scrollOffset = 0;
    fontPrintWindow(&window, MOD_COLOR_SHADOW, description, -1, font, (void *)0x001c35d0);
    window.y = (s16)(window.y - 1);
    fontPrintWindow(&window, NotSelectedColor, description, -1, font, (void *)0x001c35d0);
    modmenuFontWindowEnd();
    return UI_DRAW_RESULT_EXACT_SIZE;
}
static u64 modmenuSubmenuFooterDraw(UiElementText_t *element)
{
    ModFontSetFn fontSet;
    ModFontPrintWindowFn fontPrintWindow;
    ModFontWindow_t window;
    int font;

    if (!element) {
        return 0;
    }

    fontSet = (ModFontSetFn)GetAddressImmediate(&vaFontSet);
    fontPrintWindow = (ModFontPrintWindowFn)GetAddressImmediate(&vaFontPrintWindow);
    if (!fontSet || !fontPrintWindow || !modmenuUiFontWindowBegin()) {
        return 0;
    }

    font = fontSet(3);
    window.clipTop = 4;
    window.clipBottom = (s16)(element->base.windowH - 4);
    window.clipLeft = 8;
    window.clipRight = (s16)(element->base.windowW - 4);
    window.x = 14;
    window.y = (s16)((element->base.windowH / 2) + 2);
    window.pad0 = 0;
    window.lineHeight = MOD_TITLE_FONT_LINE_HEIGHT;
    window.flags = 0x0002;
    window.pad1 = 0;
    window.scrollOffset = 0;
    fontPrintWindow(&window, MOD_COLOR_SHADOW, modmenuSubmenuFooterText, -1, font, (void *)0x001c3d10);
    window.y = (s16)(window.y - 1);
    fontPrintWindow(&window, TitleColor, modmenuSubmenuFooterText, -1, font, (void *)0x001c3d10);
    modmenuFontWindowEnd();
    return UI_DRAW_RESULT_EXACT_SIZE;
}

static void modmenuCreateSubmenus(void)
{
    VECTOR tl;
    VECTOR tr;
    VECTOR bl;
    VECTOR br;
    int i;

    for (i = 0; i < MOD_OPTION_COUNT; i++) {
        uiMenuInit(&modmenuSubmenus[i], &modmenuMenu, MOD_MENU_ID + 1 + i);
        modmenuCopyAnimIds(&modmenuSubmenus[i], modmenuHelpTopicAnimIds[1]);

        modmenuRectVectors(tl, tr, bl, br, 275.0f, 28.0f, 260.0f, 20.0f);
        uiCreateTitle(&modmenuSubmenuTitles[i], &modmenuSubmenuTitleFrames[i], tl, tr, bl, br, 0x4f5e);
        modmenuSubmenuTitles[i].base.pUpdate = 0;
        modmenuSubmenuTitles[i].base.pDraw = (void *)modmenuSubmenuTitleDraw;
        modmenuSubmenuTitles[i].base.renderFlags = 0;

        modmenuRectVectors(tl, tr, bl, br, 195.0f, 87.0f, 123.0f, 238.0f);
        uiCreateText(&modmenuSubmenuBodies[i], &modmenuSubmenuBodyFrames[i], tl, tr, bl, br, 0, 0);
        modmenuSubmenuBodies[i].base.pUpdate = (void *)modmenuSubmenuUpdate;
        modmenuSubmenuBodies[i].base.pDraw = (void *)modmenuSubmenuBodyDraw;
        modmenuSubmenuBodies[i].base.renderFlags = 0;

        modmenuRectVectors(tl, tr, bl, br, 195.0f, 343.0f, 123.0f, 70.0f);
        uiCreateText(&modmenuSubmenuFooters[i], &modmenuSubmenuFooterFrames[i], tl, tr, bl, br, 0, 0);
        modmenuSubmenuFooters[i].base.pUpdate = 0;
        modmenuSubmenuFooters[i].base.pDraw = (void *)modmenuSubmenuFooterDraw;
        modmenuSubmenuFooters[i].base.renderFlags = 0;

        modmenuRectVectors(tl, tr, bl, br, 20.0f, 343.0f, 167.0f, 70.0f);
        uiCreateText(&modmenuSubmenuDescriptions[i], &modmenuSubmenuDescriptionFrames[i], tl, tr, bl, br, 0, 0);
        modmenuSubmenuDescriptions[i].base.pUpdate = 0;
        modmenuSubmenuDescriptions[i].base.pDraw = (void *)modmenuSubmenuDescriptionDraw;
        modmenuSubmenuDescriptions[i].base.renderFlags = 0;

        uiMenuSetElement(&modmenuSubmenus[i], 0, (UiElementBase_t *)&modmenuSubmenuTitles[i]);
        uiMenuSetElement(&modmenuSubmenus[i], 3, (UiElementBase_t *)&modmenuSubmenuBodies[i]);
        uiMenuSetElement(&modmenuSubmenus[i], 4, (UiElementBase_t *)&modmenuSubmenuFooters[i]);
        uiMenuSetElement(&modmenuSubmenus[i], 5, (UiElementBase_t *)&modmenuSubmenuDescriptions[i]);
        modmenuSubmenuSelected[i] = 0;
        modmenuSubmenuValues[i][3] = modmenuSubmenuSettings[3].minValue;
        modmenuSubmenuValues[i][7] = modmenuSubmenuSettings[7].minValue;
        modmenuSubmenuValues[i][11] = modmenuSubmenuSettings[11].minValue;
        modmenuSubmenus[i].pSelectedElement = (UiElementBase_t *)&modmenuSubmenuBodies[i];
    }
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

static void modmenuUpdateSubmenuVisualProbe(int index)
{
    if (index < 0 || index >= MOD_OPTION_COUNT) {
        return;
    }

    modmenuSetProbeFrame(&modmenuSubmenuTitleFrames[index], 275.0f, 28.0f, 260.0f, 20.0f);
    modmenuSetProbeFrame(&modmenuSubmenuBodyFrames[index], 195.0f, 87.0f, 123.0f, 238.0f);
    modmenuSetProbeFrame(&modmenuSubmenuFooterFrames[index], 195.0f, 343.0f, 123.0f, 70.0f);
    modmenuSetProbeFrame(&modmenuSubmenuDescriptionFrames[index], 20.0f, 343.0f, 167.0f, 70.0f);
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

    modmenuUpdateVisualProbe();
    MOD_UI_FRAME_ENABLES[0] = 1;
    MOD_UI_FRAME_ENABLES[3] = 1;
    MOD_UI_FRAME_ENABLES[4] = 1;

    uiMenuSetElement(&modmenuMenu, 0, (UiElementBase_t *)&modmenuTitle);
    uiMenuSetElement(&modmenuMenu, 3, (UiElementBase_t *)&modmenuList);
    uiMenuSetElement(&modmenuMenu, 4, (UiElementBase_t *)&modmenuFooter);
    modmenuSyncSelection(&modmenuList);
    modmenuMenu.pSelectedElement = (UiElementBase_t *)&modmenuList;
    modmenuTitle.base.pUpdate = (void *)modmenuUiFrameUpdate;
    modmenuList.base.pUpdate = (void *)modmenuUiUpdate;
    modmenuFooter.base.pUpdate = 0;
    modmenuTitle.base.pDraw = (void *)modmenuUiTitleDraw;
    modmenuList.base.pDraw = (void *)modmenuUiListDraw;
    modmenuFooter.base.pDraw = (void *)modmenuUiFooterDraw;
    modmenuTitle.base.renderFlags = 0;
    modmenuList.base.renderFlags = 0;
    modmenuFooter.base.renderFlags = 0;
}

static void modmenuSetActiveSubmenuFrameState(int index)
{
    int i;

    if (index < 0 || index >= MOD_OPTION_COUNT) {
        return;
    }

    if (!modmenuFrameEnablesSaved) {
        for (i = 0; i < UI_MENU_MAX_ELEMENTS; i++) {
            modmenuSavedFrameEnables[i] = MOD_UI_FRAME_ENABLES[i];
        }
        modmenuFrameEnablesSaved = 1;
    }

    for (i = 0; i < UI_MENU_MAX_ELEMENTS; i++) {
        MOD_UI_FRAME_ENABLES[i] = 0;
        modmenuSubmenus[index].pElements[i] = 0;
    }

    modmenuUpdateSubmenuVisualProbe(index);
    MOD_UI_FRAME_ENABLES[0] = 1;
    MOD_UI_FRAME_ENABLES[3] = 1;
    MOD_UI_FRAME_ENABLES[4] = 1;
    MOD_UI_FRAME_ENABLES[5] = 1;

    uiMenuSetElement(&modmenuSubmenus[index], 0, (UiElementBase_t *)&modmenuSubmenuTitles[index]);
    uiMenuSetElement(&modmenuSubmenus[index], 3, (UiElementBase_t *)&modmenuSubmenuBodies[index]);
    uiMenuSetElement(&modmenuSubmenus[index], 4, (UiElementBase_t *)&modmenuSubmenuFooters[index]);
    uiMenuSetElement(&modmenuSubmenus[index], 5, (UiElementBase_t *)&modmenuSubmenuDescriptions[index]);
    modmenuSubmenus[index].pSelectedElement = (UiElementBase_t *)&modmenuSubmenuBodies[index];
    modmenuSubmenuTitles[index].base.pUpdate = 0;
    modmenuSubmenuBodies[index].base.pUpdate = (void *)modmenuSubmenuUpdate;
    modmenuSubmenuFooters[index].base.pUpdate = 0;
    modmenuSubmenuDescriptions[index].base.pUpdate = 0;
    modmenuSubmenuTitles[index].base.pDraw = (void *)modmenuSubmenuTitleDraw;
    modmenuSubmenuBodies[index].base.pDraw = (void *)modmenuSubmenuBodyDraw;
    modmenuSubmenuFooters[index].base.pDraw = (void *)modmenuSubmenuFooterDraw;
    modmenuSubmenuDescriptions[index].base.pDraw = (void *)modmenuSubmenuDescriptionDraw;
    modmenuSubmenuTitles[index].base.renderFlags = 0;
    modmenuSubmenuBodies[index].base.renderFlags = 0;
    modmenuSubmenuFooters[index].base.renderFlags = 0;
    modmenuSubmenuDescriptions[index].base.renderFlags = 0;
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

static int modmenuActiveSubmenuIndex(void)
{
    int i;

    for (i = 0; i < MOD_OPTION_COUNT; i++) {
        if (UI_ACTIVE_POINTER == &modmenuSubmenus[i]) {
            return i;
        }
    }

    return -1;
}

static void modmenuCreateTitle(void)
{
    VECTOR tl;
    VECTOR tr;
    VECTOR bl;
    VECTOR br;

    modmenuRectVectors(tl, tr, bl, br, 275.0f, 28.0f, 260.0f, 20.0f);
    uiCreateTitle(&modmenuTitle, &modmenuTitleFrame, tl, tr, bl, br, 0x4f5e);
    modmenuTitle.base.pUpdate = (void *)modmenuUiFrameUpdate;
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
    for (i = 0; i < MOD_OPTION_COUNT; i++) {
        modmenuEntries[i].labelStringId.flags = 0;
        modmenuEntries[i].labelStringId.id = 0;
        modmenuEntries[i].pNextMenu = &modmenuSubmenus[i];
        modmenuEntries[i].timeSelected = 0;
    }
    modmenuEntries[MOD_OPTION_ENTRY_COUNT - 1].labelStringId.flags = 0;
    modmenuEntries[MOD_OPTION_ENTRY_COUNT - 1].labelStringId.id = 0;
    modmenuEntries[MOD_OPTION_ENTRY_COUNT - 1].pNextMenu = 0;
    modmenuEntries[MOD_OPTION_ENTRY_COUNT - 1].timeSelected = 0;

    modmenuRectVectors(tl, tr, bl, br, 300.0f, 56.0f, 210.0f, 96.0f);
    modmenuSyncSelection(&modmenuList);
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
    modmenuCreateSubmenus();
    uiMenuCopyFrameAnims(&modmenuMenu, MOD_STOCK_HELP_MENU);
    for (i = 0; i < UI_MENU_MAX_ELEMENTS; i++) {
        uiMenuSetElement(&modmenuMenu, i, 0);
    }
    uiMenuSetElement(&modmenuMenu, 0, (UiElementBase_t *)&modmenuTitle);
    uiMenuSetElement(&modmenuMenu, 3, (UiElementBase_t *)&modmenuList);
    uiMenuSetElement(&modmenuMenu, 4, (UiElementBase_t *)&modmenuFooter);
    modmenuSyncSelection(&modmenuList);
    modmenuLastRawButtons = modmenuRawButtons();
    modmenuLastPressureButtons = modmenuPressureButtons();
    modmenuLastHudButtons = P1_PAD->hudBitsOn;
    modmenuDpadRepeatTimer = 0;
    modmenuLastDirection = 0;
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
    modmenuLastPressureButtons = modmenuPressureButtons();
    modmenuLastHudButtons = P1_PAD->hudBitsOn;
    modmenuDpadRepeatTimer = 0;
    modmenuLastDirection = 0;
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

    if (modmenuForceCustomMenuFrames > 0) {
        modmenuForceCustomMenuFrames--;
        modmenuSetActiveFrameState();
    }

    if (modmenuIsActiveMenu()) {
        modmenuSetActiveFrameState();
        return;
    }

    {
        int submenuIndex = modmenuActiveSubmenuIndex();
        if (submenuIndex >= 0) {
            modmenuSetActiveSubmenuFrameState(submenuIndex);
            return;
        }
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
