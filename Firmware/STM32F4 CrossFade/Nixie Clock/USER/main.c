#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#include "lcd.h"
#include "usmart.h"
#include "rtc.h"
#include "NixieTube.h"
#include "test.h"

//ALIENTEK 探索者STM32F407开发板 实验9
//PWM输出实验-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

int main(void)
{ 
	RTC_TimeTypeDef RTC_TimeStruct;
	RTC_DateTypeDef RTC_DateStruct;

	u8 tbuf[40];
	u8 t=0;
	//u16 pwmval=0;    
	//u8 dir=1;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	uart_init(115200);//初始化串口波特率为115200
 	
	//usmart_dev.init(84); 	//???USMART	
	
	LED_Init();					  //???LED
 	//LCD_Init();		
	
	My_RTC_Init();		 		//???RTC
	
	M1_Set();
	M2_Set();
  H1_Set();
  H2_Set();
 
	RTC_Set_WakeUp(RTC_WakeUpClock_CK_SPRE_16bits,0);	//配置WAKE UP中断,1秒钟中断一次
	/*
	POINT_COLOR=RED;
	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
	LCD_ShowString(30,70,200,16,16,"RTC TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2014/5/5");	
	*/
	
	  //ShowNumTest();
    //while(1);
    //时钟显示部分
    //--------------------------------------------------------------------------------------
    u8 min,hour,min1,min2,hour1,hour2;
    RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);
    min=RTC_TimeStruct.RTC_Minutes;
    hour=RTC_TimeStruct.RTC_Hours;
    min1=min%10;min2=min/10;hour1=hour%10;hour2=hour/10;
		printf("%d %d %d %d\r\n",hour2,hour1,min2,min1);
    ShowNum(hour2,hour1,min2,min1);//while(1);
    //-----------------------------
    while(1) 
	{		
		t++;
		if((t%10)==0)	//每100ms更新一次显示数据
		{
;
			RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);
			if(min!=RTC_TimeStruct.RTC_Minutes){
                min=RTC_TimeStruct.RTC_Minutes;
                hour=RTC_TimeStruct.RTC_Hours;
                min1=min%10;min2=min/10;hour1=hour%10;hour2=hour/10;
                ChangeNum(hour2,hour1,min2,min1);
            }
			//sprintf((char*)tbuf,"Time:%02d:%02d:%02d",RTC_TimeStruct.RTC_Hours,RTC_TimeStruct.RTC_Minutes,RTC_TimeStruct.RTC_Seconds); 
			//LCD_ShowString(30,140,210,16,16,tbuf);	
			//printf("%d\n",RTC_TimeStruct.RTC_Minutes);
			RTC_GetDate(RTC_Format_BIN, &RTC_DateStruct);
			
			sprintf((char*)tbuf,"Date:20%02d-%02d-%02d",RTC_DateStruct.RTC_Year,RTC_DateStruct.RTC_Month,RTC_DateStruct.RTC_Date); 
			LCD_ShowString(30,160,210,16,16,tbuf);	
			sprintf((char*)tbuf,"Week:%d",RTC_DateStruct.RTC_WeekDay); 
			LCD_ShowString(30,180,210,16,16,tbuf);
		} 
		if((t%20)==0)LED0=!LED0;	//每200ms,翻转一次LED0 
		delay_ms(10);
	}
    //--------------------------------------------------------------------------------------------------
    
}
