#include "pwm.h"
#include "led.h"
#include "usart.h"
 
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//定时器PWM 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/4
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 
void TIM2_CH1_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM2, DISABLE);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM2,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM2, ENABLE);
}
void TIM2_CH2_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM2, DISABLE);
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM2,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM2, ENABLE);
}
void TIM2_CH3_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM2, DISABLE);
    TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM2,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM2, ENABLE);
}
void TIM2_CH4_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM2, DISABLE);
    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM2,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM2,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM2, ENABLE);
}
//TIM2 4路pwm信号模式设置
//a,b,c,d分别代表从CH1到CH4的模式
void TIM2_CH_Init(u32 a,u32 b,u32 c,u32 d){
    TIM2_CH1_Init(a);
    TIM2_CH2_Init(b);
    TIM2_CH3_Init(c);
    TIM2_CH4_Init(d);
}
//TIM2 PWM部分初始化 (初始化的时候调用)
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
//PA5——TIM2_CH1
//PB3——TIM2_CH2
//PB10——TIM2_CH3
//PB11——TIM2_CH4
void TIM2_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d)
{		 					 
	//此部分需手动修改IO口设置
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  	//TIM2时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//使能PORTA时钟	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//使能PORTA时钟
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource5,GPIO_AF_TIM2); //GPIOA6复用为定时器3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource3,GPIO_AF_TIM2); //GPIOA7复用为定时器3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_TIM2); //GPIOB0复用为定时器3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource11,GPIO_AF_TIM2); //GPIOB1复用为定时器3
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;           //GPIOA6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //初始化PA6
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;           //GPIOA7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //初始化PA7
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;           //GPIOB0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //初始化PB0
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;           //GPIOB1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //初始化PB1
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);//初始化定时器3
	
	//初始化TIM2 Channel1,2,3,4 PWM模式	 
    TIM2_CH_Init(1,1,1,1);									  
}  


//----------------------------------------------------------------------------

void TIM3_CH1_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM3, DISABLE);
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM3,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM3, ENABLE);
}
void TIM3_CH2_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM3, DISABLE);
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM3,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM3, ENABLE);
}
void TIM3_CH3_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM3, DISABLE);
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM3,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM3, ENABLE);
}
void TIM3_CH4_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM3, DISABLE);
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM3,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM3,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM3, ENABLE);
}
//TIM3 4路pwm信号模式设置
//a,b,c,d分别代表从CH1到CH4的模式
void TIM3_CH_Init(u32 a,u32 b,u32 c,u32 d){
    TIM3_CH1_Init(a);
    TIM3_CH2_Init(b);
    TIM3_CH3_Init(c);
    TIM3_CH4_Init(d);
}
//TIM3 PWM部分初始化 (初始化的时候调用)
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
//PA6——TIM3_CH1
//PA7——TIM3_CH2
//PB0——TIM3_CH3
//PB1——TIM3_CH4
void TIM3_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d)
{		 					 
	//此部分需手动修改IO口设置
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  	//TIM3时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//使能PORTA时钟	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//使能PORTA时钟
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM3); //GPIOA6复用为定时器3
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_TIM3); //GPIOA7复用为定时器3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource0,GPIO_AF_TIM3); //GPIOB0复用为定时器3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource1,GPIO_AF_TIM3); //GPIOB1复用为定时器3
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;           //GPIOA6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //初始化PA6
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;           //GPIOA7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //初始化PA7
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;           //GPIOB0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //初始化PB0
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;           //GPIOB1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //初始化PB1
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);//初始化定时器3
	
	//初始化TIM3 Channel1,2,3,4 PWM模式	 
    TIM3_CH_Init(1,1,1,1);									  
}  

//----------------------------------------------------------------------------



void TIM4_CH1_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM4, DISABLE);
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM4,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM4, ENABLE);
}
void TIM4_CH2_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM4, DISABLE);
    TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM4,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM4, ENABLE);
}
void TIM4_CH3_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM4, DISABLE);
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM4,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM4, ENABLE);
}
void TIM4_CH4_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM4, DISABLE);
    TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM4,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM4,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM4, ENABLE);
}
//TIM4 4路pwm信号模式设置
//a,b,c,d分别代表从CH1到CH4的模式
void TIM4_CH_Init(u32 a,u32 b,u32 c,u32 d){
    TIM4_CH1_Init(a);
    TIM4_CH2_Init(b);
    TIM4_CH3_Init(c);
    TIM4_CH4_Init(d);
}

//TIM4 PWM部分初始化 (初始化的时候调用)
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
//PB6——TIM4_CH1
//PB7——TIM4_CH2
//PB8——TIM4_CH3
//PB9——TIM4_CH4
void TIM4_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d)
{		 					 
	//此部分需手动修改IO口设置
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);  	//TIM4时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//使能PORTD时钟	
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_TIM4); //GPIOD12复用为定时器4
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_TIM4); //GPIOD13复用为定时器4
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_TIM4); //GPIOD14复用为定时器4
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource9,GPIO_AF_TIM4); //GPIOD15复用为定时器4
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;           //GPIOD12
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //初始化PD12
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;           //GPIOD13
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //初始化PD13
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;           //GPIOD14
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //初始化PD14
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;           //GPIOD15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOB,&GPIO_InitStructure);              //初始化PD15
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStructure);//初始化定时器4
	
	//初始化TIM4 Channel1,2,3,4 PWM模式	 
    TIM4_CH_Init(1,1,1,1);									  
}  


//----------------------------------------------------------------------------



void TIM5_CH1_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM5, DISABLE);
    TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM5,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC1Init(TIM5, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM5, ENABLE);
}
void TIM5_CH2_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM5, DISABLE);
    TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM5,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC2Init(TIM5, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM5, ENABLE);
}
void TIM5_CH3_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM5, DISABLE);
    TIM_OC3PreloadConfig(TIM5, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM5,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC3Init(TIM5, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC3PreloadConfig(TIM5, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM5, ENABLE);
}
void TIM5_CH4_Init(u32 mode){
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    TIM_Cmd(TIM5, DISABLE);
    TIM_OC4PreloadConfig(TIM5, TIM_OCPreload_Disable);  //失能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM5,DISABLE);//ARPE失能 //这两句话写上就行了 
    if(mode==1) TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
    else TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OC4Init(TIM5, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
    TIM_OC4PreloadConfig(TIM5, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPE使能 //这两句话写上就行了
    TIM_Cmd(TIM5, ENABLE);
}
//TIM5 4路pwm信号模式设置
//a,b,c,d分别代表从CH1到CH4的模式
void TIM5_CH_Init(u32 a,u32 b,u32 c,u32 d){
    TIM5_CH1_Init(a);
    TIM5_CH2_Init(b);
    TIM5_CH3_Init(c);
    TIM5_CH4_Init(d);
}

//TIM5 PWM部分初始化 (初始化的时候调用)
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
//PA0——TIM5_CH1
//PA1——TIM5_CH2
//PA2——TIM5_CH3
//PA3——TIM5_CH4
void TIM5_PWM_Init(u32 arr,u32 psc,u32 a,u32 b,u32 c,u32 d)
{		 					 
	//此部分需手动修改IO口设置
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  	//TIM5时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//使能PORTA时钟	
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM5); //GPIOA0复用为定时器5
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM5); //GPIOA1复用为定时器5
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_TIM5); //GPIOA2复用为定时器5
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_TIM5); //GPIOA3复用为定时器5
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;           //GPIOA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //初始化PA0
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;           //GPIOA1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //初始化PA1
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;           //GPIOA2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //初始化PA2
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;           //GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;        //下拉
	GPIO_Init(GPIOA,&GPIO_InitStructure);              //初始化PA3
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);//初始化定时器5
	
	//初始化TIM5 Channel1,2,3,4 PWM模式	 
    TIM5_CH_Init(1,1,1,1);									  
} 

//----------------------------------------------------------------------------


