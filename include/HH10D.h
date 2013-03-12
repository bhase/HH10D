#ifndef D_HH10D_H
#define D_HH10D_H

#include <stdint.h>

/**********************************************************
 *
 * HH10D is responsible for ...
 *
 **********************************************************/

typedef enum {
	HH10D_Ok = 0,
	HH10D_Uninitialized,
} HH10D_Result;

typedef uint16_t Humidity;

void HH10D_Create(void);
void HH10D_Destroy(void);

HH10D_Result HH10D_Measure(void);
Humidity HH10D_GetHumidity(void);

#endif  /* D_HH10D_H */
