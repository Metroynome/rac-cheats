#include <tamtypes.h>

#include <librac1/stdio.h>
#include <librac1/string.h>
#include <librac1/pad.h>
#include <librac1/interop.h>
#include <librac1/game.h>
#include <librac1/utils.h>
#include <librac1/player.h>

#define doBehavior_jal ((u32)0x00231dd0)
#define doBehavior_func ((u32)0x002370b8)

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

void strafe_jr(u32 jumpTo)
{
    return;
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
}

void strafe_hijack(void)
{
    Player *player = (Player*)PLAYER_1_STRUCT;
    int state = player->state;
    if (state == 0 || state == 1 || state == 2 || state == 4 || state == 5) {
        float *playerX = (float*)((u32)player + 0x180);
        float *camY    = (float*)0x00167258;
        float f1       = *(float*)0x0015ed64;
        float momentum = *(float*)0x0015ed6c;

        float saved = *playerX;
        *playerX = *camY;
        ((void(*)(int, float, float, float))0x00232490)(0, f1 * 0.017f, f1 * 0.3f, momentum * 4.712389f);
        *playerX = saved;
    } else {
        ((void(*)(void))doBehavior_func)();
    }
}

int main(void)
{
    u32 *jumpTable = (u32*)0x00208e80;
    u32 jump_jr = 0x00237134;


    Hero *hero = (Hero*)PLAYER_1_STRUCT;
    // overwrite jump_jr
    // if (*(u32*)jump_jr != 0 && *(u32*)jump_jr != ADDR2JAL(&strafe_jr)) {
    //     HOOK_J(jump_jr, &strafe_jr);
    // }

    // do behavior hhijack
    if (*(u32*)doBehavior_jal != 0 && *(u32*)doBehavior_jal == 0x0c08dc2e) {
        HOOK_JAL(doBehavior_jal, &strafe_hijack);
    }

    return 0;
}