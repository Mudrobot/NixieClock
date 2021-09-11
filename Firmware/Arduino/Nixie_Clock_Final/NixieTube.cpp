#include "Arduino.h"
#include "NixieTube.h"
#define mytim 100
int M1A=2,M1B=3,M1C=4,M1D=5;
int M2A=6,M2B=7,M2C=8,M2D=9;
int H1A=11,H1B=12,H1C=13;
int h=-1,m=-1;
#define H1D A0
#define H2A A1
#define H2B A2
#define H2C A3
#define H2D A4
void Tubeinit(){
    pinMode(M1A,OUTPUT);digitalWrite(M1A,HIGH);
    pinMode(M1B,OUTPUT);digitalWrite(M1B,HIGH);
    pinMode(M1C,OUTPUT);digitalWrite(M1C,HIGH);
    pinMode(M1D,OUTPUT);digitalWrite(M1D,HIGH);
    pinMode(M2A,OUTPUT);digitalWrite(M2A,HIGH);
    pinMode(M2B,OUTPUT);digitalWrite(M2B,HIGH);
    pinMode(M2C,OUTPUT);digitalWrite(M2C,HIGH);
    pinMode(M2D,OUTPUT);digitalWrite(M2D,HIGH);
    pinMode(H1A,OUTPUT);digitalWrite(H1A,HIGH);
    pinMode(H1B,OUTPUT);digitalWrite(H1B,HIGH);
    pinMode(H1C,OUTPUT);digitalWrite(H1C,HIGH);
    pinMode(H1D,OUTPUT);digitalWrite(H1D,HIGH);
    pinMode(H2A,OUTPUT);digitalWrite(H2A,HIGH);
    pinMode(H2B,OUTPUT);digitalWrite(H2B,HIGH);
    pinMode(H2C,OUTPUT);digitalWrite(H2C,HIGH);
    pinMode(H2D,OUTPUT);digitalWrite(H2D,HIGH);
}
void M1_0(){
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,LOW);
  digitalWrite(M1C,LOW);
  digitalWrite(M1D,LOW);
}
void M1_1(){
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,LOW);
  digitalWrite(M1C,LOW);
  digitalWrite(M1D,LOW);
}
void M1_2(){
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,HIGH);
  digitalWrite(M1C,LOW);
  digitalWrite(M1D,LOW);
}
void M1_3(){
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,HIGH);
  digitalWrite(M1C,LOW);
  digitalWrite(M1D,LOW);
}
void M1_4(){
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,LOW);
  digitalWrite(M1C,HIGH);
  digitalWrite(M1D,LOW);
}
void M1_5(){
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,LOW);
  digitalWrite(M1C,HIGH);
  digitalWrite(M1D,LOW);
}
void M1_6(){
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,HIGH);
  digitalWrite(M1C,HIGH);
  digitalWrite(M1D,LOW);
}
void M1_7(){
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,HIGH);
  digitalWrite(M1C,HIGH);
  digitalWrite(M1D,LOW);
}
void M1_8(){
  digitalWrite(M1A,LOW);
  digitalWrite(M1B,LOW);
  digitalWrite(M1C,LOW);
  digitalWrite(M1D,HIGH);
}
void M1_9(){
  digitalWrite(M1A,HIGH);
  digitalWrite(M1B,LOW);
  digitalWrite(M1C,LOW);
  digitalWrite(M1D,HIGH);
}
void M2_0(){
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,LOW);
  digitalWrite(M2C,LOW);
  digitalWrite(M2D,LOW);
}
void M2_1(){
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,LOW);
  digitalWrite(M2C,LOW);
  digitalWrite(M2D,LOW);
}
void M2_2(){
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,HIGH);
  digitalWrite(M2C,LOW);
  digitalWrite(M2D,LOW);
}
void M2_3(){
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,HIGH);
  digitalWrite(M2C,LOW);
  digitalWrite(M2D,LOW);
}
void M2_4(){
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,LOW);
  digitalWrite(M2C,HIGH);
  digitalWrite(M2D,LOW);
}
void M2_5(){
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,LOW);
  digitalWrite(M2C,HIGH);
  digitalWrite(M2D,LOW);
}
void M2_6(){
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,HIGH);
  digitalWrite(M2C,HIGH);
  digitalWrite(M2D,LOW);
}
void M2_7(){
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,HIGH);
  digitalWrite(M2C,HIGH);
  digitalWrite(M2D,LOW);
}
void M2_8(){
  digitalWrite(M2A,LOW);
  digitalWrite(M2B,LOW);
  digitalWrite(M2C,LOW);
  digitalWrite(M2D,HIGH);
}
void M2_9(){
  digitalWrite(M2A,HIGH);
  digitalWrite(M2B,LOW);
  digitalWrite(M2C,LOW);
  digitalWrite(M2D,HIGH);
}
void H1_0(){
  digitalWrite(H1A,LOW);
  digitalWrite(H1B,LOW);
  digitalWrite(H1C,LOW);
  digitalWrite(H1D,LOW);
}
void H1_1(){
  digitalWrite(H1A,HIGH);
  digitalWrite(H1B,LOW);
  digitalWrite(H1C,LOW);
  digitalWrite(H1D,LOW);
}
void H1_2(){
  digitalWrite(H1A,LOW);
  digitalWrite(H1B,HIGH);
  digitalWrite(H1C,LOW);
  digitalWrite(H1D,LOW);
}
void H1_3(){
  digitalWrite(H1A,HIGH);
  digitalWrite(H1B,HIGH);
  digitalWrite(H1C,LOW);
  digitalWrite(H1D,LOW);
}
void H1_4(){
  digitalWrite(H1A,LOW);
  digitalWrite(H1B,LOW);
  digitalWrite(H1C,HIGH);
  digitalWrite(H1D,LOW);
}
void H1_5(){
  digitalWrite(H1A,HIGH);
  digitalWrite(H1B,LOW);
  digitalWrite(H1C,HIGH);
  digitalWrite(H1D,LOW);
}
void H1_6(){
  digitalWrite(H1A,LOW);
  digitalWrite(H1B,HIGH);
  digitalWrite(H1C,HIGH);
  digitalWrite(H1D,LOW);
}
void H1_7(){
  digitalWrite(H1A,HIGH);
  digitalWrite(H1B,HIGH);
  digitalWrite(H1C,HIGH);
  digitalWrite(H1D,LOW);
}
void H1_8(){
  digitalWrite(H1A,LOW);
  digitalWrite(H1B,LOW);
  digitalWrite(H1C,LOW);
  digitalWrite(H1D,HIGH);
}
void H1_9(){
  digitalWrite(H1A,HIGH);
  digitalWrite(H1B,LOW);
  digitalWrite(H1C,LOW);
  digitalWrite(H1D,HIGH);
}
void H2_0(){
  digitalWrite(H2A,LOW);
  digitalWrite(H2B,LOW);
  digitalWrite(H2C,LOW);
  digitalWrite(H2D,LOW);
}
void H2_1(){
  digitalWrite(H2A,HIGH);
  digitalWrite(H2B,LOW);
  digitalWrite(H2C,LOW);
  digitalWrite(H2D,LOW);
}
void H2_2(){
  digitalWrite(H2A,LOW);
  digitalWrite(H2B,HIGH);
  digitalWrite(H2C,LOW);
  digitalWrite(H2D,LOW);
}
void H2_3(){
  digitalWrite(H2A,HIGH);
  digitalWrite(H2B,HIGH);
  digitalWrite(H2C,LOW);
  digitalWrite(H2D,LOW);
}
void H2_4(){
  digitalWrite(H2A,LOW);
  digitalWrite(H2B,LOW);
  digitalWrite(H2C,HIGH);
  digitalWrite(H2D,LOW);
}
void H2_5(){
  digitalWrite(H2A,HIGH);
  digitalWrite(H2B,LOW);
  digitalWrite(H2C,HIGH);
  digitalWrite(H2D,LOW);
}
void H2_6(){
  digitalWrite(H2A,LOW);
  digitalWrite(H2B,HIGH);
  digitalWrite(H2C,HIGH);
  digitalWrite(H2D,LOW);
}
void H2_7(){
  digitalWrite(H2A,HIGH);
  digitalWrite(H2B,HIGH);
  digitalWrite(H2C,HIGH);
  digitalWrite(H2D,LOW);
}
void H2_8(){
  digitalWrite(H2A,LOW);
  digitalWrite(H2B,LOW);
  digitalWrite(H2C,LOW);
  digitalWrite(H2D,HIGH);
}
void H2_9(){
  digitalWrite(H2A,HIGH);
  digitalWrite(H2B,LOW);
  digitalWrite(H2C,LOW);
  digitalWrite(H2D,HIGH);
}
void Test(){
    M1_0();M2_0();H1_0();H2_0(); delay(1000);
    M1_1();M2_1();H1_1();H2_1(); delay(1000);
    M1_2();M2_2();H1_2();H2_2(); delay(1000);
    M1_3();M2_3();H1_3();H2_3(); delay(1000);
    M1_4();M2_4();H1_4();H2_4(); delay(1000);
    M1_5();M2_5();H1_5();H2_5(); delay(1000);
    M1_6();M2_6();H1_6();H2_6(); delay(1000);
    M1_7();M2_7();H1_7();H2_7(); delay(1000);
    M1_8();M2_8();H1_8();H2_8(); delay(1000);
    M1_9();M2_9();H1_9();H2_9(); delay(1000);
}
void M1_Show(int x){
    if(x==0) M1_0();if(x==1) M1_1();
    if(x==2) M1_2();if(x==3) M1_3();
    if(x==4) M1_4();if(x==5) M1_5();
    if(x==6) M1_6();if(x==7) M1_7();
    if(x==8) M1_8();if(x==9) M1_9();
}
void M2_Show(int x){
    if(x==0) M2_0();if(x==1) M2_1();
    if(x==2) M2_2();if(x==3) M2_3();
    if(x==4) M2_4();if(x==5) M2_5();
    if(x==6) M2_6();if(x==7) M2_7();
    if(x==8) M2_8();if(x==9) M2_9();
}
void H1_Show(int x){
    if(x==0) H1_0();if(x==1) H1_1();
    if(x==2) H1_2();if(x==3) H1_3();
    if(x==4) H1_4();if(x==5) H1_5();
    if(x==6) H1_6();if(x==7) H1_7();
    if(x==8) H1_8();if(x==9) H1_9();
}
void H2_Show(int x){
    if(x==0) H2_0();if(x==1) H2_1();
    if(x==2) H2_2();if(x==3) H2_3();
    if(x==4) H2_4();if(x==5) H2_5();
    if(x==6) H2_6();if(x==7) H2_7();
    if(x==8) H2_8();if(x==9) H2_9();
}
void ShowTime(int H2,int H1,int M2,int M1){
  M1_Show(M1);M2_Show(M2);H1_Show(H1);H2_Show(H2);
}
void ROLL(int h2,int h1,int m2,int m1){
  for(int ii=1;ii<=4;++ii){
      for(int i=0;i<=9;++i){
        M1_Show(i);M2_Show(i);H1_Show(i);H2_Show(i);delay(mytim);
      }
  }
  int flag=0;
  for(int i=0;i<=9;++i){
      if(flag==0){
        M1_Show(i);M2_Show(i);H1_Show(i);H2_Show(i);delay(mytim);
      }
      else{
        M1_Show(i);M2_Show(i);H1_Show(i);delay(mytim);
      }
      if(i==h2)flag=1;
  }
  flag=0;
  for(int i=0;i<=9;++i){
      if(flag==0){
        M1_Show(i);M2_Show(i);H1_Show(i);delay(mytim);
      }
      else{
        M1_Show(i);M2_Show(i);delay(mytim);
      }
      if(i==h1)flag=1;
  }
  flag=0;
  for(int i=0;i<=9;++i){
      if(flag==0){
        M1_Show(i);M2_Show(i);delay(mytim);
      }
      else{
        M1_Show(i);delay(mytim);
      }
      if(i==m2)flag=1;
  }
  flag==0;
  for(int i=0;i<=9;++i){
      if(flag==0){
        M1_Show(i);delay(mytim);
      }
      else{
        return;
      }
      if(i==m1)flag=1;
  }
}
