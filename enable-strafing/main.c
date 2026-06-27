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

int strafe_camera_active = 0;

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

VariableAddress_t vaCameraStrafeUpdate_Hook = {
#ifdef RAC1_PAL
    .Veldin1 = 0x002e960c,
    .Novalis = 0x0031476c,
    .Aridia = 0x002f7514,
    .Kerwan = 0x002e7efc,
    .Eudora = 0x002eced4,
    .Rilgar = 0x00324ca4,
    .NebulaG34 = 0x0031162c,
    .Umbris = 0x00324f3c,
    .Batalia = 0x00311164,
    .Gaspar = 0x003110bc,
    .Orxon = 0x002f19c4,
    .Pokitaru = 0x00324944,
    .Hoven = 0x00311794,
    .OltanisOrbit = 0x003139f4,
    .Oltanis = 0x00310114,
    .Quartu = 0x002f3834,
    .Kalebo = 0x002ef6fc,
    .VeldinOrbit = 0x002fbb94,
    .Veldin2 = 0x003021cc,
#elif RAC1_NTSCJ
    .Veldin1 = 0x002ebcd4,
    .Novalis = 0x00316dcc,
    .Aridia = 0x002f9bd4,
    .Kerwan = 0x002ea554,
    .Eudora = 0x002ef5cc,
    .Rilgar = 0x003273ac,
    .NebulaG34 = 0x00313c54,
    .Umbris = 0x003275a4,
    .Batalia = 0x003138ac,
    .Gaspar = 0x00313814,
    .Orxon = 0x002f401c,
    .Pokitaru = 0x0032703c,
    .Hoven = 0x00313e7c,
    .OltanisOrbit = 0x003161e4,
    .Oltanis = 0x003127a4,
    .Quartu = 0x002f5f14,
    .Kalebo = 0x002f1e9c,
    .VeldinOrbit = 0x002fe96c,
    .Veldin2 = 0x0030491c,
#else
    .Veldin1 = 0x002e9c64,
    .Novalis = 0x00314e3c,
    .Aridia = 0x002f7be4,
    .Kerwan = 0x002e85cc,
    .Eudora = 0x002ed5ac,
    .Rilgar = 0x003252e4,
    .NebulaG34 = 0x00311d04,
    .Umbris = 0x00325614,
    .Batalia = 0x00311834,
    .Gaspar = 0x00311794,
    .Orxon = 0x002f209c,
    .Pokitaru = 0x00325014,
    .Hoven = 0x00311e64,
    .OltanisOrbit = 0x003140cc,
    .Oltanis = 0x00310764,
    .Quartu = 0x002f3f04,
    .Kalebo = 0x002efdec,
    .VeldinOrbit = 0x002fc26c,
    .Veldin2 = 0x0030289c,
#endif
};

VariableAddress_t vaCameraStrafeUpdate_Func = {
#ifdef RAC1_PAL
    .Veldin1 = 0x002e59a8,
    .Novalis = 0x00310b08,
    .Aridia = 0x002f3830,
    .Kerwan = 0x002e4218,
    .Eudora = 0x002e9270,
    .Rilgar = 0x00321040,
    .NebulaG34 = 0x0030d948,
    .Umbris = 0x003212a8,
    .Batalia = 0x0030d4d0,
    .Gaspar = 0x0030d458,
    .Orxon = 0x002edd60,
    .Pokitaru = 0x00320ce0,
    .Hoven = 0x0030dab0,
    .OltanisOrbit = 0x0030fe28,
    .Oltanis = 0x0030c4b0,
    .Quartu = 0x002efb70,
    .Kalebo = 0x002ebb30,
    .VeldinOrbit = 0x002f7f30,
    .Veldin2 = 0x002fe538,
#elif RAC1_NTSCJ
    .Veldin1 = 0x002e8068,
    .Novalis = 0x00313160,
    .Aridia = 0x002f5ee8,
    .Kerwan = 0x002e6868,
    .Eudora = 0x002eb960,
    .Rilgar = 0x00323740,
    .NebulaG34 = 0x0030ff68,
    .Umbris = 0x00323908,
    .Batalia = 0x0030fc10,
    .Gaspar = 0x0030fba8,
    .Orxon = 0x002f03b0,
    .Pokitaru = 0x003233d0,
    .Hoven = 0x00310190,
    .OltanisOrbit = 0x00312610,
    .Oltanis = 0x0030eb38,
    .Quartu = 0x002f2248,
    .Kalebo = 0x002ee2c8,
    .VeldinOrbit = 0x002fad00,
    .Veldin2 = 0x00300c80,
#else
    .Veldin1 = 0x002e6000,
    .Novalis = 0x003111d8,
    .Aridia = 0x002f3f00,
    .Kerwan = 0x002e48e8,
    .Eudora = 0x002e9948,
    .Rilgar = 0x00321680,
    .NebulaG34 = 0x0030e020,
    .Umbris = 0x00321980,
    .Batalia = 0x0030dba0,
    .Gaspar = 0x0030db30,
    .Orxon = 0x002ee438,
    .Pokitaru = 0x003213b0,
    .Hoven = 0x0030e180,
    .OltanisOrbit = 0x00310500,
    .Oltanis = 0x0030cb00,
    .Quartu = 0x002f0240,
    .Kalebo = 0x002ec220,
    .VeldinOrbit = 0x002f8608,
    .Veldin2 = 0x002fec08,
#endif
};

void cameraStrafe_Logic(u32 camera)
{
    u32 camera_state;

    // call base
    ((void (*)(u32))GetAddress(&vaCameraStrafeUpdate_Func))(camera);
    if (!strafe_camera_active || *(s16*)(camera + 0x86) != 0)
        return;

    // force camera states to strafe.
    camera_state = *(u32*)(camera + 0x70);
    *(s16*)(camera_state + 0x10) = 0;
    *(u8*)(camera_state + 0x116) = 1;
    *(float*)(camera_state + 0x11c) = 0.5;
    *(float*)(camera_state + 0x120) = 0.2;
    *(s16*)(camera_state + 0x12) = 0;
    *(s16*)(camera_state + 0x14) = 0;
    *(s16*)(camera_state + 0x16) = 0;
}

int strafeStateCheck(int state)
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

void faceForward(Player *player)
{
	float *camRot = (float*)cameraGetRot();
    *(float*)((u32)player + HERO_FACE_YAW) = camRot[2];
    player->rot[2] = camRot[2];
}

void strafeApply(Player *player, float input_mag)
{
	float *camRot = (float*)cameraGetRot();
	float cam_yaw = camRot[2];

    faceForward(player);

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

void strafe(void)
{
    Player *player = (Player*)PLAYER_1_STRUCT;
    int old_state = player->state;

    strafe_camera_active = 0;

	if (player->weaponHeldId == 8 || player->invisible)
		return;

    if (strafeStateCheck(player->state) || strafeStateCheck(old_state)) {
        float input_mag = *(float*)((u32)player + HERO_INPUT_MAG);
        strafeApply(player, input_mag);
    }
}

void strafe_init(void)
{
    // update camera speeds (slow, medium, fast)
    register int gp asm("gp");
    float *camSpeed = (float*)((u32)gp - 0x49d8);
    camSpeed[0] *= 1;
    camSpeed[1] *= 3;
    camSpeed[2] *= 5;

    // disable Skidding
    // if InitBodyState function tries to set to HERO_STATE_SKID,
    // skip all states doings.
    POKE_U32(GetAddress(&vaInitBodyState_Skid), 0x100008e2);

    HOOK_JAL(GetAddress(&vaCameraStrafeUpdate_Hook), &cameraStrafe_Logic);
}

int main(void)
{
    u32 hook = GetAddress(&vaDoBehavior_Hook);
    if (gameMode == 0 && *(u32*)hook == 0x03e00008) {
        strafe_init();
        HOOK_J(hook, &strafe);
    }

    return 0;
}

