#include "stm32f1xx_hal.h"
#include "rcc.h"


/*函 数 名：
 *参    数：
 *返 回 值：
 *注意事项：
 */
int main (void)
{
    HAL_Init();//初始化HAL库
    RCC_ClockInit();//配置时钟为72MHZ
    
    
    while(1)
    {
    
    
    }

}
