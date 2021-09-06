#include "pwm.h"
#include "led.h"
#include "usart.h"
 
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//��ʱ��PWM ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/4
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
void TIM2_CH1_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM2, DISABLE);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM2,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM2, ENABLE);
}
void TIM2_CH2_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM2, DISABLE);
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM2,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM2, ENABLE);
}
void TIM2_CH3_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM2, DISABLE);
    TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM2,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM2, ENABLE);
}
void TIM2_CH4_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM2, DISABLE);
    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM2,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM2, ENABLE);
}
//TIM2 4·pwm�ź�ģʽ����
//a,b,c,d�ֱ�����CH1��CH4��ģʽ
void TIM2_CH_Init(u32 a,u32 b,u32 c,u32 d){
    TIM2_CH1_Init(a);
    TIM2_CH2_Init(b);
    TIM2_CH3_Init(c);
    TIM2_CH4_Init(d);
}
//TIM2 PWM���ֳ�ʼ�� (��ʼ����ʱ�����)
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
//PA5����TIM2_CH1
//PB3����TIM2_CH2
//PB10����TIM2_CH3
//PB11����TIM2_CH4
void TIM2_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d)
{		 					 
	//�˲������ֶ��޸�IO������
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  	//TIM2ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTAʱ��	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//ʹ��PORTAʱ��
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource5,GPIO_AF_TIM2); //GPIOA6����Ϊ��ʱ��3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource3,GPIO_AF_TIM2); //GPIOA7����Ϊ��ʱ��3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_TIM2); //GPIOB0����Ϊ��ʱ��3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource11,GPIO_AF_TIM2); //GPIOB1����Ϊ��ʱ��3
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;           //GPIOA6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PA6
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;           //GPIOA7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PA7
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;           //GPIOB0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PB0
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;           //GPIOB1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PB1
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);//��ʼ����ʱ��3
	
	//��ʼ��TIM2 Channel1,2,3,4 PWMģʽ	 
    TIM2_CH_Init(1,1,1,1);									  
}  


//----------------------------------------------------------------------------

void TIM3_CH1_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM3, DISABLE);
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM3,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM3, ENABLE);
}
void TIM3_CH2_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM3, DISABLE);
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM3,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM3, ENABLE);
}
void TIM3_CH3_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM3, DISABLE);
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM3,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM3, ENABLE);
}
void TIM3_CH4_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM3, DISABLE);
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM3,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM3, ENABLE);
}
//TIM3 4·pwm�ź�ģʽ����
//a,b,c,d�ֱ�����CH1��CH4��ģʽ
void TIM3_CH_Init(u32 a,u32 b,u32 c,u32 d){
    TIM3_CH1_Init(a);
    TIM3_CH2_Init(b);
    TIM3_CH3_Init(c);
    TIM3_CH4_Init(d);
}
//TIM3 PWM���ֳ�ʼ�� (��ʼ����ʱ�����)
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
//PA6����TIM3_CH1
//PA7����TIM3_CH2
//PB0����TIM3_CH3
//PB1����TIM3_CH4
void TIM3_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d)
{		 					 
	//�˲������ֶ��޸�IO������
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  	//TIM3ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTAʱ��	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//ʹ��PORTAʱ��
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM3); //GPIOA6����Ϊ��ʱ��3
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_TIM3); //GPIOA7����Ϊ��ʱ��3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource0,GPIO_AF_TIM3); //GPIOB0����Ϊ��ʱ��3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource1,GPIO_AF_TIM3); //GPIOB1����Ϊ��ʱ��3
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;           //GPIOA6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PA6
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;           //GPIOA7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PA7
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;           //GPIOB0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PB0
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;           //GPIOB1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PB1
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);//��ʼ����ʱ��3
	
	//��ʼ��TIM3 Channel1,2,3,4 PWMģʽ	 
    TIM3_CH_Init(1,1,1,1);									  
}  

//----------------------------------------------------------------------------



void TIM4_CH1_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM4, DISABLE);
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM4,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM4, ENABLE);
}
void TIM4_CH2_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM4, DISABLE);
    TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM4,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM4, ENABLE);
}
void TIM4_CH3_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM4, DISABLE);
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM4,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM4, ENABLE);
}
void TIM4_CH4_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM4, DISABLE);
    TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM4,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM4, ENABLE);
}
//TIM4 4·pwm�ź�ģʽ����
//a,b,c,d�ֱ�����CH1��CH4��ģʽ
void TIM4_CH_Init(u32 a,u32 b,u32 c,u32 d){
    TIM4_CH1_Init(a);
    TIM4_CH2_Init(b);
    TIM4_CH3_Init(c);
    TIM4_CH4_Init(d);
}

//TIM4 PWM���ֳ�ʼ�� (��ʼ����ʱ�����)
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
//PB6����TIM4_CH1
//PB7����TIM4_CH2
//PB8����TIM4_CH3
//PB9����TIM4_CH4
void TIM4_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d)
{		 					 
	//�˲������ֶ��޸�IO������
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  	//TIM4ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//ʹ��PORTDʱ��	
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_TIM4); //GPIOD12����Ϊ��ʱ��4
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_TIM4); //GPIOD13����Ϊ��ʱ��4
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_TIM4); //GPIOD14����Ϊ��ʱ��4
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource9,GPIO_AF_TIM4); //GPIOD15����Ϊ��ʱ��4
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;           //GPIOD12
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PD12
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;           //GPIOD13
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PD13
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;           //GPIOD14
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PD14
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;           //GPIOD15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //��ʼ��PD15
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStructure);//��ʼ����ʱ��4
	
	//��ʼ��TIM4 Channel1,2,3,4 PWMģʽ	 
    TIM4_CH_Init(1,1,1,1);									  
}  


//----------------------------------------------------------------------------



void TIM5_CH1_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM5, DISABLE);
    TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM5,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC1Init(TIM5, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM5, ENABLE);
}
void TIM5_CH2_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM5, DISABLE);
    TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM5,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC2Init(TIM5, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM5, ENABLE);
}
void TIM5_CH3_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM5, DISABLE);
    TIM_OC3PreloadConfig(TIM5, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM5,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC3Init(TIM5, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC3PreloadConfig(TIM5, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM5, ENABLE);
}
void TIM5_CH4_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM5, DISABLE);
    TIM_OC4PreloadConfig(TIM5, TIM_OCPreload_Disable);  //ʧ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM5,DISABLE);//ARPEʧ�� //�����仰д�Ͼ����� 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OC4Init(TIM5, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
    TIM_OC4PreloadConfig(TIM5, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPEʹ�� //�����仰д�Ͼ�����
    TIM_Cmd(TIM5, ENABLE);
}
//TIM5 4·pwm�ź�ģʽ����
//a,b,c,d�ֱ�����CH1��CH4��ģʽ
void TIM5_CH_Init(u32 a,u32 b,u32 c,u32 d){
    TIM5_CH1_Init(a);
    TIM5_CH2_Init(b);
    TIM5_CH3_Init(c);
    TIM5_CH4_Init(d);
}

//TIM5 PWM���ֳ�ʼ�� (��ʼ����ʱ�����)
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
//PA0����TIM5_CH1
//PA1����TIM5_CH2
//PA2����TIM5_CH3
//PA3����TIM5_CH4
void TIM5_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d)
{		 					 
	//�˲������ֶ��޸�IO������
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  	//TIM5ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTAʱ��	
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM5); //GPIOA0����Ϊ��ʱ��5
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM5); //GPIOA1����Ϊ��ʱ��5
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_TIM5); //GPIOA2����Ϊ��ʱ��5
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_TIM5); //GPIOA3����Ϊ��ʱ��5
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;           //GPIOA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PA0
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;           //GPIOA1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PA1
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;           //GPIOA2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PA2
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;           //GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //����
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PA3
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);//��ʼ����ʱ��5
	
	//��ʼ��TIM5 Channel1,2,3,4 PWMģʽ	 
    TIM5_CH_Init(1,1,1,1);									  
} 

//----------------------------------------------------------------------------


