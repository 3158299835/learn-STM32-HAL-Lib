#include "stm32f1xx_hal.h"

#include "rcc.h"
#include "led.h"
#include "key.h"

/*�� �� ��������PB00��PB10  �жϷ�ʽ ʵ�� ������Ч��̧����Ч���������̰���
 *��    ����
 *�� �� ֵ��
 *ע�����
 */

 
int main (void)
{
    HAL_Init();//��ʼ��HAL��
    
    RccClock_Init();//����ʱ����72M
    
    LED_Init();//LED��ʼ��
    
    KEY_Init_IT(1);
    
    while(1)
    {

    }

}
