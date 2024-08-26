#include "stm32f1xx_hal.h"
#include "key.h"

void KEY_Init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();//开启GPIOB时钟
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pin = GPIO_PIN_0;
    GPIO_InitStructure.Pull = GPIO_PULLUP; 
    HAL_GPIO_Init(GPIOB,&GPIO_InitStructure);//配置为上拉输入
}


/*函 数 名：按键检测
 *参    数：mode 模式：0为按下执行，1抬起执行
 *返 回 值：0 为无按键触发；1为按键1触发
 *注意事项：按键低电平有效
 */


uint8_t KEY_Scan(uint8_t mode)
{
    static uint8_t KEY1_State = 1;  //按键状态变量。1为松开，0为按下
    if(KEY1_IN == 0 && KEY1_State)//判断按下
    {
        HAL_Delay(10);      //消抖
        if(KEY1_IN == 0)    //确实按下
        {
            KEY1_State = 0; //定义状态为已经按下
            if(mode == 0)    //如果模式为 按下触发
            {
                return 1;   //立刻返回1
            }
        }
    }
    else if(KEY1_IN == 1 && (!KEY1_State))//判断抬起
    {
        HAL_Delay(1000);      //消抖
        if(KEY1_IN == 1)    //确实抬起
        {
            KEY1_State = 1; //定义状态为已经抬起
            if(mode == 1)    //如果模式为 抬起触发
            {
                return 1;   //立刻返回1
            }
        }
    }
    
    return 0;
}










