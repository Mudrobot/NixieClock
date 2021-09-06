#include "NixieTube.h"
#include "gpio.h"
#include "main.h"
#include "DS1302.h"
#include "stdio.h"
#include "i2c.h"
#include "usart.h"
#define HIGH GPIO_PIN_SET
#define LOW GPIO_PIN_RESET
#define M1A M1A_GPIO_Port,M1A_Pin
#define M1B M1B_GPIO_Port,M1B_Pin
#define M1C M1C_GPIO_Port,M1C_Pin
#define M1D M1D_GPIO_Port,M1D_Pin

#define M2A M2A_GPIO_Port,M2A_Pin
#define M2B M2B_GPIO_Port,M2B_Pin
#define M2C M2C_GPIO_Port,M2C_Pin
#define M2D M2D_GPIO_Port,M2D_Pin

#define H1A H1A_GPIO_Port,H1A_Pin
#define H1B H1B_GPIO_Port,H1B_Pin
#define H1C H1C_GPIO_Port,H1C_Pin
#define H1D H1D_GPIO_Port,H1D_Pin

#define H2A H2A_GPIO_Port,H2A_Pin
#define H2B H2B_GPIO_Port,H2B_Pin
#define H2C H2C_GPIO_Port,H2C_Pin
#define H2D H2D_GPIO_Port,H2D_Pin
uint16_t h=0,m=0;
void M1_0(void){
    HAL_GPIO_WritePin(M1A,LOW);
    HAL_GPIO_WritePin(M1B,LOW);
    HAL_GPIO_WritePin(M1C,LOW);
    HAL_GPIO_WritePin(M1D,LOW);
}
void M1_1(void){
    HAL_GPIO_WritePin(M1A,HIGH);
    HAL_GPIO_WritePin(M1B,LOW);
    HAL_GPIO_WritePin(M1C,LOW);
    HAL_GPIO_WritePin(M1D,LOW);
}
void M1_2(void){
    HAL_GPIO_WritePin(M1A,LOW);
    HAL_GPIO_WritePin(M1B,HIGH);
    HAL_GPIO_WritePin(M1C,LOW);
    HAL_GPIO_WritePin(M1D,LOW);
}
void M1_3(void){
    HAL_GPIO_WritePin(M1A,HIGH);
    HAL_GPIO_WritePin(M1B,HIGH);
    HAL_GPIO_WritePin(M1C,LOW);
    HAL_GPIO_WritePin(M1D,LOW);
}    
void M1_4(void){
    HAL_GPIO_WritePin(M1A,LOW);
    HAL_GPIO_WritePin(M1B,LOW);
    HAL_GPIO_WritePin(M1C,HIGH);
    HAL_GPIO_WritePin(M1D,LOW);
}
void M1_5(void){
    HAL_GPIO_WritePin(M1A,HIGH);
    HAL_GPIO_WritePin(M1B,LOW);
    HAL_GPIO_WritePin(M1C,HIGH);
    HAL_GPIO_WritePin(M1D,LOW);
}
void M1_6(void){
    HAL_GPIO_WritePin(M1A,LOW);
    HAL_GPIO_WritePin(M1B,HIGH);
    HAL_GPIO_WritePin(M1C,HIGH);
    HAL_GPIO_WritePin(M1D,LOW); 
}
void M1_7(void){
    HAL_GPIO_WritePin(M1A,HIGH);
    HAL_GPIO_WritePin(M1B,HIGH);
    HAL_GPIO_WritePin(M1C,HIGH);
    HAL_GPIO_WritePin(M1D,LOW); 
}
void M1_8(void){
    HAL_GPIO_WritePin(M1A,LOW);
    HAL_GPIO_WritePin(M1B,LOW);
    HAL_GPIO_WritePin(M1C,LOW);
    HAL_GPIO_WritePin(M1D,HIGH); 
}
void M1_9(void){
    HAL_GPIO_WritePin(M1A,HIGH);
    HAL_GPIO_WritePin(M1B,LOW);
    HAL_GPIO_WritePin(M1C,LOW);
    HAL_GPIO_WritePin(M1D,HIGH); 
}


void M2_0(void){
    HAL_GPIO_WritePin(M2A,LOW);
    HAL_GPIO_WritePin(M2B,LOW);
    HAL_GPIO_WritePin(M2C,LOW);
    HAL_GPIO_WritePin(M2D,LOW);
}
void M2_1(void){
    HAL_GPIO_WritePin(M2A,HIGH);
    HAL_GPIO_WritePin(M2B,LOW);
    HAL_GPIO_WritePin(M2C,LOW);
    HAL_GPIO_WritePin(M2D,LOW);
}
void M2_2(void){
    HAL_GPIO_WritePin(M2A,LOW);
    HAL_GPIO_WritePin(M2B,HIGH);
    HAL_GPIO_WritePin(M2C,LOW);
    HAL_GPIO_WritePin(M2D,LOW);
}
void M2_3(void){
    HAL_GPIO_WritePin(M2A,HIGH);
    HAL_GPIO_WritePin(M2B,HIGH);
    HAL_GPIO_WritePin(M2C,LOW);
    HAL_GPIO_WritePin(M2D,LOW);
}    
void M2_4(void){
    HAL_GPIO_WritePin(M2A,LOW);
    HAL_GPIO_WritePin(M2B,LOW);
    HAL_GPIO_WritePin(M2C,HIGH);
    HAL_GPIO_WritePin(M2D,LOW);
}
void M2_5(void){
    HAL_GPIO_WritePin(M2A,HIGH);
    HAL_GPIO_WritePin(M2B,LOW);
    HAL_GPIO_WritePin(M2C,HIGH);
    HAL_GPIO_WritePin(M2D,LOW);
}
void M2_6(void){
    HAL_GPIO_WritePin(M2A,LOW);
    HAL_GPIO_WritePin(M2B,HIGH);
    HAL_GPIO_WritePin(M2C,HIGH);
    HAL_GPIO_WritePin(M2D,LOW); 
}
void M2_7(void){
    HAL_GPIO_WritePin(M2A,HIGH);
    HAL_GPIO_WritePin(M2B,HIGH);
    HAL_GPIO_WritePin(M2C,HIGH);
    HAL_GPIO_WritePin(M2D,LOW); 
}
void M2_8(void){
    HAL_GPIO_WritePin(M2A,LOW);
    HAL_GPIO_WritePin(M2B,LOW);
    HAL_GPIO_WritePin(M2C,LOW);
    HAL_GPIO_WritePin(M2D,HIGH); 
}
void M2_9(void){
    HAL_GPIO_WritePin(M2A,HIGH);
    HAL_GPIO_WritePin(M2B,LOW);
    HAL_GPIO_WritePin(M2C,LOW);
    HAL_GPIO_WritePin(M2D,HIGH); 
}

void H1_0(void){
    HAL_GPIO_WritePin(H1A,LOW);
    HAL_GPIO_WritePin(H1B,LOW);
    HAL_GPIO_WritePin(H1C,LOW);
    HAL_GPIO_WritePin(H1D,LOW);
}
void H1_1(void){
    HAL_GPIO_WritePin(H1A,HIGH);
    HAL_GPIO_WritePin(H1B,LOW);
    HAL_GPIO_WritePin(H1C,LOW);
    HAL_GPIO_WritePin(H1D,LOW);
}
void H1_2(void){
    HAL_GPIO_WritePin(H1A,LOW);
    HAL_GPIO_WritePin(H1B,HIGH);
    HAL_GPIO_WritePin(H1C,LOW);
    HAL_GPIO_WritePin(H1D,LOW);
}
void H1_3(void){
    HAL_GPIO_WritePin(H1A,HIGH);
    HAL_GPIO_WritePin(H1B,HIGH);
    HAL_GPIO_WritePin(H1C,LOW);
    HAL_GPIO_WritePin(H1D,LOW);
}    
void H1_4(void){
    HAL_GPIO_WritePin(H1A,LOW);
    HAL_GPIO_WritePin(H1B,LOW);
    HAL_GPIO_WritePin(H1C,HIGH);
    HAL_GPIO_WritePin(H1D,LOW);
}
void H1_5(void){
    HAL_GPIO_WritePin(H1A,HIGH);
    HAL_GPIO_WritePin(H1B,LOW);
    HAL_GPIO_WritePin(H1C,HIGH);
    HAL_GPIO_WritePin(H1D,LOW);
}
void H1_6(void){
    HAL_GPIO_WritePin(H1A,LOW);
    HAL_GPIO_WritePin(H1B,HIGH);
    HAL_GPIO_WritePin(H1C,HIGH);
    HAL_GPIO_WritePin(H1D,LOW); 
}
void H1_7(void){
    HAL_GPIO_WritePin(H1A,HIGH);
    HAL_GPIO_WritePin(H1B,HIGH);
    HAL_GPIO_WritePin(H1C,HIGH);
    HAL_GPIO_WritePin(H1D,LOW); 
}
void H1_8(void){
    HAL_GPIO_WritePin(H1A,LOW);
    HAL_GPIO_WritePin(H1B,LOW);
    HAL_GPIO_WritePin(H1C,LOW);
    HAL_GPIO_WritePin(H1D,HIGH); 
}
void H1_9(void){
    HAL_GPIO_WritePin(H1A,HIGH);
    HAL_GPIO_WritePin(H1B,LOW);
    HAL_GPIO_WritePin(H1C,LOW);
    HAL_GPIO_WritePin(H1D,HIGH); 
}

void H2_0(void){
    HAL_GPIO_WritePin(H2A,LOW);
    HAL_GPIO_WritePin(H2B,LOW);
    HAL_GPIO_WritePin(H2C,LOW);
    HAL_GPIO_WritePin(H2D,LOW);
}
void H2_1(void){
    HAL_GPIO_WritePin(H2A,HIGH);
    HAL_GPIO_WritePin(H2B,LOW);
    HAL_GPIO_WritePin(H2C,LOW);
    HAL_GPIO_WritePin(H2D,LOW);
}
void H2_2(void){
    HAL_GPIO_WritePin(H2A,LOW);
    HAL_GPIO_WritePin(H2B,HIGH);
    HAL_GPIO_WritePin(H2C,LOW);
    HAL_GPIO_WritePin(H2D,LOW);
}
void H2_3(void){
    HAL_GPIO_WritePin(H2A,HIGH);
    HAL_GPIO_WritePin(H2B,HIGH);
    HAL_GPIO_WritePin(H2C,LOW);
    HAL_GPIO_WritePin(H2D,LOW);
}    
void H2_4(void){
    HAL_GPIO_WritePin(H2A,LOW);
    HAL_GPIO_WritePin(H2B,LOW);
    HAL_GPIO_WritePin(H2C,HIGH);
    HAL_GPIO_WritePin(H2D,LOW);
}
void H2_5(void){
    HAL_GPIO_WritePin(H2A,HIGH);
    HAL_GPIO_WritePin(H2B,LOW);
    HAL_GPIO_WritePin(H2C,HIGH);
    HAL_GPIO_WritePin(H2D,LOW);
}
void H2_6(void){
    HAL_GPIO_WritePin(H2A,LOW);
    HAL_GPIO_WritePin(H2B,HIGH);
    HAL_GPIO_WritePin(H2C,HIGH);
    HAL_GPIO_WritePin(H2D,LOW); 
}
void H2_7(void){
    HAL_GPIO_WritePin(H2A,HIGH);
    HAL_GPIO_WritePin(H2B,HIGH);
    HAL_GPIO_WritePin(H2C,HIGH);
    HAL_GPIO_WritePin(H2D,LOW); 
}
void H2_8(void){
    HAL_GPIO_WritePin(H2A,LOW);
    HAL_GPIO_WritePin(H2B,LOW);
    HAL_GPIO_WritePin(H2C,LOW);
    HAL_GPIO_WritePin(H2D,HIGH); 
}
void H2_9(void){
    HAL_GPIO_WritePin(H2A,HIGH);
    HAL_GPIO_WritePin(H2B,LOW);
    HAL_GPIO_WritePin(H2C,LOW);
    HAL_GPIO_WritePin(H2D,HIGH); 
}
void Test(void){
    M1_0();M2_0();H1_0();H2_0(); HAL_Delay(1000);
    M1_1();M2_1();H1_1();H2_1(); HAL_Delay(1000);
    M1_2();M2_2();H1_2();H2_2(); HAL_Delay(1000);
    M1_3();M2_3();H1_3();H2_3(); HAL_Delay(1000);
    M1_4();M2_4();H1_4();H2_4(); HAL_Delay(1000);
    M1_5();M2_5();H1_5();H2_5(); HAL_Delay(1000);
    M1_6();M2_6();H1_6();H2_6(); HAL_Delay(1000);
    M1_7();M2_7();H1_7();H2_7(); HAL_Delay(1000);
    M1_8();M2_8();H1_8();H2_8(); HAL_Delay(1000);
    M1_9();M2_9();H1_9();H2_9(); HAL_Delay(1000);
}
void M1_Show(uint8_t x){
    if(x==0) M1_0();if(x==1) M1_1();
    if(x==2) M1_2();if(x==3) M1_3();
    if(x==4) M1_4();if(x==5) M1_5();
    if(x==6) M1_6();if(x==7) M1_7();
    if(x==8) M1_8();if(x==9) M1_9();
}
void M2_Show(uint8_t x){
    if(x==0) M2_0();if(x==1) M2_1();
    if(x==2) M2_2();if(x==3) M2_3();
    if(x==4) M2_4();if(x==5) M2_5();
    if(x==6) M2_6();if(x==7) M2_7();
    if(x==8) M2_8();if(x==9) M2_9();
}
void H1_Show(uint8_t x){
    if(x==0) H1_0();if(x==1) H1_1();
    if(x==2) H1_2();if(x==3) H1_3();
    if(x==4) H1_4();if(x==5) H1_5();
    if(x==6) H1_6();if(x==7) H1_7();
    if(x==8) H1_8();if(x==9) H1_9();
}
void H2_Show(uint8_t x){
    if(x==0) H2_0();if(x==1) H2_1();
    if(x==2) H2_2();if(x==3) H2_3();
    if(x==4) H2_4();if(x==5) H2_5();
    if(x==6) H2_6();if(x==7) H2_7();
    if(x==8) H2_8();if(x==9) H2_9();
}
void ShowTime(uint8_t nh,uint8_t nm){
    //DS1302_GetTime();
    //printf("%d\r\n",timedata.year);
    //printf("%d:%d:%d\r\n",timedata.year,timedata.month,timedata.day);
    //printf("%d:%d:%d\r\n",timedata.hour,timedata.minute,timedata.second);
    if(nh!=h||nm!=m){
        if(nm!=(m+1)%60)return;
        h=nh;m=nm;
        if(m==0)H1_Show(h%10),H2_Show(h/10);
        M1_Show(m%10);M2_Show(m/10);
        
    }
}
