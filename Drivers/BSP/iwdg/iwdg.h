#ifndef __IWDG_H_
#define __IWDG_H_

#include "./SYSTEM/sys/sys.h"

void iwdg_init(uint8_t prer, uint16_t rlr);
void iwdg_feed(void);

#endif