/*
 * PWM.h
 *
 *  Created on: 2022Äê6ÔÂ26ÈÕ
 *      Author: hp
 */

#ifndef PWM_H_
#define PWM_H_



#define  ARR  199
#define  PSC  7199
#define TIM3_CH4 0x34
#define TIM3_CH3 0x33
#define TIM3_CH2 0x32
#define TIM3_CH1 0x31
#define TIM2_CH3 0x23
#define TIM2_CH4 0x24
#define TIM2_CH1 0x21



void Open_door(void);
void Close_door(void);

#endif /* PWM_H_ */
