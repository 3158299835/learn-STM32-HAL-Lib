#include "stm32f1xx_hal.h"
#include "key.h"

//�жϷ�ʽ��ʼ��
//mode ģʽ��0Ϊ����ִ�У�1̧��ִ��
//����Ϊ�͵�ƽ��Ч
//���԰���ִ�� ����½��ؽ����жϡ�̧��ִ�У���������ؽ����ж�
void KEY_Init_IT(uint8_t mode)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();   //����GPIOBʱ��
    
    GPIO_InitTypeDef GPIO_InitStructure;
    
    if(mode == 0)   //�ж�ģʽ���Ƿ�Ϊ����ִ��
    {
        GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING; //�½��ؽ����ж� ģʽ
    }
    else    //����Ϊ̧��ִ��
    {
        GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING; //�����ؽ����ж�  ģʽ
    }
    
    GPIO_InitStructure.Pin = GPIO_PIN_0 | GPIO_PIN_10;
    GPIO_InitStructure.Pull = GPIO_PULLUP; 
    HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);//����PB 10 �� 0��ģʽ
    
    //HAL��Ĭ���жϷ���Ϊ��4 ��ռ4 ��Ӧ0
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    
    //�����ж����ȼ�
    HAL_NVIC_SetPriority(EXTI0_IRQn,4,0);   //��ռ����Ӧ
    HAL_NVIC_EnableIRQ(EXTI0_IRQn); //ʹ��
    
    HAL_NVIC_SetPriority(EXTI15_10_IRQn,4,0);   //��ռ����Ӧ(�������õ���ռ���ȼ�����)
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); //ʹ��
    
    HAL_NVIC_SetPriority(SysTick_IRQn,0,0);//���õδ�ʱ��Ϊ������ȼ�������Ῠ����HAL_Delay������
}


//���� ��ǿ�����ģ� HAL��ص�����
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    switch(GPIO_Pin)//���ݽ���ʱ��Pinֵ��ѡ��ͬ�Ķ���
    {
        case GPIO_PIN_0 : 
        {
            if(KEY1_IN == 0)//�жϰ���
            {
                HAL_Delay(10);      //����
                if(KEY1_IN == 0)    //ȷʵ����
                {
                    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
                }
            }
            else if(KEY1_IN == 1)//�ж�̧��
            {
                HAL_Delay(10);      //����
                if(KEY1_IN == 1)    //ȷʵ̧��
                {
                    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
                }
            }
            break;
        }
        case GPIO_PIN_10 : 
        {
            if(KEY2_IN == 0)//�жϰ���
            {
                HAL_Delay(10);      //����
                if(KEY2_IN == 0)    //ȷʵ����
                {
                    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
                }
            }
            else if(KEY2_IN == 1)//�ж�̧��
            {
                HAL_Delay(10);      //����
                if(KEY2_IN == 1)    //ȷʵ̧��
                {
                    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
                }
            }
            break;
        }   
    }
}



