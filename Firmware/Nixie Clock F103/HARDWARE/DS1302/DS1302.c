#include"DS1302.h"
#include"gpio.h"
struct Timedata timedata;

#define DS1302_SEC_ADDR           0x80		//秒数据地址
#define DS1302_MIN_ADDR           0x82		//分数据地址
#define DS1302_HOUR_ADDR          0x84		//时数据地址
#define DS1302_DAY_ADDR           0x86		//日数据地址
#define DS1302_MONTH_ADDR         0x88		//月数据地址
#define DS1302_WEEK_ADDR          0x8a		//星期数据地址
#define DS1302_YEAR_ADDR          0x8c		//年数据地址
#define DS1302_CONTROL_ADDR       0x8e		//控制数据地址
#define DS1302_CHARGER_ADDR       0x90 		//充电功能地址			 
#define DS1302_CLKBURST_ADDR      0xbe
#define Delay HAL_Delay(10)
uint8_t time_buf[8] = {0x20,0x21,0x08,0x18,0x17,0x07,0x00,0x03};//初始时间2019年8月13号16点05分00秒 星期五
uint8_t readtime[15];//当前时间
uint8_t sec_buf=0;  //秒缓存
uint8_t sec_flag=0; //秒标志位



void DS1302_WriteByte(uint8_t addr,uint8_t data) 
{
	uint8_t i;
    HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_RESET);//禁止数据传输 ！！！这条很重要
	//DS1302_RST=0; //禁止数据传输 ！！！这条很重要
    HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);//确保写数据前SCLK为低电平
    Delay;
	//DS1302_CLK=0; //确保写数据前SCLK为低电平
    HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_SET);	//启动DS1302总线
	//DS1302_RST=1;	//启动DS1302总线	
	OutputMode();
	addr=addr&0xFE;  //最低位置零，寄存器0位为0时写，为1时读
	for(i=0;i<8;i++) //写入目标地址：addr
	{
		if (addr&0x01) HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_SET);
		else HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_RESET);
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);//时钟上升沿写入数据
        //DS1302_CLK=1; //时钟上升沿写入数据
		//DS1302_CLK=0;
        Delay;
        HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);
		addr=addr>>1;
	}	
	for (i=0;i<8;i++) //写入数据：data
	{
		if(data&0x01) HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_SET);
		else HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_RESET);
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);//时钟上升沿写入数据
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);
		data = data >> 1;
	}
    Delay;
	HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);    // 将时钟电平置于高电平状态 ，处于已知状态
	HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_RESET);	//停止DS1302总线
}


uint8_t DS1302_ReadByte(uint8_t addr) 
{
	uint8_t i,temp;	
    HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_RESET);//禁止数据传输 ！！！这条很重要
	//DS1302_RST=0; //禁止数据传输 ！！！这条很重要
    HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);//确保写数据前SCLK为低电平
	//DS1302_CLK=0; //确保写数据前SCLK为低电平
    Delay;
    HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_SET);	//启动DS1302总线
	//DS1302_RST=1;	//启动DS1302总线	
	OutputMode();
	//写入目标地址：addr
	addr=addr|0x01; //最低位置高，寄存器0位为0时写，为1时读
	for(i=0;i<8;i++) 
	{
		if (addr&0x01) HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_SET);
		else HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_RESET);
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);//时钟上升沿写入数据
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);
		addr = addr >> 1;
	}	
	//从DS1302读出数据：temp
	InputMode();
	for(i=0;i<8;i++)
	{
		temp=temp>>1;
		if (HAL_GPIO_ReadPin(DAT_GPIO_Port,DAT_Pin)==SET) temp|=0x80;
		else temp&=0x7F;
        Delay;
        HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);//时钟上升沿写入数据
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);
	}	
    Delay;
    HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);//将时钟电平置于已知状态
	HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_RESET);//停止DS1302总线
	return temp;
}


void DS1302_WriteTime() 
{
	DS1302_WriteByte(DS1302_CONTROL_ADDR,0x00);       //关闭写保护 
	DS1302_WriteByte(DS1302_SEC_ADDR,0x80);           //暂停时钟 
	//DS1302_WriteByte(DS1302_CHARGER_ADDR,0xa9);     //涓流充电 
	DS1302_WriteByte(DS1302_YEAR_ADDR,time_buf[1]);   //年 
	DS1302_WriteByte(DS1302_MONTH_ADDR,time_buf[2]);  //月 
	DS1302_WriteByte(DS1302_DAY_ADDR,time_buf[3]);    //日 
	DS1302_WriteByte(DS1302_HOUR_ADDR,time_buf[4]);   //时 
	DS1302_WriteByte(DS1302_MIN_ADDR,time_buf[5]);    //分
	DS1302_WriteByte(DS1302_SEC_ADDR,time_buf[6]);    //秒
	DS1302_WriteByte(DS1302_WEEK_ADDR,time_buf[7]);	  //周 
	DS1302_WriteByte(DS1302_CHARGER_ADDR,0xA5);//打开充电功能 选择2K电阻充电方式
	DS1302_WriteByte(DS1302_CONTROL_ADDR,0x80);//打开写保护     
}

void DS1302_ReadTime(void)  
{
	time_buf[1]=DS1302_ReadByte(DS1302_YEAR_ADDR);          //年 
	time_buf[2]=DS1302_ReadByte(DS1302_MONTH_ADDR);         //月 
	time_buf[3]=DS1302_ReadByte(DS1302_DAY_ADDR);           //日 
	time_buf[4]=DS1302_ReadByte(DS1302_HOUR_ADDR);          //时 
	time_buf[5]=DS1302_ReadByte(DS1302_MIN_ADDR)&0x7f;      //分 
	time_buf[6]=(DS1302_ReadByte(DS1302_SEC_ADDR))&0x7f;    //秒，屏蔽秒的第7位，避免超出59
	time_buf[7]=DS1302_ReadByte(DS1302_WEEK_ADDR);          //周 	
}

void DS1302_GetTime()
{ 
    DS1302_ReadTime(); //读取时间
    timedata.year=(time_buf[0]>>4)*1000+(time_buf[0]&0x0F)*100+(time_buf[1]>>4)*10+(time_buf[1]&0x0F); //计算年份
    timedata.month=(time_buf[2]>>4)*10+(time_buf[2]&0x0F);  //计算月份
    timedata.day=(time_buf[3]>>4)*10+(time_buf[3]&0x0F);    //计算日期
    timedata.hour=(time_buf[4]>>4)*10+(time_buf[4]&0x0F);   //计算小时
    timedata.minute=(time_buf[5]>>4)*10+(time_buf[5]&0x0F); //计算分钟
    timedata.second=(time_buf[6]>>4)*10+(time_buf[6]&0x0F); //计算秒钟
    timedata.week=(time_buf[7]&0x0F);                       //计算星期
  //printf("时间:%d-%d-%d %d:%d:%d %d \n",TimeData.year,TimeData.month,TimeData.day,TimeData.hour,TimeData.minute,TimeData.second,TimeData.week);																												
}
void OutputMode(){
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DAT_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(DAT_GPIO_Port, &GPIO_InitStruct);
}
void InputMode(){
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DAT_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DAT_GPIO_Port, &GPIO_InitStruct);
}
