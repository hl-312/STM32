#ifndef __LED_H_
#define __LED_H_
/* 引脚，端口，时钟使能定义 */
#define LED0_GPIO_PORT GPIOB
#define LED0_GPIO_PIN GPIO_PIN_5
#define LED0_GPIO_CLK_ENABLE()        \
    do                                \
    {                                 \
        __HAL_RCC_GPIOB_CLK_ENABLE(); \
    } while (0)

#define LED1_GPIO_PORT GPIOE
#define LED1_GPIO_PIN GPIO_PIN_5
#define LED1_GPIO_CLK_ENABLE()        \
    do                                \
    {                                 \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)

/*LED 操作函数：宏定义*/
#define LED0(x)                                                                                                                                \
    do                                                                                                                                         \
    {                                                                                                                                          \
        x ? HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_SET) : HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_RESET); \
    } while (0)

#define LED1(x)                                                                                                                                \
    do                                                                                                                                         \
    {                                                                                                                                          \
        x ? HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_SET) : HAL_GPIO_WritePin(LED1_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_RESET); \
    } while (0)

#define LED0_TOGGLE()                                     \
    do                                                    \
    {                                                     \
        HAL_GPIO_TogglePin(LED0_GPIO_PORT, LED0_GPIO_PIN); \
    } while (0)

#define LED1_TOGGLE()                                     \
    do                                                    \
    {                                                     \
        HAL_GPIO_TogglePin(LED1_GPIO_PORT, LED1_GPIO_PIN); \
    } while (0)

/*
 * @brief  初始化LED相关IO端口，并使能时钟
 * @param  无
 * @retval 无
 */
void led_init(void);

#endif