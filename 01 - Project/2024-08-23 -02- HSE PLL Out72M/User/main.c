#include "stm32f1xx_hal.h"

#include "rcc.h"
/*函 数 名：rcc设置为HSE外部高速时钟，通过PLL倍频到72MHZ 输出到PA8引脚
 *参    数：
 *返 回 值：
 *注意事项：
 */
 
uint32_t HCLKFreq  = 0;//显示时钟树三处频率
uint32_t PCLK1Freq = 0;
uint32_t PCLK2Freq = 0;
 
int main (void)
{
    HAL_Init();//初始化HAL库
    RCC_ClockInit();//配置时钟树初始化
    
    HAL_RCC_MCOConfig(RCC_MCO1,RCC_MCO1SOURCE_SYSCLK,RCC_MCODIV_1);//PA8引脚输出、系统时钟、不分频

    HCLKFreq  = HAL_RCC_GetHCLKFreq();
    PCLK1Freq = HAL_RCC_GetPCLK1Freq();
    PCLK2Freq = HAL_RCC_GetPCLK2Freq();
    
    while(1)
    {
    
    
    }

}
