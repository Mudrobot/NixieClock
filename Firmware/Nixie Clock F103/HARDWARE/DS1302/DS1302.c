#include"DS1302.h"
#include"gpio.h"
struct Timedata timedata;

#define DS1302_SEC_ADDR           0x80		//�����ݵ�ַ
#define DS1302_MIN_ADDR           0x82		//�����ݵ�ַ
#define DS1302_HOUR_ADDR          0x84		//ʱ���ݵ�ַ
#define DS1302_DAY_ADDR           0x86		//�����ݵ�ַ
#define DS1302_MONTH_ADDR         0x88		//�����ݵ�ַ
#define DS1302_WEEK_ADDR          0x8a		//�������ݵ�ַ
#define DS1302_YEAR_ADDR          0x8c		//�����ݵ�ַ
#define DS1302_CONTROL_ADDR       0x8e		//�������ݵ�ַ
#define DS1302_CHARGER_ADDR       0x90 		//��繦�ܵ�ַ			 
#define DS1302_CLKBURST_ADDR      0xbe
#define Delay HAL_Delay(10)
uint8_t time_buf[8] = {0x20,0x21,0x08,0x18,0x17,0x07,0x00,0x03};//��ʼʱ��2019��8��13��16��05��00�� ������
uint8_t readtime[15];//��ǰʱ��
uint8_t sec_buf=0;  //�뻺��
uint8_t sec_flag=0; //���־λ



void DS1302_WriteByte(uint8_t addr,uint8_t data) 
{
	uint8_t i;
    HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_RESET);//��ֹ���ݴ��� ��������������Ҫ
	//DS1302_RST=0; //��ֹ���ݴ��� ��������������Ҫ
    HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);//ȷ��д����ǰSCLKΪ�͵�ƽ
    Delay;
	//DS1302_CLK=0; //ȷ��д����ǰSCLKΪ�͵�ƽ
    HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_SET);	//����DS1302����
	//DS1302_RST=1;	//����DS1302����	
	OutputMode();
	addr=addr&0xFE;  //���λ���㣬�Ĵ���0λΪ0ʱд��Ϊ1ʱ��
	for(i=0;i<8;i++) //д��Ŀ���ַ��addr
	{
		if (addr&0x01) HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_SET);
		else HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_RESET);
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);//ʱ��������д������
        //DS1302_CLK=1; //ʱ��������д������
		//DS1302_CLK=0;
        Delay;
        HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);
		addr=addr>>1;
	}	
	for (i=0;i<8;i++) //д�����ݣ�data
	{
		if(data&0x01) HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_SET);
		else HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_RESET);
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);//ʱ��������д������
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);
		data = data >> 1;
	}
    Delay;
	HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);    // ��ʱ�ӵ�ƽ���ڸߵ�ƽ״̬ ��������֪״̬
	HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_RESET);	//ֹͣDS1302����
}


uint8_t DS1302_ReadByte(uint8_t addr) 
{
	uint8_t i,temp;	
    HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_RESET);//��ֹ���ݴ��� ��������������Ҫ
	//DS1302_RST=0; //��ֹ���ݴ��� ��������������Ҫ
    HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);//ȷ��д����ǰSCLKΪ�͵�ƽ
	//DS1302_CLK=0; //ȷ��д����ǰSCLKΪ�͵�ƽ
    Delay;
    HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_SET);	//����DS1302����
	//DS1302_RST=1;	//����DS1302����	
	OutputMode();
	//д��Ŀ���ַ��addr
	addr=addr|0x01; //���λ�øߣ��Ĵ���0λΪ0ʱд��Ϊ1ʱ��
	for(i=0;i<8;i++) 
	{
		if (addr&0x01) HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_SET);
		else HAL_GPIO_WritePin(DAT_GPIO_Port,DAT_Pin,GPIO_PIN_RESET);
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);//ʱ��������д������
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);
		addr = addr >> 1;
	}	
	//��DS1302�������ݣ�temp
	InputMode();
	for(i=0;i<8;i++)
	{
		temp=temp>>1;
		if (HAL_GPIO_ReadPin(DAT_GPIO_Port,DAT_Pin)==SET) temp|=0x80;
		else temp&=0x7F;
        Delay;
        HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);//ʱ��������д������
        Delay;
		HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_RESET);
	}	
    Delay;
    HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin, GPIO_PIN_SET);//��ʱ�ӵ�ƽ������֪״̬
	HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_RESET);//ֹͣDS1302����
	return temp;
}


void DS1302_WriteTime() 
{
	DS1302_WriteByte(DS1302_CONTROL_ADDR,0x00);       //�ر�д���� 
	DS1302_WriteByte(DS1302_SEC_ADDR,0x80);           //��ͣʱ�� 
	//DS1302_WriteByte(DS1302_CHARGER_ADDR,0xa9);     //������ 
	DS1302_WriteByte(DS1302_YEAR_ADDR,time_buf[1]);   //�� 
	DS1302_WriteByte(DS1302_MONTH_ADDR,time_buf[2]);  //�� 
	DS1302_WriteByte(DS1302_DAY_ADDR,time_buf[3]);    //�� 
	DS1302_WriteByte(DS1302_HOUR_ADDR,time_buf[4]);   //ʱ 
	DS1302_WriteByte(DS1302_MIN_ADDR,time_buf[5]);    //��
	DS1302_WriteByte(DS1302_SEC_ADDR,time_buf[6]);    //��
	DS1302_WriteByte(DS1302_WEEK_ADDR,time_buf[7]);	  //�� 
	DS1302_WriteByte(DS1302_CHARGER_ADDR,0xA5);//�򿪳�繦�� ѡ��2K�����緽ʽ
	DS1302_WriteByte(DS1302_CONTROL_ADDR,0x80);//��д����     
}

void DS1302_ReadTime(void)  
{
	time_buf[1]=DS1302_ReadByte(DS1302_YEAR_ADDR);          //�� 
	time_buf[2]=DS1302_ReadByte(DS1302_MONTH_ADDR);         //�� 
	time_buf[3]=DS1302_ReadByte(DS1302_DAY_ADDR);           //�� 
	time_buf[4]=DS1302_ReadByte(DS1302_HOUR_ADDR);          //ʱ 
	time_buf[5]=DS1302_ReadByte(DS1302_MIN_ADDR)&0x7f;      //�� 
	time_buf[6]=(DS1302_ReadByte(DS1302_SEC_ADDR))&0x7f;    //�룬������ĵ�7λ�����ⳬ��59
	time_buf[7]=DS1302_ReadByte(DS1302_WEEK_ADDR);          //�� 	
}

void DS1302_GetTime()
{ 
    DS1302_ReadTime(); //��ȡʱ��
    timedata.year=(time_buf[0]>>4)*1000+(time_buf[0]&0x0F)*100+(time_buf[1]>>4)*10+(time_buf[1]&0x0F); //�������
    timedata.month=(time_buf[2]>>4)*10+(time_buf[2]&0x0F);  //�����·�
    timedata.day=(time_buf[3]>>4)*10+(time_buf[3]&0x0F);    //��������
    timedata.hour=(time_buf[4]>>4)*10+(time_buf[4]&0x0F);   //����Сʱ
    timedata.minute=(time_buf[5]>>4)*10+(time_buf[5]&0x0F); //�������
    timedata.second=(time_buf[6]>>4)*10+(time_buf[6]&0x0F); //��������
    timedata.week=(time_buf[7]&0x0F);                       //��������
  //printf("ʱ��:%d-%d-%d %d:%d:%d %d \n",TimeData.year,TimeData.month,TimeData.day,TimeData.hour,TimeData.minute,TimeData.second,TimeData.week);																												
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
