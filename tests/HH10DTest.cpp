extern "C"
{
#include "HH10D.h"
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
