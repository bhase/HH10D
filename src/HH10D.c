#include "HH10D.h"

static enum {
	Uninitialized,
	Ready,
} module_state;

void HH10D_Create(void)
{
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
	return HH10D_Ok;
}
