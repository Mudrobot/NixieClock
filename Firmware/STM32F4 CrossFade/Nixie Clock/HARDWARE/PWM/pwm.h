#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/6/16
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
void TIM2_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d);
void TIM2_CH_Init(u32 a,u32 b,u32 c,u32 d);
void TIM2_CH1_Init(u32 mode);
void TIM2_CH2_Init(u32 mode);
void TIM2_CH3_Init(u32 mode);
void TIM2_CH4_Init(u32 mode);

void TIM3_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d);
void TIM3_CH_Init(u32 a,u32 b,u32 c,u32 d);
void TIM3_CH1_Init(u32 mode);
void TIM3_CH2_Init(u32 mode);
void TIM3_CH3_Init(u32 mode);
void TIM3_CH4_Init(u32 mode);

void TIM4_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d);
void TIM4_CH_Init(u32 a,u32 b,u32 c,u32 d);
void TIM4_CH1_Init(u32 mode);
void TIM4_CH2_Init(u32 mode);
void TIM4_CH3_Init(u32 mode);
void TIM4_CH4_Init(u32 mode);

void TIM5_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d);
void TIM5_CH_Init(u32 a,u32 b,u32 c,u32 d);
void TIM5_CH1_Init(u32 mode);
void TIM5_CH2_Init(u32 mode);
void TIM5_CH3_Init(u32 mode);
void TIM5_CH4_Init(u32 mode);

#endif
