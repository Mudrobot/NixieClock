#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>
#include <DS1302.h>
#include <SoftwareSerial.h>
#include <WiFiUdp.h>

SoftwareSerial uart1(14,12);//RX=d5,TX=d6
DS1302 rtc(2, 0, 4); //对应DS1302的RST D4,DAT, D3,CLK D2
int h=-1,m=-1,flag=1;
const int keyPin=13;
const char *ssid     = "Mi 11_Mudrobot";
const char *password = "n1j2c3f4j5";
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp1.aliyun.com",60*60*8, 30*60*1000);
void initRTCTime(void)//初始化RTC时钟
{
  rtc.writeProtect(false); //关闭写保护
  rtc.halt(false); //清除时钟停止标志
  Time t(2021, 8, 19, 21, 00, 00,  Time::kThursday); //新建时间对象 最后参数位星期数据，周日为1，周一为2以此类推
  rtc.time(t);//向DS1302设置时间数据
}

void printTime()//打印时间数据
{
  Time tim = rtc.time(); //从DS1302获取时间数据
  char buf[50];
  snprintf(buf, sizeof(buf), "%02d:%02d",tim.hr, tim.min);
  Serial.println(buf);
  uart1.println(buf);
}

void setup() {
  Serial.begin(9600);
  uart1.begin(9600);
  uart1.listen();
  pinMode(keyPin,INPUT_PULLUP);
  pinMode(16,OUTPUT);digitalWrite(16,LOW);
  pinMode(15,OUTPUT);digitalWrite(15,LOW);//D8-->GND
  //新模块上电需要设置一次当前时间，
  //下载完成后需屏蔽此函数再次下载，否则每次上电都会初始化时间数据
  initRTCTime();

}
int judge(){
  boolean Value;
  Value=digitalRead(keyPin);
  if(Value==LOW){
    delay(30);
    if(Value==LOW) return 1;
  }
  return 0;
}
void modifyTime(){
  digitalWrite(16,HIGH);
  WiFi.begin(ssid, password);
  int cnt=0;
  while ( WiFi.status() != WL_CONNECTED &&cnt!=20) {
    delay ( 500 );
    Serial.print ( "." );
    cnt++;
  }
  if(WiFi.status()!=WL_CONNECTED) return;
  timeClient.begin();
  for(int i=1;i<=5;++i){
    timeClient.update();
    delay(1000);
  }
  timeClient.update();
  Time tim = rtc.time();
  rtc.writeProtect(false); //关闭写保护
  rtc.halt(false); //清除时钟停止标志
  tim.hr=timeClient.getHours();
  tim.min=timeClient.getMinutes();
  tim.sec=timeClient.getSeconds();
  rtc.time(tim);//向DS1302设置时间数据
  //Serial.println(timeClient.getFormattedTime());
  //Serial.println("OK!");
  digitalWrite(16,LOW);
}
String comdata="";
void loop() {
  /*Serial.println("OK");
  while (uart1.available() > 0)  
    {
        Serial.println("Copy");
        comdata += char(uart1.read());
        delay(2);
    }
   if (comdata.length()==4&&comdata=="GOT\n")
    {
      Serial.println("printtime");
       printTime();
       comdata = "";
    }*/
    if(judge()){
      Serial.println("ModifyTime");
      modifyTime();
    }
    else printTime();
    delay(1000);
}
