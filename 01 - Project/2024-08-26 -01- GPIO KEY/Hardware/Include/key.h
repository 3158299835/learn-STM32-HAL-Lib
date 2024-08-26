#ifndef __KEY_H
#define __KEY_H

#define KEY1_IN HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)


//≥ı ºªØ
void KEY_Init(void);

//∞¥º¸…®√Ë
uint8_t KEY_Scan(uint8_t mode);

#endif
