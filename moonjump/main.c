#include <tamtypes.h>

#include <librac1/stdio.h>
#include <librac1/string.h>
#include <librac1/pad.h>
#include <librac1/player.h>
#include <librac1/math3d.h>
#include <librac1/math.h>

int main(void)
{
	Player *p = (Player*)PLAYER_1_STRUCT;
	if (!p) return;

	if ((P1_PAD->btns & PAD_CROSS) == 0)
		*(float*)&p->pos[2] += 1.125;

	return 0;
}
