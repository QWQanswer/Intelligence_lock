/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* SPDX-License-Identifier: Apache-2.0
*******************************************************************************/

/*
 *@Note
 串口打印调试例程：
 USART1_Tx(PA9)。
 本例程演示使用 USART1(PA9) 作打印调试口输出。

*/

#include "debug.h"
#include "lcd.h"
#include "display.h"
#include "key.h"
#include "as608.h"
#include "usart2.h"
#include "timer.h"
#include "use_as608.h"
#include "uart_openmv.h"
#include "PWM.h"
#include "Niming.h"

/* Global typedef */

/* Global define */

/* Global Variable */

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */

u8 num_last=1;
int recv;
enum Judge OpenMV_Volue;
u8 flag_getOpenMVdata=0;


int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n",SystemCoreClock);


    LCD_Init();
    LCD_SetBrightness(40);
    Display_keyboard();
    PS_StaGPIO_Init();//初始化FR读状态引脚
    //usart3_init(57600);//初始化串口3,用于与指纹模块通讯
    EXTI_INT_INIT();
    //USART_OpenMV();//初始化串口2,用于与OpenMV模块通讯,baud 19200
    while(1)
    {
        if(flag_warning==0)
        {
            if(flag_reshow)
            {
                LCD_SetColor(0x18E3, WHITE);
                LCD_Clear(BLACK);
                Display_keyboard();
                flag_reshow=0;
                flag_JudgeFR=0;
                flag_InFR=0;
                flag_dispaly_OpenMV=0;
            }
            if(flag_enter)
                flag_enter=0,Display_EnterNum(num);
            num=keyboard[Y_key][X_key];
            if(num!=num_last)
                Clear_Line(num_last);
            Display_BlinkLine(num);
            num_last=num;

            if(flag_JudgeFR)
            {
                Judge_FR();
                Display_JudgeFR();
            }
            else if(flag_InFR)
            {
                Add_FR();
                Display_AddFR();
            }
            if (flag_dispaly_OpenMV)
            {

                recv = USART_ReceiveData(USART2);                               //读取接收到的数据
                if(flag_getOpenMVdata)                                           //只取一次openmv返回值
                {
                    if (recv%10==1)                                                 //取最后一次收到的数据
                    {
                        OpenMV_Volue=Right;
                    }
                    else if (recv%10==2)
                    {
                        OpenMV_Volue=Wrong;
                    }
                    flag_getOpenMVdata=0;
                }
                Display_OpenMV();
            }

            if(flag_OpenMV==1)
            {
                USART_SendData(USART2, 0x11);                                   //发送数据
                flag_dispaly_OpenMV=1;
                flag_getOpenMVdata=1;
                flag_OpenMV=0;
            }

            if(time_error_count>=5)
                flag_warning=1;
        }
        if(flag_warning==1&&flag_OpenMV==0&&flag_JudgeFR==0&&flag_InFR==0)
        {
            Display_Warning();
            flag_warning=2;
            time_error_count=0;
        }
        if(flag_warning==2)
        {
            Keep_Warning();
            printf("Warning\r\n");
        }
    }
}




