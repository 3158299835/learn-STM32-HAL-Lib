#ifndef __KEY_H
#define __KEY_H

#define KEY1_IN HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)
#define KEY2_IN HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10)

//�жϷ�ʽ��ʼ��
//mode ģʽ��0Ϊ����ִ�У�1̧��ִ��
void KEY_Init_IT(uint8_t mode);



#endif
