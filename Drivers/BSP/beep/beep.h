#ifndef __BEEP_H_
#define __BEEP_H_

/* 引脚，端口，时钟使能定义 */
#define BEEP_GPIO_PORT GPIOB
#define BEEP_GPIO_PIN GPIO_PIN_8
#define BEEP_GPIO_CLK_ENABLE()        \
    do                                \
    {                                 \
        __HAL_RCC_GPIOB_CLK_ENABLE(); \
    } while (0)

/*LED 操作函数：宏定义*/
#define BEEP(x)                                                                                                                                \
    do                                                                                                                                         \
    {                                                                                                                                          \
        x ? HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN, GPIO_PIN_SET) : HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN, GPIO_PIN_RESET); \
    } while (0)

#define BEEP_TOGGLE()                                      \
    do                                                     \
    {                                                      \
        HAL_GPIO_TogglePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN); \
    } while (0)

/*
 * @brief  初始化LED相关IO端口，并使能时钟
 * @param  无
 * @retval 无
 */
void beep_init(void);

#endif