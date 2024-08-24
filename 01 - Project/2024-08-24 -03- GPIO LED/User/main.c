#include "stm32f1xx_hal.h"

#include "rcc.h"

#include "led.h"
/*函 数 名：设置PB15 LED灯闪烁
 *参    数：
 *返 回 值：
 *注意事项：
 */

 
int main (void)
{
    HAL_Init();//初始化HAL库
    
    RccClock_Init();//配置时钟树72M
    
    LED_Init();
    
    while(1)
    {
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
        HAL_Delay(500);
    }

}
