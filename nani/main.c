#include <tamtypes.h>
#include <librac1/game.h>
#include <librac1/utils.h>
#include <librac1/level.h>

int main(void)
{
	if (Level != LEVEL_ID_RILGAR)
		return 0;

	float maxVal = 50;

	// update max float
	POKE_LUI_ORI(0x0031686c, 0x00316870, maxVal, 1);
	POKE_LUI_ORI(0x003168e4, 0x003168e8, maxVal, 1);
	// nop reset address
	POKE_U32(0x0028cfe4, 0);

	return 0;
}
