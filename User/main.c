#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
#include "./BSP/wwdg/wwdg.h"

int main(void)
{
	/*ϵͳ��ʼ��*/
	HAL_Init();							/* ��ʼ�� HAL �� */
	sys_stm32_clock_init(RCC_PLL_MUL9); /* ����ʱ��, 72Mhz */
	delay_init(72);						/* ��ʱ��ʼ�� */
	usart_init(115200);
	/*�û���ʼ��*/
	led_init(); /* LED ��ʼ�� */
	if(__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST) != RESET)
	{
		printf("���ڿ��Ź���λ��\r\n");
		__HAL_RCC_CLEAR_RESET_FLAGS();
	}else
	{
		printf("�ⲿ��λ��\r\n");
	}
	delay_ms(500);
	printf("���ڴ�������ι����\r\n\r\n");
	wwdg_init(0x7f,0x5f,WWDG_PRESCALER_8);

	while (1)
	{
		delay_ms(87);
		HAL_WWDG_Refresh(&g_wwdg_handle);
		LED0_TOGGLE();
		printf("��ι����\r\n");
	}
}
