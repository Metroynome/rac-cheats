#include <tamtypes.h>

#include <libgc/stdio.h>
#include <libgc/string.h>
#include <libgc/pad.h>
#include <libgc/player.h>

int main(void)
{
	Player *p = (Player*)PLAYER_1_STRUCT;
	if ((*(u16*)((u32)P1_PAD + 0x1c) & PAD_CROSS) == 0)
		p->pos[2] += 0.110f;

	return 0;
}
