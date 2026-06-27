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

#if !defined(RAC1_PAL) && !defined(RAC1_NTSCJ)
#define CAMERA_STRAFE_UPDATE_CALL (0x00314e3c)
#define CAMERA_STRAFE_UPDATE_FUNC (0x003111d8)
#else
#define CAMERA_STRAFE_UPDATE_CALL (0)
#define CAMERA_STRAFE_UPDATE_FUNC (0)
#endif

int strafe_camera_active = 0;

void apply_native_strafe_camera_mode(u32 camera)
{
    if (*(s16*)(camera + 0x86) != 0)
        return;

    u32 camera_state = *(u32*)(camera + 0x70);
    if (camera_state == 0)
        return;

    *(s16*)(camera_state + 0x10) = 0;
    *(u8*)(camera_state + 0x116) = 1;
    *(float*)(camera_state + 0x11c) = 0.04f;
    *(float*)(camera_state + 0x120) = 0.2f;
    *(s16*)(camera_state + 0x12) = 0;
    *(s16*)(camera_state + 0x14) = 0;
    *(s16*)(camera_state + 0x16) = 0;
}

void camera_strafe_update_wrapper(u32 camera)
{
    ((void (*)(u32))CAMERA_STRAFE_UPDATE_FUNC)(camera);
    if (strafe_camera_active)
        apply_native_strafe_camera_mode(camera);
}

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

VariableAddress_t vaInitBodyState_Skid = {
#ifdef RAC1_PAL
    .Veldin1 = 0x002232fc,
    .Novalis = 0x0023dc34,
    .Aridia = 0x0022bbe8,
    .Kerwan = 0x002172e4,
    .Eudora = 0x0021685c,
    .Rilgar = 0x0024e1bc,
    .NebulaG34 = 0x00235ae0,
    .Umbris = 0x0024b0e4,
    .Batalia = 0x00231860,
    .Gaspar = 0x00242f5c,
    .Orxon = 0x002168e4,
    .Pokitaru = 0x0024e81c,
    .Hoven = 0x00240ee8,
    .OltanisOrbit = 0x0022ed64,
    .Oltanis = 0x00230558,
    .Quartu = 0x002177d4,
    .Kalebo = 0x0021f63c,
    .VeldinOrbit = 0x0021f3b4,
    .Veldin2 = 0x00228a88,
#elif RAC1_NTSCJ
    .Veldin1 = 0x00224e50,
    .Novalis = 0x0023f778,
    .Aridia = 0x0022d754,
    .Kerwan = 0x00218e28,
    .Eudora = 0x00218430,
    .Rilgar = 0x0024fd18,
    .NebulaG34 = 0x00237614,
    .Umbris = 0x0024cc38,
    .Batalia = 0x002333a4,
    .Gaspar = 0x00244ab0,
    .Orxon = 0x00218438,
    .Pokitaru = 0x00250360,
    .Hoven = 0x00242aac,
    .OltanisOrbit = 0x002308b8,
    .Oltanis = 0x0023209c,
    .Quartu = 0x00219338,
    .Kalebo = 0x00221200,
    .VeldinOrbit = 0x00221008,
    .Veldin2 = 0x0022a5ec,
#else
    .Veldin1 = 0x0022371c,
    .Novalis = 0x0023e0cc,
    .Aridia = 0x0022c080,
    .Kerwan = 0x0021777c,
    .Eudora = 0x00216cfc,
    .Rilgar = 0x0024e5d4,
    .NebulaG34 = 0x00235f80,
    .Umbris = 0x0024b584,
    .Batalia = 0x00231cf8,
    .Gaspar = 0x002433fc,
    .Orxon = 0x00216d84,
    .Pokitaru = 0x0024ecb4,
    .Hoven = 0x00241380,
    .OltanisOrbit = 0x0022f204,
    .Oltanis = 0x00230970,
    .Quartu = 0x00217c6c,
    .Kalebo = 0x0021fad4,
    .VeldinOrbit = 0x0021f854,
    .Veldin2 = 0x00228f20,
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

    if (P1_PAD->handsOffStick != 0 || input_mag < 0.2f) {
        strafe_camera_active = 0;
        return;
    }

    strafe_camera_active = 1;

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
    // saving Y axis causes floating bug.
    // *(float*)((u32)player + HERO_MOVE_Y) = 0.0f;
}

void strafe_hijack(void)
{
    Player *player = (Player*)PLAYER_1_STRUCT;
    int old_state = player->state;

    strafe_camera_active = 0;

	if (player->weaponHeldId == 8)
		return;

    if (is_strafe_state(player->state) || is_strafe_state(old_state)) {
        float input_mag = *(float*)((u32)player + HERO_INPUT_MAG);
        apply_camera_relative_strafe(player, input_mag);
    }
}

void strafe_init(void)
{
    // disable Skidding
    // if InitBodyState function tries to set to HERO_STATE_SKID,
    // skip all states doings.
    POKE_U32(GetAddress(&vaInitBodyState_Skid), 0x100008e2);

    if (CAMERA_STRAFE_UPDATE_CALL != 0 && CAMERA_STRAFE_UPDATE_FUNC != 0)
        HOOK_JAL(CAMERA_STRAFE_UPDATE_CALL, &camera_strafe_update_wrapper);
}

int main(void)
{
    u32 hook = GetAddress(&vaDoBehavior_Hook);
    if (gameMode == 0 && *(u32*)hook == 0x03e00008) {
        strafe_init();
        HOOK_J(hook, &strafe_hijack);
    }

    return 0;
}

