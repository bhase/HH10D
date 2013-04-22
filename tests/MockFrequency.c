#include "MockFrequency.h"

static uint8_t get_frequency_called = 0;
static uint16_t saved_frequency;

Frequency Timer_GetFrequency(void)
{
	get_frequency_called = 1;
	return saved_frequency;
}

void MockFreq_Setup(uint16_t frequency)
{
	get_frequency_called = 0;
	saved_frequency = frequency;
}

int MockFreq_IsGetFrequencyCalled(void)
{
	return get_frequency_called;
}
