#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
#include "./BSP/wwdg/wwdg.h"

int main(void)
{
	/*系统初始化*/
	HAL_Init();							/* 初始化 HAL 库 */
	sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
	delay_init(72);						/* 延时初始化 */
	usart_init(115200);
	/*用户初始化*/
	led_init(); /* LED 初始化 */
	if(__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST) != RESET)
	{
		printf("窗口看门狗复位！\r\n");
		__HAL_RCC_CLEAR_RESET_FLAGS();
	}else
	{
		printf("外部复位！\r\n");
	}
	delay_ms(500);
	printf("请在窗口期内喂狗！\r\n\r\n");
	wwdg_init(0x7f,0x5f,WWDG_PRESCALER_8);

	while (1)
	{
		delay_ms(87);
		HAL_WWDG_Refresh(&g_wwdg_handle);
		LED0_TOGGLE();
		printf("已喂狗。\r\n");
	}
}
