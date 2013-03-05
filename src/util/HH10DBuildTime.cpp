#include "HH10DBuildTime.h"

HH10DBuildTime::HH10DBuildTime()
: dateTime(__DATE__ " " __TIME__)
{
}

HH10DBuildTime::~HH10DBuildTime()
{
}

const char* HH10DBuildTime::GetDateTime()
{
    return dateTime;
}

