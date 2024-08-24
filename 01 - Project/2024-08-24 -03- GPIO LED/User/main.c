#include "stm32f1xx_hal.h"

#include "rcc.h"

#include "led.h"
/*�� �� ��������PB15 LED����˸
 *��    ����
 *�� �� ֵ��
 *ע�����
 */

 
int main (void)
{
    HAL_Init();//��ʼ��HAL��
    
    RccClock_Init();//����ʱ����72M
    
    LED_Init();
    
    while(1)
    {
        HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
        HAL_Delay(500);
    }

}
