#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
//#include "./BSP/usart/usart.h"

extern UART_HandleTypeDef uartx_handle;

int main(void)
{
	uint8_t len;
	uint16_t times = 0;
	/*ϵͳ��ʼ��*/
	HAL_Init();							/* ��ʼ�� HAL �� */
	sys_stm32_clock_init(RCC_PLL_MUL9); /* ����ʱ��, 72Mhz */
	delay_init(72);						/* ��ʱ��ʼ�� */
	usart_init(72, 115200);
	/*�û���ʼ��*/
	led_init(); /* LED ��ʼ�� */

	while (1)
	{
		if (g_usart_rx_sta & 0x8000) /* ���յ�������? */
		{
			len = g_usart_rx_sta & 0x3fff; /* �õ��˴ν��յ������ݳ��� */
			printf("\r\n �����͵���ϢΪ:\r\n");
			/*���ͽ��յ�������*/
			HAL_UART_Transmit(&uartx_handle, (uint8_t *)g_usart_rx_buf, len, 1000);
			/*�ȴ����ͽ���*/
			while (__HAL_UART_GET_FLAG(&uartx_handle, UART_FLAG_TC) != SET)
				;
			printf("\r\n\r\n"); /* ���뻻�� */
			g_usart_rx_sta = 0;
		}
		else
		{
			times++;
			if (times % 5000 == 0)
			{
				printf("\r\n ����ԭ�� STM32 ������ ����ʵ��\r\n");
				printf("����ԭ��@ALIENTEK\r\n\r\n\r\n");
			}
			if (times % 200 == 0)
				printf("����������,�Իس�������\r\n");
			if (times % 30 == 0)
				LED0_TOGGLE(); /* ��˸ LED,��ʾϵͳ��������. */
			delay_ms(10);
		}
	}
}
