#include <tamtypes.h>

#include <librac1/stdio.h>
#include <librac1/string.h>
#include <librac1/pad.h>
#include <librac1/interop.h>
#include <librac1/game.h>
#include <librac1/utils.h>
#include <librac1/player.h>
#include <librac1/math.h>
#include <librac1/camera.h>

#define HERO_MOVE_X (0x00e0)
#define HERO_MOVE_Z (0x00e4)
#define HERO_MOVE_Y (0x00e8)
#define HERO_FACE_YAW (0x0180)
#define HERO_MOVE_SPEED (0x0190)
#define HERO_INPUT_MAG (0x229c)
#define MOMENTUM_MULTIPLIER (0.0166667f) // novalis: (*(float*)0x0015ed6c)

VariableAddress_t vaDoBehavior_Hook = {
#ifdef RAC1_PAL
	.Veldin1 = 0x002a9094,
	.Novalis = 0x0023bfb4,
	.Aridia = 0x002a8f54,
	.Kerwan = 0x002994dc,
	.Eudora = 0x0029b21c,
	.Rilgar = 0x002d3ad4,
	.NebulaG34 = 0x002b62a4,
	.Umbris = 0x002d2124,
	.Batalia = 0x002b1afc,
	.Gaspar = 0x002c803c,
	.Orxon = 0x0029a8cc,
	.Pokitaru = 0x002cd26c,
	.Hoven = 0x002c12d4,
	.OltanisOrbit = 0x002bdab4,
	.Oltanis = 0x002b792c,
	.Quartu = 0x0029cd2c,
	.Kalebo = 0x002a371c,
	.VeldinOrbit = 0x002a4784,
	.Veldin2 = 0x00234e84,
#elif RAC1_NTSCJ
	.Veldin1 = 0x002ab544,
	.Novalis = 0x0023dae4,
	.Aridia = 0x002ab3c4,
	.Kerwan = 0x0029b91c,
	.Eudora = 0x0029d6fc,
	.Rilgar = 0x002d5f3c,
	.NebulaG34 = 0x002b86d4,
	.Umbris = 0x002d4584,
	.Batalia = 0x002b3f44,
	.Gaspar = 0x002ca4ec,
	.Orxon = 0x0029cd0c,
	.Pokitaru = 0x002cf6ac,
	.Hoven = 0x002c37a4,
	.OltanisOrbit = 0x002bffcc,
	.Oltanis = 0x002b9d7c,
	.Quartu = 0x0029f194,
	.Kalebo = 0x002a5bf4,
	.VeldinOrbit = 0x002a6cdc,
	.Veldin2 = 0x00236a9c,
#else
	.Veldin1 = 0x002a96ec,
	.Novalis = 0x0023c44c,
	.Aridia = 0x002a9624,
	.Kerwan = 0x00299bac,
	.Eudora = 0x0029b8f4,
	.Rilgar = 0x002d4144,
	.NebulaG34 = 0x002b697c,
	.Umbris = 0x002d27fc,
	.Batalia = 0x002b21cc,
	.Gaspar = 0x002c8714,
	.Orxon = 0x0029afa4,
	.Pokitaru = 0x002cd93c,
	.Hoven = 0x002c19a4,
	.OltanisOrbit = 0x002be18c,
	.Oltanis = 0x002b7f7c,
	.Quartu = 0x0029d3fc,
	.Kalebo = 0x002a3e0c,
	.VeldinOrbit = 0x002a4e5c,
	.Veldin2 = 0x0023531c,
#endif
};

int is_strafe_state(int state)
{
    return state == PLAYER_STATE_IDLE
        || state == PLAYER_STATE_LOOK
        || state == PLAYER_STATE_WALK
        || state == PLAYER_STATE_SKID
        || state == PLAYER_STATE_CROUCH
        || state == PLAYER_STATE_QUICK_TURN
        || state == PLAYER_STATE_TARGETING
        || state == PLAYER_STATE_GUN_WAITING;
}

void face_camera(Player *player)
{
	float *camRot = (float*)cameraGetRot();
    *(float*)((u32)player + HERO_FACE_YAW) = camRot[2];
    player->rot[2] = camRot[2];
}

void apply_camera_relative_strafe(Player *player, float input_mag)
{
	float *camRot = (float*)cameraGetRot();
	float cam_yaw = camRot[2];

    face_camera(player);

    if (P1_PAD->handsOffStick != 0 || input_mag < 0.2f)
        return;

    float speed = *(float*)((u32)player + HERO_MOVE_SPEED);
    if (speed < MOMENTUM_MULTIPLIER * 1.5f)
        speed = MOMENTUM_MULTIPLIER * 3.0f;

    speed *= clamp(input_mag, 0.35f, 1.0f);

    *(float*)((u32)player + HERO_MOVE_SPEED) = speed;

    float stick_x = player->sitckInput[0];
    float stick_y = -player->sitckInput[1];
    float stick_len = sqrtf(stick_x * stick_x + stick_y * stick_y);
    if (stick_len > 1.0f) {
        stick_x /= stick_len;
        stick_y /= stick_len;
    }
    float cam_sin = asinf(cam_yaw);
    float cam_cos = acosf(cam_yaw);

    *(float*)((u32)player + HERO_MOVE_X) = (cam_sin * stick_y + cam_cos * stick_x) * speed;
    *(float*)((u32)player + HERO_MOVE_Z) = (cam_cos * stick_y - cam_sin * stick_x) * speed;
    *(float*)((u32)player + HERO_MOVE_Y) = 0.0f;
}

void strafe_hijack(void)
{
    Player *player = (Player*)PLAYER_1_STRUCT;
    int old_state = player->state;

    if (is_strafe_state(player->state) || is_strafe_state(old_state)) {
        float input_mag = *(float*)((u32)player + HERO_INPUT_MAG);
        apply_camera_relative_strafe(player, input_mag);
    }
}

int main(void)
{
    u32 hook = GetAddress(&vaDoBehavior_Hook);
    if (gameMode == 0 && *(u32*)hook == 0x03e00008) {
        HOOK_J(hook, &strafe_hijack);
    }

    return 0;
}

