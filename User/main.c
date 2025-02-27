#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
// #include "./BSP/usart/usart.h"

int main(void)
{
	uint8_t len;
	uint16_t times = 0;
	/*系统初始化*/
	HAL_Init();							/* 初始化 HAL 库 */
	sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
	delay_init(72);						/* 延时初始化 */
	usart_init(115200);
	/*用户初始化*/
	led_init(); /* LED 初始化 */

	while (1)
	{
		if (g_usart_rx_sta & 0x8000) /* 接收到了数据? */
		{
			len = g_usart_rx_sta & 0x3fff; /* 得到此次接收到的数据长度 */
			printf("\r\n 您发送的消息为:\r\n");
			/*发送接收到的数据*/
			HAL_UART_Transmit(&g_uart1_handle, (uint8_t *)g_usart_rx_buf, len, 1000);
			/*等待发送结束*/
			while (__HAL_UART_GET_FLAG(&g_uart1_handle, UART_FLAG_TC) != SET)
				;
			printf("\r\n\r\n"); /* 插入换行 */
			g_usart_rx_sta = 0;
		}
		else
		{
			times++;
			if (times % 5000 == 0)
			{
				printf("\r\n 正点原子 STM32 开发板 串口实验\r\n");
				printf("正点原子@ALIENTEK\r\n\r\n\r\n");
			}
			if (times % 200 == 0)
				printf("请输入数据,以回车键结束\r\n");
			if (times % 30 == 0)
				LED0_TOGGLE(); /* 闪烁 LED,提示系统正在运行. */
			delay_ms(10);
		}
	}
}
