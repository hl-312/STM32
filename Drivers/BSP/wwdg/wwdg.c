#include "./BSP/wwdg/wwdg.h"
#include "./BSP/led/led.h"

/*
 * 工作参数初始化 HAL_WWDG_Init()
 * 底层初始化/回调函数内实现 HAL_WWDG_MspInit() 配置 NVIC、CLOCK——RCC
 *      设置优先级，使能中断 HAL_NVIC_SetPriority(), HAL_NVIC_EnableIRQ()
 * 编写中断服务函数=按照回调机制调用 HAL 的公共中断服务函数 WWDG_IRQHandler()->HAL_WWDG_IRQHandler()
 * 重定义提前唤醒回调函数=按照回调机制重定义被 HAL 的公共中断服务函数所调用的具体处理函数 HAL_WWDG_EarlyWakeupCallback()
 * 在窗口期内喂狗 HAL_WWDG_Refresh()
 */

WWDG_HandleTypeDef g_wwdg_handle;

/*用户初始化函数：创建配置表=创建句柄（全局变量），填写句柄，调用 HAL 初始化函数并传递句柄*/
void wwdg_init(uint8_t tr, uint8_t wr, uint32_t fprer)
{
    g_wwdg_handle.Instance = WWDG;
    g_wwdg_handle.Init.Counter = tr;
    g_wwdg_handle.Init.Window = wr;
    g_wwdg_handle.Init.Prescaler = fprer;
    g_wwdg_handle.Init.EWIMode = WWDG_EWI_ENABLE;
    HAL_WWDG_Init(&g_wwdg_handle);
}

/*HAL 初始化函数的回调函数 MspInit，负责底层初始化，相关硬件外设的初始化、中断配置和初始化、时钟 RCC 设置等等*/
void HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)
{
    __HAL_RCC_WWDG_CLK_ENABLE();
    HAL_NVIC_SetPriority(WWDG_IRQn, 2, 3);
    HAL_NVIC_EnableIRQ(WWDG_IRQn);
}

/*重定义内核中断函数（定义于.s 启动文件里），即中断流程里的请求步骤，回调 HAL 公共中断服务*/
void WWDG_IRQHandler(void)
{
    HAL_WWDG_IRQHandler(&g_wwdg_handle);
}

/*重定义具体中断服务函数，即中断流程里的处理步骤，由 HAL 公共中断服务回调具体处理函数 */
void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg)
{
    // HAL_WWDG_Refresh(&g_wwdg_handle);
    LED1_TOGGLE();
}