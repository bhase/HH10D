#ifndef D_HH10D_H
#define D_HH10D_H

/**********************************************************
 *
 * HH10D is responsible for ...
 *
 **********************************************************/

typedef enum {
	HH10D_Ok = 0,
	HH10D_Uninitialized,
} HH10D_Result;

void HH10D_Create(void);
void HH10D_Destroy(void);

HH10D_Result HH10D_Measure(void);

#endif  /* D_HH10D_H */
