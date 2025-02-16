#ifndef __KEY_H_
#define __KEY_H_

#include "./SYSTEM/sys/sys.h"

/* ���ţ��˿ڣ�ʱ��ʹ�ܶ��� */
#define KEY0_GPIO_PORT GPIOE
#define KEY0_GPIO_PIN GPIO_PIN_4
#define KEY0_GPIO_CLK_ENABLE()        \
    do                                \
    {                                 \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)

#define KEY1_GPIO_PORT GPIOE
#define KEY1_GPIO_PIN GPIO_PIN_3
#define KEY1_GPIO_CLK_ENABLE()        \
    do                                \
    {                                 \
        __HAL_RCC_GPIOE_CLK_ENABLE(); \
    } while (0)

#define WKUP_GPIO_PORT GPIOA
#define WKUP_GPIO_PIN GPIO_PIN_0
#define WKUP_GPIO_CLK_ENABLE()        \
    do                                \
    {                                 \
        __HAL_RCC_GPIOA_CLK_ENABLE(); \
    } while (0)

#define KEY0 HAL_GPIO_ReadPin(KEY0_GPIO_PORT, KEY0_GPIO_PIN)  /*��ȡ KEY0 ����*/
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_PORT, KEY1_GPIO_PIN)  /*��ȡ KEY1 ����*/
#define WK_UP HAL_GPIO_ReadPin(WKUP_GPIO_PORT, WKUP_GPIO_PIN) /*��ȡ WKUP ����*/

#define KEY0_PRES 1 /*KEY0 ����*/
#define KEY1_PRES 2 /*KEY1 ����*/
#define WKUP_PRES 3 /*WK_UP ����*/

/**
 * @brief ������ʼ������
 * @param ��
 * @retval ��
 */
void key_init(void);

/**
 * @brief ����ɨ�躯��
 * @note �ú�������Ӧ���ȼ�(ͬʱ���¶������): WK_UP > KEY1 > KEY0!!
 * @param mode:0 / 1, ���庬������:
 * @arg 0, ��֧��������(���������²���ʱ, ֻ�е�һ�ε��û᷵�ؼ�ֵ,
 * �����ɿ��Ժ�, �ٴΰ��²Ż᷵��������ֵ)
 * @arg 1, ֧��������(���������²���ʱ, ÿ�ε��øú������᷵�ؼ�ֵ)
 * @retval ��ֵ, ��������:
 * KEY0_PRES, 1, KEY0 ����
 * KEY1_PRES, 2, KEY1 ����
 * WKUP_PRES, 3, WKUP ����
 */
uint8_t key_scan(uint8_t mode);

#endif