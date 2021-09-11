#include "Arduino.h"
#include "NixieTube.h"
int fllag=1;
int hh2=-1,hh1,mm2,mm1;
String comdata = "";
void GetFirstTime(){
    while (Serial.available() > 0)  
    {
        comdata += char(Serial.read());
        delay(2);
    }
  if (comdata.length()>0)
    {
      Serial.println(comdata);
      if(comdata[0]>='0'&&comdata[0]<='9'){
        Serial.println("Sure");
        fllag=2;
        hh2=(int)(comdata[0]-'0');
        hh1=(int)(comdata[1]-'0');
        mm2=(int)(comdata[3]-'0');
        mm1=(int)(comdata[4]-'0');
        //ShowTime((int)(comdata[0]-'0'),(int)(comdata[1]-'0'),(int)(comdata[3]-'0'),(int)(comdata[4]-'0'));
      }
       comdata = "";
    }
}
void setup() {
  Serial.begin(9600);
  Tubeinit();
  fllag=1;
  while(hh2==-1){
    GetFirstTime();
  }
  ROLL(hh2,hh1,mm2,mm1);
}

void GetTime(){
  //while(Serial.available()==0);
  while (Serial.available() > 0)  
    {
        comdata += char(Serial.read());
        delay(2);
    }
  if (comdata.length()>0)
    {
      Serial.println(comdata);
      if(comdata[0]>='0'&&comdata[0]<='9'){
        Serial.println("Sure");
        ShowTime((int)(comdata[0]-'0'),(int)(comdata[1]-'0'),(int)(comdata[3]-'0'),(int)(comdata[4]-'0'));
      }
       comdata = "";
    }
}


void loop() {
  //if (fllag==2)ROLL(hh2,hh1,mm2,mm1);fllag==0;
  GetTime();
  //delay(1000);
}
