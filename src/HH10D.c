#include "HH10D.h"
#include "I2C.h"
#include "Timer.h"

static enum {
	Uninitialized,
	Ready,
} module_state;

static Humidity humidity = 0;
static uint16_t offset = 0;
static uint16_t sens = 0;

void HH10D_Create(void)
{
	uint8_t buf[4];

	buf[0] = 0x0A;
	I2C_WriteTo(0xA2, 1, buf);
	I2C_ReadFrom(0xA3, 4, buf);
	I2C_Run();

	offset = (uint16_t)((buf[2] << 8) + buf[3]);
	sens = (uint16_t)(((buf[0] << 8) + buf[1]) * 10);

	module_state = Ready;
}

void HH10D_Destroy(void)
{
	module_state = Uninitialized;
}


HH10D_Result HH10D_Measure(void)
{
	uint16_t freq = 0;

	if (module_state == Uninitialized)
		return HH10D_Uninitialized;

	freq = Timer_GetFrequency();
	humidity = (Humidity)(((uint32_t)(offset - freq) * sens) / 4096);
	return HH10D_Ok;
}

Humidity HH10D_GetHumidity(void)
{
	return humidity;
}
