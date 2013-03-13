extern "C"
{
#include "HH10D.h"
#include "MockI2C.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(HH10D)
{
	void setup()
	{
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
	uint8_t buf[4];

	HH10D_Destroy();

	MockI2C_Create(3);

	buf[0] = 0x0A;
	MockI2C_Expect_I2C_WriteTo_and_check_buffer(0xA2, 1, buf);

	buf[0] = 0x01;
	buf[1] = 0x63;
	buf[2] = 0x1D;
	buf[3] = 0x19;
	MockI2C_Expect_I2C_ReadFrom_and_fill_buffer(0xA3, 4, buf);

	MockI2C_Expect_I2C_Run_and_return(I2C_Ok);

	HH10D_Create();

	MockI2C_CheckExpectations();
	MockI2C_Destroy();
}
