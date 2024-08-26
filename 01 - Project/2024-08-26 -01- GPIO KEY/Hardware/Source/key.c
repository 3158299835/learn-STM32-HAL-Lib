#include "stm32f1xx_hal.h"
#include "key.h"

void KEY_Init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();//����GPIOBʱ��
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pin = GPIO_PIN_0;
    GPIO_InitStructure.Pull = GPIO_PULLUP; 
    HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);//����Ϊ��������
}


/*�� �� �����������
 *��    ����mode ģʽ��0Ϊ����ִ�У�1̧��ִ��
 *�� �� ֵ��0 Ϊ�ް���������1Ϊ����1����
 *ע����������͵�ƽ��Ч
 */


uint8_t KEY_Scan(uint8_t mode)
{
    static uint8_t KEY1_State = 1;  //����״̬������1Ϊ�ɿ���0Ϊ����
    if(KEY1_IN == 0 && KEY1_State)//�жϰ���
    {
        HAL_Delay(10);      //����
        if(KEY1_IN == 0)    //ȷʵ����
        {
            KEY1_State = 0; //����״̬Ϊ�Ѿ�����
            if(mode == 0)    //���ģʽΪ ���´���
            {
                return 1;   //���̷���1
            }
        }
    }
    else if(KEY1_IN == 1 && (!KEY1_State))//�ж�̧��
    {
        HAL_Delay(1000);      //����
        if(KEY1_IN == 1)    //ȷʵ̧��
        {
            KEY1_State = 1; //����״̬Ϊ�Ѿ�̧��
            if(mode == 1)    //���ģʽΪ ̧�𴥷�
            {
                return 1;   //���̷���1
            }
        }
    }
    
    return 0;
}










