extern "C"
{
#include "HH10D.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(HH10D)
{
	void setup()
	{
	}

	void teardown()
	{
		HH10D_Destroy();
	}
};

TEST(HH10D, Uninitialized)
{
	LONGS_EQUAL(HH10D_Uninitialized, HH10D_Measure());
}

