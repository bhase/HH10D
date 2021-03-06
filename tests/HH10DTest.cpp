extern "C"
{
#include "HH10D.h"
#include "MockI2C.h"
#include "MockFrequency.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(HH10D)
{
	static const uint16_t DEFAULT_OFFSET = 7449;
	static const uint16_t DEFAULT_SENS = 355;
	static const uint16_t DEFAULT_FREQUENCY = 7190;

	void setup()
	{
		MockFreq_Setup(DEFAULT_FREQUENCY);

		setupSensorParameter(DEFAULT_OFFSET, DEFAULT_SENS);

		HH10D_Create();
	}

	void teardown()
	{
		HH10D_Destroy();
		MockI2C_Destroy();
	}

	void setupSensorParameter(uint16_t offset, uint16_t sens)
	{
		const I2C_Address device_address = 0xA2;
		uint8_t default_parameter[4] = {(uint8_t)((sens >> 8) & 0xFF), (uint8_t)(sens & 0xFF),
			(uint8_t)((offset >> 8) & 0xFF), (uint8_t)(offset & 0xFF)};
		uint8_t buf[1] = { 0x0A };

		MockI2C_Create(3);
		MockI2C_Expect_I2C_WriteTo_and_check_buffer(device_address, 1, buf);
		MockI2C_Expect_I2C_ReadFrom_and_fill_buffer(device_address, 4, default_parameter);
		MockI2C_Expect_I2C_Run_and_return(I2C_Ok);
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

TEST(HH10D, Measure_reads_frequency)
{
	HH10D_Measure();
	LONGS_EQUAL(1, MockFreq_IsGetFrequencyCalled());
}

TEST(HH10D, Measure_evaluates_frequency)
{
	MockFreq_Setup(6400);
	HH10D_Measure();
	LONGS_EQUAL(909, HH10D_GetHumidity());
}
