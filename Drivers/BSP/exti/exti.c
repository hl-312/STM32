#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
#include "./BSP/key/key.h"
#include "./BSP/beep/beep.h"
#include "./BSP/exti/exti.h"

void extix_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;
    gpio_init_struct.Pin = KEY0_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_IT_FALLING;
    gpio_init_struct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(KEY0_GPIO_PORT, &gpio_init_struct);

    gpio_init_struct.Pin = KEY1_GPIO_PIN;
    HAL_GPIO_Init(KEY1_GPIO_PORT, &gpio_init_struct);

    gpio_init_struct.Pin = WKUP_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_IT_RISING;
    gpio_init_struct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(WKUP_GPIO_PORT, &gpio_init_struct);

    HAL_NVIC_SetPriority(KEY0_INT_IRQn, 0, 2);
    HAL_NVIC_EnableIRQ(KEY0_INT_IRQn);

    HAL_NVIC_SetPriority(KEY1_INT_IRQn, 1, 2);
    HAL_NVIC_EnableIRQ(KEY1_INT_IRQn);

    HAL_NVIC_SetPriority(WKUP_INT_IRQn, 3, 2);
    HAL_NVIC_EnableIRQ(WKUP_INT_IRQn);
}

void KEY0_INT_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY0_INT_GPIO_PIN);
    __HAL_GPIO_EXTI_CLEAR_IT(KEY0_INT_GPIO_PIN);
}

void KEY1_INT_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY1_INT_GPIO_PIN);
    __HAL_GPIO_EXTI_CLEAR_IT(KEY1_INT_GPIO_PIN);
}

void WKUP_INT_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(WKUP_INT_GPIO_PIN);
    __HAL_GPIO_EXTI_CLEAR_IT(WKUP_INT_GPIO_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    delay_ms(20);
    switch (GPIO_Pin)
    {
    case KEY0_INT_GPIO_PIN:
        if (KEY0 == 0)
        {
            LED0_TOGGLE();
            LED1_TOGGLE();
        }
        break;
    case KEY1_INT_GPIO_PIN:
        if (KEY1 == 0)
        {
            LED0_TOGGLE();
        }
        break;
    case WKUP_INT_GPIO_PIN:
        if (WK_UP == 1)
        {
            BEEP_TOGGLE();
        }
        break;

    default:
        break;
    }
}
