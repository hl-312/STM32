#ifndef __EXTI_H_
#define __EXTI_H_

#include "./SYSTEM/sys/sys.h"

/*引脚 和 中断编号 & 中断服务函数 定义*/
#define KEY0_INT_GPIO_PORT GPIOE
#define KEY0_INT_GPIO_PIN GPIO_PIN_4
/*PE口时钟使能*/
#define KEY0_INT_GPIO_CLK_ENABLE()    \
    do                                \
    {                                 \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)
#define KEY0_INT_IRQn EXTI4_IRQn /*IRQn: Interrupt Request Number*/
#define KEY0_INT_IRQHandler EXTI4_IRQHandler

#define KEY1_INT_GPIO_PORT GPIOE
#define KEY1_INT_GPIO_PIN GPIO_PIN_3
/*PE口时钟使能*/
#define KEY1_INT_GPIO_CLK_ENABLE()    \
    do                                \
    {                                 \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)
#define KEY1_INT_IRQn EXTI3_IRQn
#define KEY1_INT_IRQHandler EXTI3_IRQHandler

#define WKUP_INT_GPIO_PORT GPIOA
#define WKUP_INT_GPIO_PIN GPIO_PIN_0
/*PA口时钟使能*/
#define WKUP_INT_GPIO_CLK_ENABLE()    \
    do                                \
    {                                 \
        __HAL_RCC_GPIOA_CLK_ENABLE(); \
    } while (0)
#define WKUP_INT_IRQn EXTI0_IRQn
#define WKUP_INT_IRQHandler EXTI0_IRQHandler

/// @brief 外部中断初始化程序
void extix_init(void);

/// @brief KEY0 外部中断服务程序
/// @param  无
void KEY0_INT_IRQHandler(void);
/// @brief KEY1 外部中断服务程序
/// @param  无
void KEY1_INT_IRQHandler(void);
/// @brief WKUP 外部中断服务程序
/// @param  无
void WKUP_INT_IRQHandler(void);

/// @brief 中断服务程序中要做的事情；在HAL库中，所有中断服务函数都是在调用此函数
/// @param GIPO_Pin: 中断引脚号
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif