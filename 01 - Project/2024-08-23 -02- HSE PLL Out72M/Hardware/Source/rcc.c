#include "stm32f1xx_hal.h"
#include "rcc.h"


void RCC_ClockInit()
{
    RCC_OscInitTypeDef RCC_OsInitStructure; //�������ⲿʱ��Դ���ýṹ��
    RCC_ClkInitTypeDef RCC_ClkInitStructure;//��������ʱ�ӽṹ��
    
    RCC_OsInitStructure.OscillatorType = RCC_OSCILLATORTYPE_HSE;    //ѡ���𵴵�·Ϊ�ⲿ����
    RCC_OsInitStructure.HSEState = RCC_HSE_ON;  //��HSEʱ��
    RCC_OsInitStructure.HSEPredivValue = RCC_HSE_PREDIV_DIV1;   //����Ƶ
    RCC_OsInitStructure.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;   //����΢��ֵ Ĭ��
    RCC_OsInitStructure.PLL.PLLState = RCC_PLL_ON;  //����PLLΪ��
    RCC_OsInitStructure.PLL.PLLSource = RCC_PLLSOURCE_HSE; //ѡ��PLL����Ϊ�ⲿ����ʱ��
    RCC_OsInitStructure.PLL.PLLMUL = RCC_PLL_MUL9;          //����9��Ƶ
    HAL_RCC_OscConfig(&RCC_OsInitStructure);    //��������Ա..
    
    RCC_ClkInitStructure.ClockType = RCC_CLOCKTYPE_HCLK  | RCC_CLOCKTYPE_PCLK1 |RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_SYSCLK;//��Ҫ���õ�ʱ��
    RCC_ClkInitStructure.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; //SYSCLKϵͳʱ������Դ PLL��Ϊϵͳʱ��
    RCC_ClkInitStructure.AHBCLKDivider = RCC_SYSCLK_DIV1;   //AHBԤ��Ƶ 1��Ƶ
    RCC_ClkInitStructure.APB1CLKDivider = RCC_HCLK_DIV2;    //APB1Ԥ��Ƶ 2��Ƶ
    RCC_ClkInitStructure.APB2CLKDivider = RCC_HCLK_DIV1;    //APB2Ԥ��Ƶ 1��Ƶ
    HAL_RCC_ClockConfig(&RCC_ClkInitStructure,FLASH_LATENCY_2);//��������Ա�����Ҹ���Ƶ������FLASH�ȴ�����Ϊ2
    
    //����Ա������ÿ�����API�������ҵ����ṹ����������ڽṹ��ͳ�Ա�п��ҵ�
}






