#include "Arduino.h"
#include "NixieTube.h"
void setup() {
  Serial.begin(9600);
  Tubeinit();

}
String comdata = "";
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
  GetTime();
  //delay(1000);
}
