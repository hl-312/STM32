#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
#include "./BSP/beep/beep.h"
#include "./BSP/key/key.h"

int main(void)
{
	/*单片机中变量好像必须在函数调用前声明，定义全局变量记录按键扫描函数的返回值*/
	uint8_t key;

	/*系统初始化*/
	HAL_Init();							/* 初始化 HAL 库 */
	sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
	delay_init(72);						/* 延时初始化 */
	/*用户初始化*/
	led_init();	 /* LED 初始化 */
	beep_init(); /* BEEP 初始化 */
	key_init();

	while (1)
	{
		key = key_scan(1); /*长按模式，结果不稳定，也有可能是操作函数是反转的原因，应该是正常的*/
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
