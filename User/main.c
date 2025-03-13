#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/led/led.h"
#include "./BSP/btim/btim.h"

int main(void)
{
	/*系统初始化*/
	HAL_Init();							/* 初始化 HAL 库 */
	sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
	delay_init(72);						/* 延时初始化 */
	usart_init(115200);
	/*用户初始化*/
	led_init(); /* LED 初始化 */
	btim_timx_int_init(7199,4999);

	while (1)
	{
	}
}
