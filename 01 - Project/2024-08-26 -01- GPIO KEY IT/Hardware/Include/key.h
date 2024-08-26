#ifndef __KEY_H
#define __KEY_H

#define KEY1_IN HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)
#define KEY2_IN HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10)

//中断方式初始化
//mode 模式：0为按下执行，1抬起执行
void KEY_Init_IT(uint8_t mode);



#endif
