#include "stm32f1xx_hal.h"
#include "rcc.h"


/*�� �� ����
 *��    ����
 *�� �� ֵ��
 *ע�����
 */
int main (void)
{
    HAL_Init();//��ʼ��HAL��
    RCC_ClockInit();//����ʱ��Ϊ72MHZ
    
    
    while(1)
    {
    
    
    }

}
