#include "CppUTest/TestHarness.h"
#include "HH10DBuildTime.h"

TEST_GROUP(HH10DBuildTime)
{
  HH10DBuildTime* projectBuildTime;

  void setup()
  {
    projectBuildTime = new HH10DBuildTime();
  }
  void teardown()
  {
    delete projectBuildTime;
  }
};

TEST(HH10DBuildTime, Create)
{
  CHECK(0 != projectBuildTime->GetDateTime());
}

