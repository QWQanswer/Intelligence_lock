/*
 * use_as608.c
 *
 *  Created on: 2022年6月9日
 *      Author: hp
 */

#include "debug.h"
#include "lcd.h"
#include "display.h"
#include "key.h"
#include "as608.h"
#include "usart2.h"
#include "timer.h"
#include "use_as608.h"
#include "malloc.h"

u16 ID=1;
SysPara AS608Para;//指纹模块AS608参数

void ShowErrMessage(u8 ensure)
{
    LCD_Fill(120,120,240,160,BLACK);
    LCD_ShowString(120,120,32,0,(u8*)EnsureMessage(ensure));
}

void Add_FR(void)
{
    u8 i,ensure ,processnum=0;
//    u16 ID=1;
    while(TURE)
    {
        switch(processnum)
        {
            case 0:
                i++;
                LCD_Fill(0,160,240,200,BLACK);
                LCD_ShowString(0,160,32,0,"P FS");
                ensure=PS_GetImage();
                if(ensure==0x00)
                {
//                    BEEP=1;
                    ensure=PS_GenChar(CharBuffer1);
//                    BEEP=0;
                    if(ensure==0x00)
                    {
                        LCD_Fill(0,160,240,200,BLACK);
                        LCD_ShowString(0,160,32,0,"FS N");
                        i=0;
                        processnum=1;
                    }
                    else
                        ShowErrMessage(ensure);
                }
                else
                    ShowErrMessage(ensure);
                break;

            case 1:
                i++;
                LCD_Fill(0,160,240,200,BLACK);
                LCD_ShowString(0,160,32,0,"PA FS");
                ensure=PS_GetImage();
                if(ensure==0x00)
                {
//                    BEEP=1;
                    ensure=PS_GenChar(CharBuffer2);//生成特征
//                    BEEP=0;
                    if(ensure==0x00)
                    {
                        LCD_Fill(0,160,240,200,BLACK);
                        LCD_ShowString(0,160,32,0,"FS N");
                        i=0;
                        processnum=2;
                    }
                    else
                        ShowErrMessage(ensure);
                }
                else
                    ShowErrMessage(ensure);
                break;

            case 2:
                LCD_Fill(0,160,240,200,BLACK);
                LCD_ShowString(0,160,32,0,"DB FS");
                ensure=PS_Match();
                if(ensure==0x00)
                {
                    LCD_Fill(0,160,240,200,BLACK);
                    LCD_ShowString(0,160,32,0,"DB SC");
                    processnum=3;
                }
                else
                {
                    LCD_Fill(0,160,240,200,BLACK);
                    LCD_ShowString(0,160,32,0,"DB FA");
                    ShowErrMessage(ensure);
                    i=0;
                    processnum=3;
                }
                Delay_Ms(1200);
                break;

            case 3:
                LCD_Fill(0,160,240,200,BLACK);
                LCD_ShowString(0,160,32,0,"SCFS");
                ensure=PS_RegModel();
                if(ensure==0x00)
                {
                    LCD_Fill(0,160,240,200,BLACK);
                    LCD_ShowString(0,160,32,0,"SCFSSC");
                    processnum=4;//跳到第五步
                }
                else
                {
                    processnum=0;
                    ShowErrMessage(ensure);
                }
                Delay_Ms(1200);
                break;

            case 4:
                ensure=PS_StoreChar(CharBuffer2,ID);//储存模板
                if(ensure==0x00)
                {
                    LCD_Fill(0,160,240,200,BLACK);
                    LCD_ShowString(0,160,32,0,"LRFSC");

                    Delay_Ms(1500);
                    LCD_Fill(0,160,240,200,BLACK);
                    return ;
                }
                else
                {
                    processnum=0;
                    ShowErrMessage(ensure);
                }
                break;
        }
        Delay_Ms(1000);
        if (i==5)
        {
            break;
        }
    }
}



void press_FR(void)
{
    SearchResult seach;
    u8 ensure;
    ensure=PS_GetImage();
    if(ensure==0x00)//获取图像成功
    {
//        BEEP=1;//打开蜂鸣器
        ensure=PS_GenChar(CharBuffer1);
        if(ensure==0x00) //生成特征成功
        {
            ensure=PS_HighSpeedSearch(CharBuffer1,0,300,&seach);
            if(ensure==0x00)//搜索成功
            {
                LCD_Fill(0,200,240,220,BLACK);
                LCD_ShowString(0,200,16,0,"SFSSC");
            }
            else
            {
                ShowErrMessage(ensure);
            }
        }
        else
        {
            ShowErrMessage(ensure);
        }
        //Delay_Ms(600);
        LCD_Fill(0,200,240,220,BLACK);
    }
}

void Judge_FR(void)
{
    if (PDin(3))
    {
        press_FR();//刷指纹
    }
}
