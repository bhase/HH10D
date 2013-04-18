extern "C"
{
#include "HH10D.h"
#include "Timer.h"
#include "MockI2C.h"

static uint8_t get_frequency_called = 0;

Frequency Timer_GetFrequency(void)
{
	get_frequency_called = 1;
	return 0;
}
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(HH10D)
{
	void setup()
	{
		get_frequency_called = 0;
		HH10D_Create();
	}

	void teardown()
	{
		HH10D_Destroy();
	}
};


TEST(HH10D, Uninitialized)
{
	HH10D_Destroy();
	LONGS_EQUAL(HH10D_Uninitialized, HH10D_Measure());
}

TEST(HH10D, Initialized)
{
	LONGS_EQUAL(HH10D_Ok, HH10D_Measure());
}

TEST(HH10D, Datasheet_example)
{
	HH10D_Measure();
	LONGS_EQUAL(224, HH10D_GetHumidity());
}

TEST(HH10D, InitReadsParameter)
{
	const I2C_Address device_address = 0xA2;
	const uint8_t default_parameter[4] = {0x01, 0x63, 0x1D, 0x19};
	uint8_t buf[1] = { 0x0A };

	HH10D_Destroy();

	MockI2C_Create(3);
	MockI2C_Expect_I2C_WriteTo_and_check_buffer(device_address, 1, buf);
	MockI2C_Expect_I2C_ReadFrom_and_fill_buffer(device_address, 4, default_parameter);
	MockI2C_Expect_I2C_Run_and_return(I2C_Ok);

	HH10D_Create();

	MockI2C_CheckExpectations();
	MockI2C_Destroy();
}

TEST(HH10D, Measure_reads_frequency)
{
	HH10D_Measure();
	LONGS_EQUAL(1, get_frequency_called);
}
