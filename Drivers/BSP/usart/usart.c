#include "./BSP/usart/usart.h"

UART_HandleTypeDef uartx_handle;
extern uint8_t g_usart_rx_buf[USART_REC_LEN];
extern uint16_t g_usart_rx_sta;

void usart_init(uint32_t baudrate)
{
    uartx_handle.Instance = USART_UX;
    uartx_handle.Init.BaudRate = baudrate;
    uartx_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uartx_handle.Init.StopBits = UART_STOPBITS_1;
    uartx_handle.Init.Parity = UART_PARITY_NONE;
    uartx_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uartx_handle.Init.Mode = UART_MODE_TX_RX;

    HAL_UART_Init(&uartx_handle);
    HAL_UART_Receive_IT(&uartx_handle, (uint8_t *)g_usart_rx_buf, RXBUFFERSIZE);
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef gpio_init_struct;
    if (huart->Instance == USART1)
    {
        USART_UX_CLK_ENABLE();      /*USART1 时钟使能*/
        USART_TX_GPIO_CLK_ENABLE(); /*发送引脚时钟使能——被复用的 IO 口引脚*/
        USART_RX_GPIO_CLK_ENABLE(); /*接收引脚时钟使能*/

        gpio_init_struct.Pin = USART_TX_GPIO_PIN;
        gpio_init_struct.Mode = GPIO_MODE_AF_PP;
        gpio_init_struct.Pull = GPIO_PULLUP; /*复用推挽输出时使用上拉或下拉电阻是用来增加负载能力的，也就是增加驱动电流或者分流灌电流*/
        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(USART_TX_GPIO_PORT, &gpio_init_struct);

        gpio_init_struct.Pin = USART_RX_GPIO_PIN;
        gpio_init_struct.Mode = GPIO_MODE_AF_INPUT;
        HAL_GPIO_Init(USART_RX_GPIO_PORT, &gpio_init_struct);

#if USART_EN_RX
        HAL_NVIC_EnableIRQ(USART_UX_IRQn);
        HAL_NVIC_SetPriority(USART_UX_IRQn, 3, 3);
#endif
    }
}

void USART_UX_IRQHandler(void)
{
#if SYS_SUPPORT_OS
    OSIntEnter();
#endif
    HAL_UART_IRQHandler(&uartx_handle);
#if SYS_SUPPORT_OS
    OSIntExit();
#endif
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART_UX)
    {
        if ((g_usart_rx_sta & 0x8000) == 0)
        {
            if (g_usart_rx_sta & 0x4000)
            {
                if (g_usart_rx_buf[0] != 0x0a)
                {
                    g_usart_rx_sta = 0;
                }
                else
                {
                    g_usart_rx_sta |= 0x8000;
                }
            }
            else
            {
                if (g_usart_rx_buf[0] == 0x0d)
                {
                    g_usart_rx_sta |= 0x4000;
                }
                else
                {
                    g_usart_rx_buf[g_usart_rx_sta & 0x3fff] = g_usart_rx_buf[0];
                    g_usart_rx_sta++;
                    if (g_usart_rx_sta > (USART_REC_LEN - 1))
                    {
                        g_usart_rx_sta = 0;
                    }
                }
            }
        }
        HAL_UART_Receive_IT(&uartx_handle, (uint8_t *)g_usart_rx_buf, RXBUFFERSIZE);
    }
}