#include "HH10D.h"
#include "I2C.h"
#include "Timer.h"

static enum {
	Uninitialized,
	Ready,
} module_state;

void HH10D_Create(void)
{
	uint8_t buf[4];

	buf[0] = 0x0A;
	I2C_WriteTo(0xA2, 1, buf);
	I2C_ReadFrom(0xA3, 4, buf);
	I2C_Run();

	module_state = Ready;
}

void HH10D_Destroy(void)
{
	module_state = Uninitialized;
}


HH10D_Result HH10D_Measure(void)
{
	if (module_state == Uninitialized)
		return HH10D_Uninitialized;
	Timer_GetFrequency();
	return HH10D_Ok;
}

Humidity HH10D_GetHumidity(void)
{
	return 224;
}
