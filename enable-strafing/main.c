#include <tamtypes.h>

#include <librac1/stdio.h>
#include <librac1/string.h>
#include <librac1/pad.h>
#include <librac1/interop.h>
#include <librac1/game.h>
#include <librac1/utils.h>
#include <librac1/player.h>
#include <librac1/math.h>

#define doBehavior_jal ((u32)0x00231dd0)
#define doBehavior_func ((u32)0x002370b8)

#define HERO_MOVE_X         0x00e0
#define HERO_MOVE_Z         0x00e4
#define HERO_MOVE_Y         0x00e8
#define HERO_FACE_YAW       0x0180
#define HERO_MOVE_SPEED     0x0190
#define HERO_INPUT_MAG      0x229c

#define CAMERA_YAW          (*(float*)0x00167258)
#define MOMENTUM_MULTIPLIER (*(float*)0x0015ed6c)

typedef float (*AngleSin_t)(float angle);
typedef float (*AngleCos_t)(float angle);

static AngleSin_t AngleSin = (AngleSin_t)0x002216f8;
static AngleCos_t AngleCos = (AngleCos_t)0x00221710;

VariableAddress_t vaUpdateAnalog = {
    .Veldin1 = 0x0020889c,
    .Novalis = 0x00229f9c,
    .Aridia = 0x002190f4,
    .Kerwan = 0x00201a2c,
    .Eudora = 0x001fbe7c,
    .Rilgar = 0x00236e04,
    .NebulaG34 = 0x002206fc,
    .Unbris = 0x00230704,
    .Batalia = 0x0021ac14,
    .Gaspar = 0x0022857c,
    .Orxon = 0x001fbf04,
    .Pokitaru = 0x002399f4,
    .Hoven = 0x0022b084,
    .OltanisOrbit = 0x00214384,
    .Oltanis = 0x0021b78c,
    .Quartu = 0x0020171c,
    .Kalebo = 0x002068fc,
    .VeldinOrbit = 0x002057f4,
    .Veldin2 = 0x00210d94,
};

static float clampf_local(float value, float min, float max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

static int is_strafe_state(int state)
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

static void face_camera(Player *player)
{
    *(float*)((u32)player + HERO_FACE_YAW) = CAMERA_YAW;
    player->rot[2] = CAMERA_YAW;
}

static void apply_camera_relative_strafe(Player *player, float input_mag)
{
    float move_yaw = *(float*)((u32)player + HERO_FACE_YAW);

    face_camera(player);

    if (P1_PAD->handsOffStick != 0 || input_mag < 0.2f)
        return;

    float speed = *(float*)((u32)player + HERO_MOVE_SPEED);

    if (speed < MOMENTUM_MULTIPLIER * 1.5f)
        speed = MOMENTUM_MULTIPLIER * 3.0f;

    speed *= clampf_local(input_mag, 0.35f, 1.0f);

    *(float*)((u32)player + HERO_MOVE_SPEED) = speed;

    *(float*)((u32)player + HERO_MOVE_X) = AngleSin(move_yaw) * speed;
    *(float*)((u32)player + HERO_MOVE_Z) = AngleCos(move_yaw) * speed;
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
    if (gameMode == 0) {
        HOOK_J(0x0023c44c, &strafe_hijack);
    }

    return 0;
}

