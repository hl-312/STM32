#ifndef __USART_H_
#define __USART_H_
#include "./SYSTEM/sys/sys.h"
/*引脚定义：串口 1 的 GPIO*/
#define USART_TX_GPIO_PORT GPIOA
#define USART_TX_GPIO_PIN GPIO_PIN_9
#define USART_TX_GPIO_CLK_ENABLE()    \
    do                                \
    {                                 \
        __HAL_RCC_GPIOA_CLK_ENABLE(); \
    } while (0)

#define USART_RX_GPIO_PORT GPIOA
#define USART_RX_GPIO_PIN GPIO_PIN_10
#define USART_RX_GPIO_CLK_ENABLE()    \
    do                                \
    {                                 \
        __HAL_RCC_GPIOA_CLK_ENABLE(); \
    } while (0)

#define USART_UX USART1
#define USART_UX_IRQn USART1_IRQn
#define USART_UX_IRQHandler USART1_IRQHandler
#define USART_UX_CLK_ENABLE()          \
    do                                 \
    {                                  \
        __HAL_RCC_USART1_CLK_ENABLE(); \
    } while (0)

#define USART_REC_LEN 200
#define USART_EN_RX 1
#define RXBUFFERSIZE 1

/**
 * @brief 串口 X 初始化函数
 * @param baudrate: 波特率, 根据自己需要设置波特率值
 * @note 注意: 必须设置正确的时钟源, 否则串口波特率就会设置异常.
 * 这里的 USART 的时钟源在 sys_stm32_clock_init()函数中已经设置过了.
 * @retval 无
 */
void usart_init(uint32_t baudrate);

/**
 * @brief UART 底层初始化函数
 * @param huart: UART 句柄类型指针
 * @note 此函数会被 HAL_UART_Init()调用
 * 完成时钟使能，引脚配置，中断配置
 * @retval 无
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart);

#endif