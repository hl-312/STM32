#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
#include "./BSP/beep/beep.h"
#include "./BSP/key/key.h"

int main(void)
{
	/*��Ƭ���б�����������ں�������ǰ����������ȫ�ֱ�����¼����ɨ�躯���ķ���ֵ*/
	uint8_t key;

	/*ϵͳ��ʼ��*/
	HAL_Init();							/* ��ʼ�� HAL �� */
	sys_stm32_clock_init(RCC_PLL_MUL9); /* ����ʱ��, 72Mhz */
	delay_init(72);						/* ��ʱ��ʼ�� */
	/*�û���ʼ��*/
	led_init();	 /* LED ��ʼ�� */
	beep_init(); /* BEEP ��ʼ�� */
	key_init();

	while (1)
	{
		key = key_scan(1); /*����ģʽ��������ȶ���Ҳ�п����ǲ��������Ƿ�ת��ԭ��Ӧ����������*/
		if (key)
		{
			switch (key)
			{
			case WKUP_PRES:
				BEEP_TOGGLE();
				break;
			case KEY1_PRES:
				LED1_TOGGLE();
				break;
			case KEY0_PRES:
				LED0_TOGGLE();
				LED1_TOGGLE();
				break;
			default:
				break;
			}
		}
		else
		{
			delay_ms(10);
		}
	}
}
