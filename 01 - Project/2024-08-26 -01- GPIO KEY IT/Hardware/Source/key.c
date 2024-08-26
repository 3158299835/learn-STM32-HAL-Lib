#include "stm32f1xx_hal.h"
#include "key.h"

//中断方式初始化
//mode 模式：0为按下执行，1抬起执行
//按键为低电平有效
//所以按下执行 检测下降沿进入中断、抬起执行，检测上升沿进入中断
void KEY_Init_IT(uint8_t mode)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();   //开启GPIOB时钟
    
    GPIO_InitTypeDef GPIO_InitStructure;
    
    if(mode == 0)   //判断模式：是否为按下执行
    {
        GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING; //下降沿进入中断 模式
    }
    else    //否则为抬起执行
    {
        GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING; //上升沿进入中断  模式
    }
    
    GPIO_InitStructure.Pin = GPIO_PIN_0 | GPIO_PIN_10;
    GPIO_InitStructure.Pull = GPIO_PULLUP; 
    HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);//配置PB 10 、 0的模式
    
    //HAL库默认中断分组为组4 抢占4 响应0
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    
    //设置中断优先级
    HAL_NVIC_SetPriority(EXTI0_IRQn,4,0);   //抢占和响应
    HAL_NVIC_EnableIRQ(EXTI0_IRQn); //使能
    
    HAL_NVIC_SetPriority(EXTI15_10_IRQn,4,0);   //抢占和响应(这里设置的抢占优先级更高)
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); //使能
    
    HAL_NVIC_SetPriority(SysTick_IRQn,0,0);//设置滴答定时器为最高优先级，否则会卡死在HAL_Delay函数中
}


//定义 （强声明的） HAL库回调函数
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    switch(GPIO_Pin)//根据进入时的Pin值来选择不同的动作
    {
        case GPIO_PIN_0 : 
        {
            if(KEY1_IN == 0)//判断按下
            {
                HAL_Delay(10);      //消抖
                if(KEY1_IN == 0)    //确实按下
                {
                    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
                }
            }
            else if(KEY1_IN == 1)//判断抬起
            {
                HAL_Delay(10);      //消抖
                if(KEY1_IN == 1)    //确实抬起
                {
                    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
                }
            }
            break;
        }
        case GPIO_PIN_10 : 
        {
            if(KEY2_IN == 0)//判断按下
            {
                HAL_Delay(10);      //消抖
                if(KEY2_IN == 0)    //确实按下
                {
                    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
                }
            }
            else if(KEY2_IN == 1)//判断抬起
            {
                HAL_Delay(10);      //消抖
                if(KEY2_IN == 1)    //确实抬起
                {
                    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_15);
                }
            }
            break;
        }   
    }
}



