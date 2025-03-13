#include "./BSP/btim/btim.h"
#include "./BSP/led/led.h"

TIM_HandleTypeDef g_btim_handle;

void btim_timx_int_init(uint16_t psc, uint16_t arr)
{
    g_btim_handle.Instance = TIM6;
    g_btim_handle.Init.Prescaler = psc;
    g_btim_handle.Init.Period = arr;
    HAL_TIM_Base_Init(&g_btim_handle);
	HAL_TIM_Base_Start_IT(&g_btim_handle);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM6)
	{
		__HAL_RCC_TIM6_CLK_ENABLE();
		HAL_NVIC_SetPriority(TIM6_IRQn, 1, 2);
		HAL_NVIC_EnableIRQ(TIM6_IRQn);
	}
}

void TIM6_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&g_btim_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM6)
	{
		LED0_TOGGLE();
	}
}