#ifndef __KEY_H_
#define __KEY_H_

#include "./SYSTEM/sys/sys.h"

/* 引脚，端口，时钟使能定义 */
#define KEY0_GPIO_PORT GPIOE
#define KEY0_GPIO_PIN GPIO_PIN_4
#define KEY0_GPIO_CLK_ENABLE()        \
    do                                \
    {                                 \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)

#define KEY1_GPIO_PORT GPIOE
#define KEY1_GPIO_PIN GPIO_PIN_3
#define KEY1_GPIO_CLK_ENABLE()        \
    do                                \
    {                                 \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)

#define WKUP_GPIO_PORT GPIOA
#define WKUP_GPIO_PIN GPIO_PIN_0
#define WKUP_GPIO_CLK_ENABLE()        \
    do                                \
    {                                 \
        __HAL_RCC_GPIOA_CLK_ENABLE(); \
    } while (0)

#define KEY0 HAL_GPIO_ReadPin(KEY0_GPIO_PORT, KEY0_GPIO_PIN)  /*读取 KEY0 引脚*/
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_PORT, KEY1_GPIO_PIN)  /*读取 KEY1 引脚*/
#define WK_UP HAL_GPIO_ReadPin(WKUP_GPIO_PORT, WKUP_GPIO_PIN) /*读取 WKUP 引脚*/

#define KEY0_PRES 1 /*KEY0 按下*/
#define KEY1_PRES 2 /*KEY1 按下*/
#define WKUP_PRES 3 /*WK_UP 按下*/

/**
 * @brief 按键初始化函数
 * @param 无
 * @retval 无
 */
void key_init(void);

/**
 * @brief 按键扫描函数
 * @note 该函数有响应优先级(同时按下多个按键): WK_UP > KEY1 > KEY0!!
 * @param mode:0 / 1, 具体含义如下:
 * @arg 0, 不支持连续按(当按键按下不放时, 只有第一次调用会返回键值,
 * 必须松开以后, 再次按下才会返回其他键值)
 * @arg 1, 支持连续按(当按键按下不放时, 每次调用该函数都会返回键值)
 * @retval 键值, 定义如下:
 * KEY0_PRES, 1, KEY0 按下
 * KEY1_PRES, 2, KEY1 按下
 * WKUP_PRES, 3, WKUP 按下
 */
uint8_t key_scan(uint8_t mode);

#endif