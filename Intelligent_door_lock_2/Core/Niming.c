/*
 * Niming.c
 *
 *  Created on: 2022Äê6ÔÂ9ÈÕ
 *      Author: hp
 */

#include "Niming.h"
#include "debug.h"

void niming_uartsend_Onebyte(int data1)
{
    uint8_t data_to_send[20];
    uint8_t i = 0;
    uint8_t cnt = 0;
    uint8_t sum = 0;
    data_to_send[cnt++]=0xAA;
    data_to_send[cnt++]=0x05;
    data_to_send[cnt++]=0xAF;
    data_to_send[cnt++]=0xF1;
    data_to_send[cnt++]=0;

    data_to_send[cnt++] = BYTE1(data1); data_to_send[cnt++] = BYTE0(data1);

    data_to_send[4] = cnt-5;
    for(i=0;i<cnt;i++)
    {
    sum+=data_to_send[i];
    }
    data_to_send[cnt++] = sum;
    for(i = 0;i<cnt;i++)
    {
        USART_SendData(USART1, data_to_send[i]);
    }

}

void niming_uartsend_TwoByte(int data1,int data2)
{
    uint8_t data_to_send[20];
    uint8_t i = 0;
    uint8_t cnt = 0;
    uint8_t sum = 0;

    data_to_send[cnt++]=0xAA;
    data_to_send[cnt++]=0x05;
    data_to_send[cnt++]=0xAF;
    data_to_send[cnt++]=0xF1;
    data_to_send[cnt++]=0;

    data_to_send[cnt++] = BYTE1(data1); data_to_send[cnt++] = BYTE0(data1);
    data_to_send[cnt++] = BYTE1(data2); data_to_send[cnt++] = BYTE0(data2);

    data_to_send[4] = cnt-5;
    for(i=0;i<cnt;i++)
    {
        sum+=data_to_send[i];
    }
    data_to_send[cnt++] = sum;
    for(i = 0;i<cnt;i++)
    {
        USART_SendData(USART1, data_to_send[i]);
    }
}

void niming_uartsend_Three_Byte(int data1,int data2,int data3)
{
    uint8_t data_to_send[20];
    uint8_t i = 0;
    uint8_t cnt = 0;
    uint8_t sum = 0;

    data_to_send[cnt++]=0xAA;
    data_to_send[cnt++]=0x05;
    data_to_send[cnt++]=0xAF;
    data_to_send[cnt++]=0xF1;
    data_to_send[cnt++]=0;

    data_to_send[cnt++] = BYTE1(data1); data_to_send[cnt++] = BYTE0(data1);
    data_to_send[cnt++] = BYTE1(data2); data_to_send[cnt++] = BYTE0(data2);
    data_to_send[cnt++] = BYTE1(data3); data_to_send[cnt++] = BYTE0(data3);

    data_to_send[4] = cnt-5;
    for(i=0;i<cnt;i++)
    {
        sum+=data_to_send[i];
    }
    data_to_send[cnt++] = sum;
    for(i = 0;i<cnt;i++)
    {
        USART_SendData(USART1, data_to_send[i]);
    }
}

void niming_uartsend_Four_Byte(int data1,int data2,int data3,int data4)
{
    uint8_t data_to_send[20];
    uint8_t i = 0;
    uint8_t cnt = 0;
    uint8_t sum = 0;

    data_to_send[cnt++]=0xAA;
    data_to_send[cnt++]=0x05;
    data_to_send[cnt++]=0xAF;
    data_to_send[cnt++]=0xF1;
    data_to_send[cnt++]=0;

    data_to_send[cnt++] = BYTE1(data1); data_to_send[cnt++] = BYTE0(data1);
    data_to_send[cnt++] = BYTE1(data2); data_to_send[cnt++] = BYTE0(data2);
    data_to_send[cnt++] = BYTE1(data3); data_to_send[cnt++] = BYTE0(data3);
    data_to_send[cnt++] = BYTE1(data4); data_to_send[cnt++] = BYTE0(data4);

    data_to_send[4] = cnt-5;
    for(i=0;i<cnt;i++)
    {
        sum+=data_to_send[i];
    }
    data_to_send[cnt++] = sum;
    for(i = 0;i<cnt;i++)
    {
        USART_SendData(USART1, data_to_send[i]);
    }
}

void niming_uartsend_Five_Byte(int data1,int data2,int data3,int data4,int data5)
{
    uint8_t data_to_send[20];
    uint8_t i = 0;
    uint8_t cnt = 0;
    uint8_t sum = 0;

    data_to_send[cnt++]=0xAA;
    data_to_send[cnt++]=0x05;
    data_to_send[cnt++]=0xAF;
    data_to_send[cnt++]=0xF1;
    data_to_send[cnt++]=0;

    data_to_send[cnt++] = BYTE1(data1); data_to_send[cnt++] = BYTE0(data1);
    data_to_send[cnt++] = BYTE1(data2); data_to_send[cnt++] = BYTE0(data2);
    data_to_send[cnt++] = BYTE1(data3); data_to_send[cnt++] = BYTE0(data3);
    data_to_send[cnt++] = BYTE1(data4); data_to_send[cnt++] = BYTE0(data4);
    data_to_send[cnt++] = BYTE1(data5); data_to_send[cnt++] = BYTE0(data5);

    data_to_send[4] = cnt-5;
    for(i=0;i<cnt;i++)
    {
        sum+=data_to_send[i];
    }
    data_to_send[cnt++] = sum;
    for(i = 0;i<cnt;i++)
    {
        USART_SendData(USART1, data_to_send[i]);
    }
}

void niming_uartsend_Six_Byte(int data1,int data2,int data3,int data4,int data5,int data6)
{
    unsigned char data_to_send[20];
    unsigned char i = 0;
    unsigned char cnt = 0;
    unsigned char sum = 0;
    data_to_send[cnt++]=0xAA;
    data_to_send[cnt++]=0x05;
    data_to_send[cnt++]=0xAF;
    data_to_send[cnt++]=0xF1;
    data_to_send[cnt++]=0;

    data_to_send[cnt++] = BYTE1(data1); data_to_send[cnt++] = BYTE0(data1);
    data_to_send[cnt++] = BYTE1(data2); data_to_send[cnt++] = BYTE0(data2);
    data_to_send[cnt++] = BYTE1(data3); data_to_send[cnt++] = BYTE0(data3);
    data_to_send[cnt++] = BYTE1(data4); data_to_send[cnt++] = BYTE0(data4);
    data_to_send[cnt++] = BYTE1(data5); data_to_send[cnt++] = BYTE0(data5);
    data_to_send[cnt++] = BYTE1(data6); data_to_send[cnt++] = BYTE0(data6);

    data_to_send[4] = cnt-5;
    for(i=0;i<cnt;i++)
    {
        sum+=data_to_send[i];
    }
    data_to_send[cnt++] = sum;
    for(i = 0;i<cnt;i++)
    {
        USART_SendData(USART1, data_to_send[i]);
    }
}





