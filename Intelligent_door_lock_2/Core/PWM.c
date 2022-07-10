/*
 * PWM.c
 *
 *  Created on: 2022年6月26日
 *      Author: hp
 */

#include "debug.h"
#include "PWM.h"

#define PWM_MODE1   0
#define PWM_MODE2   1

#define PWM_MODE PWM_MODE2



void TIM_PWMOut_Init(uint8_t type)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;

    switch(type)
    {
    case TIM3_CH4:
        RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE );//使能GPIO外设和AFIO复用功能模块时钟使能
        GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init( GPIOB, &GPIO_InitStructure );
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE );
        break;
    case TIM3_CH3:
        RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE );//使能GPIO外设和AFIO复用功能模块时钟使能
        GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init( GPIOC, &GPIO_InitStructure );
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE );
            break;
    case TIM3_CH2:
        RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE );//使能GPIO外设和AFIO复用功能模块时钟使能
        GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init( GPIOC, &GPIO_InitStructure );
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE );
            break;
    case TIM3_CH1:
        RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE );//使能GPIO外设和AFIO复用功能模块时钟使能
        GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init( GPIOC, &GPIO_InitStructure );
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE );
            break;
    case TIM2_CH3:
        RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE );//使能GPIO外设和AFIO复用功能模块时钟使能
        GPIO_PinRemapConfig(GPIO_FullRemap_TIM2, ENABLE);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init( GPIOB, &GPIO_InitStructure );
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE );
            break;
    case TIM2_CH4:
        RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE );//使能GPIO外设和AFIO复用功能模块时钟使能
        GPIO_PinRemapConfig(GPIO_FullRemap_TIM2, ENABLE);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init( GPIOB, &GPIO_InitStructure );
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE );
            break;
    default:
        break;
    }

    TIM_TimeBaseInitStructure.TIM_Period = ARR;//指定下次更新事件时要加载到活动自动重新加载寄存器中的周期值。
    TIM_TimeBaseInitStructure.TIM_Prescaler = PSC;//指定用于划分TIM时钟的预分频器值。
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    if(type > TIM2_CH4)
    TIM_TimeBaseInit( TIM3, &TIM_TimeBaseInitStructure);
    else
    TIM_TimeBaseInit( TIM2, &TIM_TimeBaseInitStructure);

#if (PWM_MODE == PWM_MODE1)
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;

#elif (PWM_MODE == PWM_MODE2)
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;

#endif

    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0.5/20.0*ARR;//指定要加载到捕获比较寄存器中的脉冲值。
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

    switch(type)
    {
    case TIM3_CH4:
        TIM_OC4Init( TIM3, &TIM_OCInitStructure );
        TIM_CtrlPWMOutputs(TIM3, ENABLE );
        TIM_OC4PreloadConfig( TIM3, TIM_OCPreload_Disable );//TIM_OCPreload_Enable  TIM_OCPreload_Disable
        TIM_ARRPreloadConfig( TIM3, ENABLE );
        TIM_Cmd( TIM3, ENABLE );
        break;
    case TIM3_CH3:
        TIM_OC3Init( TIM3, &TIM_OCInitStructure );
        TIM_CtrlPWMOutputs(TIM3, ENABLE );
        TIM_OC3PreloadConfig( TIM3, TIM_OCPreload_Disable );//TIM_OCPreload_Enable  TIM_OCPreload_Disable
        TIM_ARRPreloadConfig( TIM3, ENABLE );
        TIM_Cmd( TIM3, ENABLE );
        //TIM_SetCompare3(TIM3,1600);
            break;
    case TIM3_CH2:
        TIM_OC2Init( TIM3, &TIM_OCInitStructure );
        TIM_CtrlPWMOutputs(TIM3, ENABLE );
        TIM_OC2PreloadConfig( TIM3, TIM_OCPreload_Disable );//TIM_OCPreload_Enable  TIM_OCPreload_Disable
        TIM_ARRPreloadConfig( TIM3, ENABLE );
        TIM_Cmd( TIM3, ENABLE );
            break;
    case TIM3_CH1:
        TIM_OC1Init( TIM3, &TIM_OCInitStructure );
        TIM_CtrlPWMOutputs(TIM3, ENABLE );
        TIM_OC1PreloadConfig( TIM3, TIM_OCPreload_Disable );//TIM_OCPreload_Enable  TIM_OCPreload_Disable
        TIM_ARRPreloadConfig( TIM3, ENABLE );
        TIM_Cmd( TIM3, ENABLE );
            break;
    case TIM2_CH3:
        TIM_OC3Init( TIM2, &TIM_OCInitStructure );
        TIM_CtrlPWMOutputs(TIM2, ENABLE );
        TIM_OC3PreloadConfig( TIM2, TIM_OCPreload_Disable );//TIM_OCPreload_Enable  TIM_OCPreload_Disable
        TIM_ARRPreloadConfig( TIM2, ENABLE );
        TIM_Cmd( TIM2, ENABLE );
            break;
    case TIM2_CH4:
        TIM_OC4Init( TIM2, &TIM_OCInitStructure );
        TIM_CtrlPWMOutputs(TIM2, ENABLE );
        TIM_OC4PreloadConfig( TIM2, TIM_OCPreload_Disable );//TIM_OCPreload_Enable  TIM_OCPreload_Disable
        TIM_ARRPreloadConfig( TIM2, ENABLE );
        TIM_Cmd( TIM2, ENABLE );
            break;
    }
}

//设置占空比

void Set_PWM_Dutycycle(uint16_t dutycycle,uint8_t type)

{
    switch(type)
    {
    case TIM3_CH4:
        TIM_SetCompare4(TIM3,dutycycle); //设置TIM3捕获比较1寄存器值,，用于修改占空比
        break;
    case TIM3_CH3:
        TIM_SetCompare3(TIM3,dutycycle); //设置TIM3捕获比较1寄存器值,，用于修改占空比
            break;
    case TIM3_CH2:
        TIM_SetCompare2(TIM3,dutycycle); //设置TIM3捕获比较1寄存器值,，用于修改占空比
            break;
    case TIM3_CH1:
        TIM_SetCompare1(TIM3,dutycycle); //设置TIM3捕获比较1寄存器值,，用于修改占空比
            break;
    case TIM2_CH3:
        TIM_SetCompare3(TIM2,dutycycle); //设置TIM3捕获比较1寄存器值,，用于修改占空比
            break;
    case TIM2_CH4:
        TIM_SetCompare4(TIM2,dutycycle); //设置TIM3捕获比较1寄存器值,，用于修改占空比
            break;
    }

}


void Open_door(void)
{
    Set_PWM_Dutycycle(TIM3_CH4,150);
}

void Close_door(void)
{
    Set_PWM_Dutycycle(TIM3_CH4,250);
}
