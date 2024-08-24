#include "stm32f1xx_hal.h"

#include "rcc.h"
/*�� �� ����rcc����ΪHSE�ⲿ����ʱ�ӣ�ͨ��PLL��Ƶ��72MHZ �����PA8����
 *��    ����
 *�� �� ֵ��
 *ע�����
 */
 
uint32_t HCLKFreq  = 0;//��ʾʱ��������Ƶ��
uint32_t PCLK1Freq = 0;
uint32_t PCLK2Freq = 0;
 
int main (void)
{
    HAL_Init();//��ʼ��HAL��
    RCC_ClockInit();//����ʱ������ʼ��
    
    HAL_RCC_MCOConfig(RCC_MCO1,RCC_MCO1SOURCE_SYSCLK,RCC_MCODIV_1);//PA8���������ϵͳʱ�ӡ�����Ƶ

    HCLKFreq  = HAL_RCC_GetHCLKFreq();
    PCLK1Freq = HAL_RCC_GetPCLK1Freq();
    PCLK2Freq = HAL_RCC_GetPCLK2Freq();
    
    while(1)
    {
    
    
    }

}
