#include "stm32f1xx_hal.h"
#include "rcc.h"


void RCC_ClockInit()
{
    RCC_OscInitTypeDef RCC_OsInitStructure; //设置内外部时钟源配置结构体
    RCC_ClkInitTypeDef RCC_ClkInitStructure;//设置总线时钟结构体
    
    RCC_OsInitStructure.OscillatorType = RCC_OSCILLATORTYPE_HSE;    //选择震荡电路为外部高速
    RCC_OsInitStructure.HSEState = RCC_HSE_ON;  //打开HSE时钟
    RCC_OsInitStructure.HSEPredivValue = RCC_HSE_PREDIV_DIV1;   //不分频
    RCC_OsInitStructure.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;   //设置微调值 默认
    RCC_OsInitStructure.PLL.PLLState = RCC_PLL_ON;  //设置PLL为打开
    RCC_OsInitStructure.PLL.PLLSource = RCC_PLLSOURCE_HSE; //选择PLL输入为外部高速时钟
    RCC_OsInitStructure.PLL.PLLMUL = RCC_PLL_MUL9;          //设置9倍频
    HAL_RCC_OscConfig(&RCC_OsInitStructure);    //传给话务员..
    
    RCC_ClkInitStructure.ClockType = RCC_CLOCKTYPE_HCLK  | RCC_CLOCKTYPE_PCLK1 |RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_SYSCLK;//需要配置的时钟
    RCC_ClkInitStructure.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; //SYSCLK系统时钟输入源 PLL作为系统时钟
    RCC_ClkInitStructure.AHBCLKDivider = RCC_SYSCLK_DIV1;   //AHB预分频 1分频
    RCC_ClkInitStructure.APB1CLKDivider = RCC_HCLK_DIV2;    //APB1预分频 2分频
    RCC_ClkInitStructure.APB2CLKDivider = RCC_HCLK_DIV1;    //APB2预分频 1分频
    HAL_RCC_ClockConfig(&RCC_ClkInitStructure,FLASH_LATENCY_2);//传给话务员，并且根据频率设置FLASH等待周期为2
    
    //话务员相关配置可以在API函数中找到。结构体相关配置在结构体和成员中可找到
}






