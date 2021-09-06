#ifndef __DS1302_H__
#define __DS1302_H__
#include "main.h"

struct Timedata{
    uint16_t year;
    uint8_t month,day,hour,minute,second,week;
};
extern struct Timedata timedata;

void DS1302_WriteByte(uint8_t addr,uint8_t data);
uint8_t DS1302_ReadByte(uint8_t addr);
void DS1302_WriteTime(void);
void DS1302_ReadTime(void);
void DS1302_GetTime(void);
void OutputMode(void);
void InputMode(void);
#endif
