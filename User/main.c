#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
#include "./BSP/beep/beep.h"
#include "./BSP/key/key.h"
#include "./BSP/exti/exti.h"

int main(void)
{
	/*ϵͳ��ʼ��*/
	HAL_Init();							/* ��ʼ�� HAL �� */
	sys_stm32_clock_init(RCC_PLL_MUL9); /* ����ʱ��, 72Mhz */
	delay_init(72);						/* ��ʱ��ʼ�� */
	usart_init(72,115200);
	/*�û���ʼ��*/
	led_init();	 /* LED ��ʼ�� */
	beep_init(); /* BEEP ��ʼ�� */
	extix_init();
	LED0(0);

	while (1)
	{
		printf("OK\r\n");
		delay_ms(1000);
	}
}
