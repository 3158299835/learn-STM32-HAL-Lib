#include "stm32f1xx_hal.h"

#include "rcc.h"
#include "led.h"
#include "key.h"

/*函 数 名：设置PB00、PB10  中断方式 实现 按下有效、抬起有效、长按、短按、
 *参    数：
 *返 回 值：
 *注意事项：
 */

 
int main (void)
{
    HAL_Init();//初始化HAL库
    
    RccClock_Init();//配置时钟树72M
    
    LED_Init();//LED初始化
    
    KEY_Init_IT(1);
    
    while(1)
    {

    }

}
