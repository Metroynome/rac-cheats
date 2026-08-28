#include <tamtypes.h>
#include <librac1/game.h>
#include <librac1/interop.h>
#include <librac1/moby.h>
#include <librac1/ui.h>
#include <librac1/math.h>
#include <librac1/utils.h>

#define PAUSE_RENDER_HOOK 0x0021ab64
#define UI_RENDER_MENU ((void (*)(int))0x0028d080)
#define M1138_UPDATE_MENU_ITEM ((void (*)(Moby *))0x00309898)

#define PAUSE_ROW_COUNT 7
#define MOD_PAUSE_ROW_COUNT 8
#define MOD_PAUSE_ROW_SLOT 7

static UiMenuOption_t modPauseEntry;
static UiElementMenuOption_t modPauseElement;
static M1138_MenuItem_Pvar_t modPauseFrames[MOD_PAUSE_ROW_COUNT];
static VECTOR modPausePositions[MOD_PAUSE_ROW_COUNT];
static VECTOR modPauseUnk40s[MOD_PAUSE_ROW_COUNT];
static int modPauseSlotReady;
static int modPauseLayoutReady;

static int isPauseMainMenu(UiMenu_t *menu)
{
    return menu && menu->menuId == UI_MENU_PAUSE_MAIN;
}

/* RAC1 VECTOR order is x,z,y: index 1 is Z, index 2 is Y. */
static void offsetFrame(M1138_MenuItem_Pvar_t *frame, float z, float y, int screenDy)
{
    int i;

    for (i = 0; i < 4; i++) {
        frame->point[i][1] += z;
        frame->point[i][2] += y;
    }
    frame->y += screenDy;
}

static void offsetVector(VECTOR vector, float z, float y)
{
    vector[1] += z;
    vector[2] += y;
}

static void addPauseMenuRow(UiStaticData_t *ui, UiPauseMenu_t *pause)
{
    if (!ui || !pause) {
        return;
    }
    if (!isPauseMainMenu(&pause->menu)) {
        return;
    }

    if (!modPauseSlotReady) {
        modPauseEntry = pause->entries.goodies;
        modPauseElement = pause->optionElements[PAUSE_ROW_COUNT - 1];
        modPauseElement.pOption = &modPauseEntry;
        modPauseElement.pPreviousElement = &pause->optionElements[PAUSE_ROW_COUNT - 1];
        modPauseElement.pNextElement = 0;
        modPauseSlotReady = 1;
    }

    pause->optionElements[PAUSE_ROW_COUNT - 1].pNextElement = &modPauseElement;
    pause->menu.pElements[MOD_PAUSE_ROW_SLOT] = (UiElementBase_t *)&modPauseElement;
    pause->menu.mobyAnimIds[MOD_PAUSE_ROW_SLOT] = pause->menu.mobyAnimIds[PAUSE_ROW_COUNT - 1];
    ui->frameEnables[MOD_PAUSE_ROW_SLOT] = 1;
}

static int cachePauseMenuLayout(UiGlobals_t *ui)
{
    M1138_MenuItem_Pvar_t *rowBeforeLast;
    M1138_MenuItem_Pvar_t *lastRow;
    float frameZ;
    float frameY;
    float posZ;
    float posY;
    int screenStep;
    int i;

    if (modPauseLayoutReady) {
        return 1;
    }

    for (i = 0; i < PAUSE_ROW_COUNT; i++) {
        if (!ui->uiMobys[i] || !ui->uiMobys[i]->pVar) {
            return 0;
        }
    }

    rowBeforeLast = (M1138_MenuItem_Pvar_t *)ui->uiMobys[PAUSE_ROW_COUNT - 2]->pVar;
    lastRow = (M1138_MenuItem_Pvar_t *)ui->uiMobys[PAUSE_ROW_COUNT - 1]->pVar;

    frameZ = lastRow->point[0][1] - rowBeforeLast->point[0][1];
    frameY = lastRow->point[0][2] - rowBeforeLast->point[0][2];
    posZ = ui->uiMobys[PAUSE_ROW_COUNT - 1]->position[1] - ui->uiMobys[PAUSE_ROW_COUNT - 2]->position[1];
    posY = ui->uiMobys[PAUSE_ROW_COUNT - 1]->position[2] - ui->uiMobys[PAUSE_ROW_COUNT - 2]->position[2];
    screenStep = lastRow->y - rowBeforeLast->y;
    if (screenStep <= 0) {
        screenStep = lastRow->h + 6;
    }

    if (fabsf(frameZ) < 0.001f && fabsf(frameY) < 0.001f) {
        frameZ = lastRow->point[2][1] - lastRow->point[0][1];
        frameY = lastRow->point[2][2] - lastRow->point[0][2];
        if (fabsf(frameZ) < 0.001f && fabsf(frameY) < 0.001f) {
            frameZ = lastRow->worldHeight;
        }
    }
    if (fabsf(posZ) < 0.001f && fabsf(posY) < 0.001f) {
        posZ = frameZ;
        posY = frameY;
    }

    for (i = 0; i < PAUSE_ROW_COUNT; i++) {
        modPauseFrames[i] = *(M1138_MenuItem_Pvar_t *)ui->uiMobys[i]->pVar;
        vector_copy(modPausePositions[i], ui->uiMobys[i]->position);
        vector_copy(modPauseUnk40s[i], ui->uiMobys[i]->unk_40);
        offsetFrame(&modPauseFrames[i], -(frameZ * 0.5f), -(frameY * 0.5f), -(screenStep / 2));
        offsetVector(modPausePositions[i], -(posZ * 0.5f), -(posY * 0.5f));
    }

    modPauseFrames[MOD_PAUSE_ROW_SLOT] = *lastRow;
    vector_copy(modPausePositions[MOD_PAUSE_ROW_SLOT], ui->uiMobys[PAUSE_ROW_COUNT - 1]->position);
    vector_copy(modPauseUnk40s[MOD_PAUSE_ROW_SLOT], ui->uiMobys[PAUSE_ROW_COUNT - 1]->unk_40);
    offsetFrame(&modPauseFrames[MOD_PAUSE_ROW_SLOT], frameZ * 0.5f, frameY * 0.5f, screenStep / 2);
    offsetVector(modPausePositions[MOD_PAUSE_ROW_SLOT], posZ * 0.5f, posY * 0.5f);

    modPauseLayoutReady = 1;
    return 1;
}

static void applyPauseMenuLayout(UiGlobals_t *ui, UiPauseMenu_t *pause)
{
    int i;

    if (!cachePauseMenuLayout(ui)) {
        return;
    }

    for (i = 0; i < MOD_PAUSE_ROW_COUNT; i++) {
        if (!ui->uiMobys[i]) {
            continue;
        }
        vector_copy(ui->uiMobys[i]->position, modPausePositions[i]);
        vector_copy(ui->uiMobys[i]->unk_40, modPauseUnk40s[i]);
        ui->uiMobys[i]->modeBits &= ~2;
        ui->uiMobys[i]->pUpdate = M1138_UPDATE_MENU_ITEM;
        uiFrameMobyUseCustomPoints(ui->uiMobys[i], &modPauseFrames[i]);
    }

    for (i = 0; i < PAUSE_ROW_COUNT; i++) {
        pause->optionElements[i].base.screenX = modPauseFrames[i].x;
        pause->optionElements[i].base.screenY = modPauseFrames[i].y;
        pause->optionElements[i].base.windowW = modPauseFrames[i].w;
        pause->optionElements[i].base.windowH = modPauseFrames[i].h;
    }

    modPauseElement.base.pMoby = ui->uiMobys[MOD_PAUSE_ROW_SLOT];
    modPauseElement.base.screenX = modPauseFrames[MOD_PAUSE_ROW_SLOT].x;
    modPauseElement.base.screenY = modPauseFrames[MOD_PAUSE_ROW_SLOT].y;
    modPauseElement.base.windowW = modPauseFrames[MOD_PAUSE_ROW_SLOT].w;
    modPauseElement.base.windowH = modPauseFrames[MOD_PAUSE_ROW_SLOT].h;
}

static void updatePauseMenu(UiGlobals_t *ui)
{
    UiPauseMenu_t *pause;

    if (!isPauseMainMenu(ui->pActiveMenu)) {
        return;
    }

    pause = (UiPauseMenu_t *)ui->pActiveMenu;
    addPauseMenuRow(&UI_STATIC_DATA, pause);
    applyPauseMenuLayout(ui, pause);
}

void hookPauseRender(int index)
{
    if (index == 0) {
        updatePauseMenu((UiGlobals_t *)UI_GLOBALS_ADDRESS);
    }

    UI_RENDER_MENU(index);
}

int main(void)
{
    UiStaticData_t *ui = &UI_STATIC_DATA;

    addPauseMenuRow(ui, &ui->menus.pauseMain);

    if (*(u32 *)PAUSE_RENDER_HOOK == 0x0c0a3420) {
        HOOK_JAL(PAUSE_RENDER_HOOK, &hookPauseRender);
    }

    return 0;
}
