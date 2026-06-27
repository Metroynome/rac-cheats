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
    .Veldin1 = 0x00220ee4,
    .Novalis = 0x0023bfb4,
    .Aridia = 0x0022a230,
    .Kerwan = 0x00215150,
    .Eudora = 0x00214444,
    .Rilgar = 0x0024b99c,
    .NebulaG34 = 0x0023416c,
    .Umbris = 0x00248ccc,
    .Batalia = 0x0022f63c,
    .Gaspar = 0x00240b44,
    .Orxon = 0x002144cc,
    .Pokitaru = 0x0024c658,
    .Hoven = 0x0023ebd8,
    .OltanisOrbit = 0x0022c94c,
    .Oltanis = 0x0022eadc,
    .Quartu = 0x002156fc,
    .Kalebo = 0x0021cdcc,
    .VeldinOrbit = 0x0021d000,
    .Veldin2 = 0x00226898,
#elif RAC1_NTSCJ
    .Veldin1 = 0x00222a34,
    .Novalis = 0x0023dae4,
    .Aridia = 0x0022bd88,
    .Kerwan = 0x00216c80,
    .Eudora = 0x00216014,
    .Rilgar = 0x0024d4f4,
    .NebulaG34 = 0x00235c9c,
    .Umbris = 0x0024a81c,
    .Batalia = 0x0023116c,
    .Gaspar = 0x00242694,
    .Orxon = 0x0021601c,
    .Pokitaru = 0x0024e188,
    .Hoven = 0x00240788,
    .OltanisOrbit = 0x0022e49c,
    .Oltanis = 0x0023060c,
    .Quartu = 0x0021724c,
    .Kalebo = 0x0021e97c,
    .VeldinOrbit = 0x0021ec50,
    .Veldin2 = 0x002283e8,
#else
    .Veldin1 = 0x00221304,
    .Novalis = 0x0023c44c,
    .Aridia = 0x0022a6c8,
    .Kerwan = 0x002155e8,
    .Eudora = 0x002148e4,
    .Rilgar = 0x0024bdb4,
    .NebulaG34 = 0x0023460c,
    .Umbris = 0x0024916c,
    .Batalia = 0x0022fad4,
    .Gaspar = 0x00240fe4,
    .Orxon = 0x0021496c,
    .Pokitaru = 0x0024caf0,
    .Hoven = 0x0023f070,
    .OltanisOrbit = 0x0022cdec,
    .Oltanis = 0x0022eef4,
    .Quartu = 0x00215b94,
    .Kalebo = 0x0021d264,
    .VeldinOrbit = 0x0021d4a0,
    .Veldin2 = 0x00226d30,
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

	if (player->weaponHeldId == 8)
		return;

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

