/*
 * Niming.h
 *
 *  Created on: 2022��6��9��
 *      Author: hp
 */

#ifndef NIMING_H_
#define NIMING_H_

#define BYTE0(dwTemp)       (*(char *)(&dwTemp))     //ȡ��int�ͱ����ĵ��ֽ�
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))   // ȡ�洢�ڴ˱�����һ�ڴ��ֽڵ����ݣ����ֽ�
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))

void niming_uartsend_Onebyte(int data1);
void niming_uartsend_TwoByte(int data1,int data2);
void niming_uartsend_Three_Byte(int data1,int data2,int data3);
void niming_uartsend_Four_Byte(int data1,int data2,int data3,int data4);
void niming_uartsend_Five_Byte(int data1,int data2,int data3,int data4,int data5);
void niming_uartsend_Six_Byte(int data1,int data2,int data3,int data4,int data5,int data6);

#endif /* NIMING_H_ */


