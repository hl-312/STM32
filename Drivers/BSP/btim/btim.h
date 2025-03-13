#ifndef __BTIM_H_
#define __BTIM_H_

#include "./SYSTEM/sys/sys.h"

extern TIM_HandleTypeDef g_btim_handle;

void btim_timx_int_init(uint16_t psc, uint16_t arr);

#endif