#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
#include "./BSP/iwdg/iwdg.h"

int main(void)
{
	/*ϵͳ��ʼ��*/
	HAL_Init();							/* ��ʼ�� HAL �� */
	sys_stm32_clock_init(RCC_PLL_MUL9); /* ����ʱ��, 72Mhz */
	delay_init(72);						/* ��ʱ��ʼ�� */
	usart_init(115200);
	/*�û���ʼ��*/
	led_init(); /* LED ��ʼ�� */
	printf("����û�м�ʱι����\r\n");
	iwdg_init(IWDG_PRESCALER_64, 1250); /*��ʱ2s*/

	while (1)
	{
		delay_ms(2020);
		iwdg_feed();
		printf("��ι����\r\n");
	}
}
