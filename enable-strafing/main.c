#include <tamtypes.h>

#include <librac1/stdio.h>
#include <librac1/string.h>
#include <librac1/pad.h>
#include <librac1/interop.h>
#include <librac1/game.h>
#include <librac1/utils.h>
#include <librac1/player.h>

// VariableAddress_t vaUpdateAnalog = {
// 	.Veldin1 = 0x0020889c,
// 	.Novalis = 0x00229f9c,
// 	.Aridia = 0x002190f4,
// 	.Kerwan = 0x00201a2c,
// 	.Eudora = 0x001fbe7c,
// 	.Rilgar = 0x00236e04,
// 	.NebulaG34 = 0x002206fc,
// 	.Unbris = 0x00230704,
// 	.Batalia = 0x0021ac14,
// 	.Gaspar = 0x0022857c,
// 	.Orxon = 0x001fbf04,
// 	.Pokitaru = 0x002399f4,
// 	.Hoven = 0x0022b084,
// 	.OltanisOrbit = 0x00214384,
// 	.Oltanis = 0x0021b78c,
// 	.Quartu = 0x0020171c,
// 	.Kalebo = 0x002068fc,
// 	.VeldinOrbit = 0x002057f4,
// 	.Veldin2 = 0x00210d94,
// };


typedef void (*CaseHandler)(void);
static CaseHandler originalHandlers[6] = {0};

void strafeLogic(void)
{
    // figure out which state we're in to call the right original handler
    Player *player = (Player*)PLAYER_1_STRUCT;
    int state = player->state;

    float *playerX = (float*)((u32)player + 0x180);
    float *camY    = (float*)0x00167258;
    float f1       = *(float*)0x0015ed64;
    float momentum = *(float*)0x0015ed6c;

    float saved = *playerX;
    *playerX = *camY;
    ((void(*)(int, float, float, float))0x00232490)(0, f1 * 0.017f, f1 * 0.3f, momentum * 4.712389f);
    *playerX = saved;

    // call the original handler for this state
    if (state >= 0 && state < 6 && originalHandlers[state])
        originalHandlers[state]();
}

int main(void)
{
    u32 *jumpTable = (u32*)0x00208e80;

    // only patch once
    if (jumpTable[0] == (u32)&strafeLogic) return 0;

    int states[] = {0, 1, 2, 3, 4, 5};
    int i;
    for (i = 0; i < COUNT_OF(states); ++i) {
        originalHandlers[states[i]] = (CaseHandler)jumpTable[states[i]];
        POKE_U32(&jumpTable[states[i]], (u32)&strafeLogic);
    }

    return 0;
}