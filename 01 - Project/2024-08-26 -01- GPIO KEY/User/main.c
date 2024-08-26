#include "stm32f1xx_hal.h"

#include "rcc.h"
#include "led.h"
#include "key.h"

/*�� �� ��������PB00  ʵ�� ������Ч��̧����Ч���������̰���
 *��    ����
 *�� �� ֵ��
 *ע�����
 */

 
int main (void)
{
    HAL_Init();//��ʼ��HAL��
    
    RccClock_Init();//����ʱ����72M
    
    LED_Init();
    KEY_Init();
    
    while(1)
    {
        switch(KEY_Scan(1))
        {
            case 1:HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
                    break;
            
        
        }
    }

}
