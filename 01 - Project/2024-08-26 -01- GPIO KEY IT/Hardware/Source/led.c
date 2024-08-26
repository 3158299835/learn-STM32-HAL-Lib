#include "stm32f1xx_hal.h"
#include "led.h"

void LED_Init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();//开启GPIOB时钟
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Pin = GPIO_PIN_15;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);
    
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);//默认高电平（关）
}
