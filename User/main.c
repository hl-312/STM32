#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
#include "./BSP/beep/beep.h"
#include "./BSP/key/key.h"
#include "./BSP/exti/exti.h"

int main(void)
{
	/*系统初始化*/
	HAL_Init();							/* 初始化 HAL 库 */
	sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
	delay_init(72);						/* 延时初始化 */
	usart_init(72,115200);
	/*用户初始化*/
	led_init();	 /* LED 初始化 */
	beep_init(); /* BEEP 初始化 */
	extix_init();
	LED0(0);

	while (1)
	{
		printf("OK\r\n");
		delay_ms(1000);
	}
}
