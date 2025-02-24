#ifndef __EXTI_H_
#define __EXTI_H_

#include "./SYSTEM/sys/sys.h"

/*���� �� �жϱ�� & �жϷ����� ����*/
#define KEY0_INT_GPIO_PORT GPIOE
#define KEY0_INT_GPIO_PIN GPIO_PIN_4
/*PE��ʱ��ʹ��*/
#define KEY0_INT_GPIO_CLK_ENABLE()    \
    do                                \
    {                                 \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)
#define KEY0_INT_IRQn EXTI4_IRQn /*IRQn: Interrupt Request Number*/
#define KEY0_INT_IRQHandler EXTI4_IRQHandler

#define KEY1_INT_GPIO_PORT GPIOE
#define KEY1_INT_GPIO_PIN GPIO_PIN_3
/*PE��ʱ��ʹ��*/
#define KEY1_INT_GPIO_CLK_ENABLE()    \
    do                                \
    {                                 \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)
#define KEY1_INT_IRQn EXTI3_IRQn
#define KEY1_INT_IRQHandler EXTI3_IRQHandler

#define WKUP_INT_GPIO_PORT GPIOA
#define WKUP_INT_GPIO_PIN GPIO_PIN_0
/*PA��ʱ��ʹ��*/
#define WKUP_INT_GPIO_CLK_ENABLE()    \
    do                                \
    {                                 \
        __HAL_RCC_GPIOA_CLK_ENABLE(); \
    } while (0)
#define WKUP_INT_IRQn EXTI0_IRQn
#define WKUP_INT_IRQHandler EXTI0_IRQHandler

/// @brief �ⲿ�жϳ�ʼ������
void extix_init(void);

#endif