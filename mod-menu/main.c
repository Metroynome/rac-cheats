#include <tamtypes.h>
#include <librac1/pad.h>
#include <librac1/game.h>
#include <librac1/graphics.h>
#include <librac1/interop.h>
#include <librac1/stdio.h>
#include <librac1/ui.h>
#include <librac1/utils.h>

#define MOD_COLOR_SHADOW 0x80000000
#define MOD_STATE_MAGIC 0x4d4d3046
#define MOD_ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))
#define MOD_PTR_UNSET ((UiMenu_t *)0xffffffff)
#define MOD_MENU_ID UI_MENU_CUSTOM
#define MOD_BUILD_TAG "pause-render-hook-row-2026-08-21"
#define MOD_STOCK_HELP_MENU ((UiMenu_t *)0x001b3e18)
#define MOD_STOCK_PAUSE_MENU ((UiPauseMenu_t *)0x001c2a08)
#define MOD_UI_FRAME_ENABLES ((int *)0x001b2840)
#define MOD_TITLE_FONT_LINE_HEIGHT 0x10
#define MOD_DESC_FRAME_X 20
#define MOD_DESC_FRAME_Y 343
#define MOD_DESC_FRAME_W 167
#define MOD_DESC_FRAME_H 70

#define PAUSE_HOOK (0x0021ab64)

UiElementBase_t modMenu;

static UiMenuOption_t modMenuEntry;
static UiElementMenuOption_t modMenuElement;
static int modMenuSlotReady;
#define M1138_UPDATE_MENU_ITEM ((void (*)(Moby *))0x00309898)
#define MOBY_ANIM_SEQS(moby) ((MobySeq **)((moby)->pClass->seqs))

#define DRAW_FRAME_BORDER ((void (*)(Moby *))0x00297830)
static M1138_MenuItem_Pvar_t modMenuFrames[8];
static VECTOR modMenuPositions[8];
static VECTOR modMenuUnk40s[8];
static void patchPauseMenuSlot(UiPauseMenu_t *pause)
{
    if (!pause) {
        return;
    }
    if (pause->menu.menuId != UI_MENU_PAUSE_MAIN) {
        return;
    }

    if (modMenuSlotReady == 0) {
        modMenuEntry = pause->entries.goodies;
        modMenuElement = pause->optionElements[6];
        modMenuElement.pOption = &modMenuEntry;
        modMenuElement.pPreviousElement = &pause->optionElements[6];
        modMenuElement.pNextElement = 0;
        modMenuSlotReady = 1;
    }

    pause->optionElements[6].pNextElement = &modMenuElement;
    pause->menu.pElements[7] = (UiElementBase_t *)&modMenuElement;
    pause->menu.mobyAnimIds[7] = pause->menu.mobyAnimIds[6];
    MOD_UI_FRAME_ENABLES[7] = 1;
}

static int modMenuLayoutReady;

static float modAbs(float value)
{
    return value < 0.0f ? -value : value;
}

static void offsetMenuFrame(M1138_MenuItem_Pvar_t *frame, float dy, float dz, int screenDy)
{
    int i;

    for (i = 0; i < 4; i++) {
        frame->point[i][1] += dy;
        frame->point[i][2] += dz;
    }
    frame->y += screenDy;
}

static void offsetVector(VECTOR vector, float dy, float dz)
{
    vector[1] += dy;
    vector[2] += dz;
}

static void applyFrameMobyLayout(UiGlobals_t *ui)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (!ui->uiMobys[i]) {
            continue;
        }
        vector_copy(ui->uiMobys[i]->position, modMenuPositions[i]);
        vector_copy(ui->uiMobys[i]->unk_40, modMenuUnk40s[i]);
        ui->uiMobys[i]->modeBits &= ~2;
        ui->uiMobys[i]->pUpdate = M1138_UPDATE_MENU_ITEM;
        if (i == 7) {
            uiFrameMobyUseCustomPoints(ui->uiMobys[i], &modMenuFrames[i]);
        }
}
}

static void ensureModMenuFrameMoby(UiGlobals_t *ui, UiPauseMenu_t *pause)
{
    Moby *moby;
    Moby *source;
    M1138_MenuItem_Pvar_t *frame5;
    M1138_MenuItem_Pvar_t *frame6;
    float frameDy;
    float frameDz;
    float posDy;
    float posDz;
    int screenStep;
    int i;

    source = ui->uiMobys[6];
    moby = ui->uiMobys[7];
    if (!moby) {
        moby = mobySpawn(MOBY_ID_FRAME);
        if (!moby) {
            return;
        }
        ui->uiMobys[7] = moby;
    }

    if (source) {
        vector_copy(moby->position, source->position);
        vector_copy(moby->unk_40, source->unk_40);
    }
    else {
        moby->position[0] = 0.0f;
        moby->position[1] = 0.0f;
        moby->position[2] = 0.0f;
        moby->position[3] = 1.0f;
    }
    if (moby->pClass) {
        if (MOBY_ANIM_SEQS(moby)[pause->menu.mobyAnimIds[7]]) {
            mobySetAnimation(moby, pause->menu.mobyAnimIds[7], MOBY_ANIM_SEQS(moby)[pause->menu.mobyAnimIds[7]]->frameCnt - 1);
        }
        else {
            mobySetAnimation(moby, pause->menu.mobyAnimIds[7], 0);
        }
    }

    if (!modMenuLayoutReady) {
        for (i = 0; i < 7; i++) {
            if (!ui->uiMobys[i] || !ui->uiMobys[i]->pVar) {
                return;
            }
        }

        frame5 = (M1138_MenuItem_Pvar_t *)ui->uiMobys[5]->pVar;
        frame6 = (M1138_MenuItem_Pvar_t *)ui->uiMobys[6]->pVar;
        frameDy = frame6->point[0][1] - frame5->point[0][1];
        frameDz = frame6->point[0][2] - frame5->point[0][2];
        posDy = ui->uiMobys[6]->position[1] - ui->uiMobys[5]->position[1];
        posDz = ui->uiMobys[6]->position[2] - ui->uiMobys[5]->position[2];
        screenStep = frame6->y - frame5->y;
        if (screenStep <= 0) {
            screenStep = frame6->h + 6;
        }

        if (modAbs(frameDy) < 0.001f && modAbs(frameDz) < 0.001f) {
            frameDy = frame6->point[2][1] - frame6->point[0][1];
            frameDz = frame6->point[2][2] - frame6->point[0][2];
            if (modAbs(frameDy) < 0.001f && modAbs(frameDz) < 0.001f) {
                frameDy = frame6->worldHeight;
            }
        }
        if (modAbs(posDy) < 0.001f && modAbs(posDz) < 0.001f) {
            posDy = frameDy;
            posDz = frameDz;
        }

        for (i = 0; i < 7; i++) {
            modMenuFrames[i] = *(M1138_MenuItem_Pvar_t *)ui->uiMobys[i]->pVar;
            vector_copy(modMenuPositions[i], ui->uiMobys[i]->position);
            vector_copy(modMenuUnk40s[i], ui->uiMobys[i]->unk_40);
            offsetMenuFrame(&modMenuFrames[i], -(frameDy * 0.5f), -(frameDz * 0.5f), -(screenStep / 2));
            offsetVector(modMenuPositions[i], -(posDy * 0.5f), -(posDz * 0.5f));
        }
        modMenuFrames[7] = *frame6;
        vector_copy(modMenuPositions[7], ui->uiMobys[6]->position);
        vector_copy(modMenuUnk40s[7], ui->uiMobys[6]->unk_40);
        offsetMenuFrame(&modMenuFrames[7], frameDy * 0.5f, frameDz * 0.5f, screenStep / 2);
        offsetVector(modMenuPositions[7], posDy * 0.5f, posDz * 0.5f);
        modMenuLayoutReady = 1;
    }

    applyFrameMobyLayout(ui);
}

static void installModMenuSlot(UiGlobals_t *ui)
{
    UiPauseMenu_t *pause;
    int i;
    if (!ui->pActiveMenu) {
        return;
    }
    if (ui->pActiveMenu->menuId != UI_MENU_PAUSE_MAIN) {
        return;
    }

    pause = (UiPauseMenu_t *)ui->pActiveMenu;
    patchPauseMenuSlot(pause);
    ensureModMenuFrameMoby(ui, pause);
    modMenuElement.base.pMoby = ui->uiMobys[7];
    if (modMenuLayoutReady) {
        for (i = 0; i < 7; i++) {
            pause->optionElements[i].base.screenX = modMenuFrames[i].x;
            pause->optionElements[i].base.screenY = modMenuFrames[i].y;
            pause->optionElements[i].base.windowW = modMenuFrames[i].w;
            pause->optionElements[i].base.windowH = modMenuFrames[i].h;
        }
        modMenuElement.base.screenX = modMenuFrames[7].x;
        modMenuElement.base.screenY = modMenuFrames[7].y;
        modMenuElement.base.windowW = modMenuFrames[7].w;
        modMenuElement.base.windowH = modMenuFrames[7].h;
    }
}
void hookPause(int index)
{
    UiGlobals_t *ui = (UiGlobals_t*)UI_GLOBALS_ADDRESS;

    if (index == 0 && ui->pActiveMenu) {
        installModMenuSlot(ui);
    }

    ((void(*)(int))0x0028d080)(index);

    if (index == 0 && ui->pActiveMenu && ui->pActiveMenu->menuId == UI_MENU_PAUSE_MAIN && ui->uiMobys[7]) {
        DRAW_FRAME_BORDER(ui->uiMobys[7]);
    }
}

int main()
{
    u32 val = 0x0c0a3420;
    patchPauseMenuSlot(MOD_STOCK_PAUSE_MENU);
    if (*(u32*)PAUSE_HOOK == val) {
        HOOK_JAL(PAUSE_HOOK, &hookPause);
    }
    return 0;
}
