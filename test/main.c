#include <tamtypes.h>

#include <libgc/stdio.h>
#include <libgc/string.h>
#include <libgc/pad.h>
#include <libgc/player.h>

#ifdef RAC2_PAL
#define SCREEN_WIDTH			(512)
#define SCREEN_HEIGHT			(448)
#else
#define SCREEN_WIDTH			(512)
#define SCREEN_HEIGHT			(416)
#endif

int main(void)
{
	Player *p = (Player*)PLAYER_1_STRUCT;
	if ((*(u16*)((u32)P1_PAD + 0x1c) & PAD_CROSS) == 0) {
		p->pos[2] += 0.110f;
	}
	// ((void(*)(float, float, float, float, float, float, u64, u64, u64, char *, u64))0x002e8b60)(SCREEN_WIDTH * 0.3, SCREEN_HEIGHT * 0.3, 1.5, 1.5, 1, 1, 0x80ffffff, -1, 1, "Hello, I'm Text!", 0x80000000);

	return 0;
}
