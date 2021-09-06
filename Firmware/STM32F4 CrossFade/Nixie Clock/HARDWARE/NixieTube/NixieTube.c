#include "sys.h"
#include "pwm.h"
#include "NixieTube.h"
#include "delay.h"
//TIM2
//默认不显示

void M1_Set(void){
    TIM2_PWM_Init(500-1,84-1,1,1,1,1);	//84M/84=1Mhz的计数频率,重装载值50，所以PWM频率为 1M/500=2Khz.     
    TIM_SetCompare1(TIM2,500);
    TIM_SetCompare2(TIM2,500);
    TIM_SetCompare3(TIM2,500);
    TIM_SetCompare4(TIM2,500);
}
void M1_Num0To1(u32 rev){
    if(rev==0){
        TIM2_CH_Init(1,1,1,1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
        }
    }
}
void M1_Num1To2(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);//SetMode
        TIM2_CH2_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
        }
    }
}
void M1_Num2To3(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
        }
    }
}
void M1_Num3To4(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH2_Init(2);//SetMode
        TIM2_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH2_Init(1);
        TIM2_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
        }
    }
}
void M1_Num4To5(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
        }
    }
}
void M1_Num5To6(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH2_Init(1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
        }
    }
}
void M1_Num6To7(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
        }
    }
}
void M1_Num7To8(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH2_Init(2);//SetMode
        TIM2_CH3_Init(2);
        TIM2_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH2_Init(1);
        TIM2_CH3_Init(1);
        TIM2_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M1_Num8To9(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
        }
    }
}
void M1_Num9To0(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}

void M1_Num0(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH2_Init(2);
        TIM2_CH3_Init(2);
        TIM2_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH2_Init(1);
        TIM2_CH3_Init(1);
        TIM2_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M1_Num1(u32 rev){
    if(rev==0){
        TIM2_CH2_Init(2);
        TIM2_CH3_Init(2);
        TIM2_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH2_Init(1);
        TIM2_CH3_Init(1);
        TIM2_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M1_Num2(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH3_Init(2);
        TIM2_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare3(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH3_Init(1);
        TIM2_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare3(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M1_Num3(u32 rev){
    if(rev==0){
        TIM2_CH3_Init(2);
        TIM2_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare3(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH3_Init(1);
        TIM2_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare3(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M1_Num4(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH2_Init(2);
        TIM2_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH2_Init(1);
        TIM2_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M1_Num5(u32 rev){
    if(rev==0){
        TIM2_CH2_Init(2);
        TIM2_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH2_Init(1);
        TIM2_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M1_Num6(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M1_Num7(u32 rev){
    if(rev==0){
        TIM2_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M1_Num8(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH2_Init(2);
        TIM2_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH2_Init(1);
        TIM2_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
        }
    }
}
void M1_Num9(u32 rev){
    if(rev==0){
        TIM2_CH2_Init(2);
        TIM2_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
        }
    }
    else{
        TIM2_CH2_Init(1);
        TIM2_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM2,i);
            TIM_SetCompare3(TIM2,i);
        }
    }
}
//---------------------------------------------------------------------------------------------------------
void M2_Set(void){
    TIM3_PWM_Init(500-1,84-1,1,1,1,1);	//84M/84=1Mhz的计数频率,重装载值50，所以PWM频率为 1M/500=2Khz.     
    TIM_SetCompare1(TIM3,500);
    TIM_SetCompare2(TIM3,500);
    TIM_SetCompare3(TIM3,500);
    TIM_SetCompare4(TIM3,500);
}
void M2_Num0To1(u32 rev){
    if(rev==0){
        TIM3_CH_Init(1,1,1,1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
        }
    }
}
void M2_Num1To2(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(2);//SetMode
        TIM3_CH2_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(1);
        TIM3_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
        }
    }
}
void M2_Num2To3(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
        }
    }
}
void M2_Num3To4(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(2);
        TIM3_CH2_Init(2);//SetMode
        TIM3_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(1);
        TIM3_CH2_Init(1);
        TIM3_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
        }
    }
}
void M2_Num4To5(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
        }
    }
}
void M2_Num5To6(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(2);
        TIM3_CH2_Init(1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(1);
        TIM3_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
        }
    }
}
void M2_Num6To7(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
        }
    }
}
void M2_Num7To8(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(2);
        TIM3_CH2_Init(2);//SetMode
        TIM3_CH3_Init(2);
        TIM3_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(1);
        TIM3_CH2_Init(1);
        TIM3_CH3_Init(1);
        TIM3_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
}
void M2_Num8To9(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
        }
    }
}
void M2_Num9To0(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(2);
        TIM3_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(1);
        TIM3_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
}

void M2_Num0(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(2);
        TIM3_CH2_Init(2);
        TIM3_CH3_Init(2);
        TIM3_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(1);
        TIM3_CH2_Init(1);
        TIM3_CH3_Init(1);
        TIM3_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
}
void M2_Num1(u32 rev){
    if(rev==0){
        TIM3_CH2_Init(2);
        TIM3_CH3_Init(2);
        TIM3_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
    else{
        TIM3_CH2_Init(1);
        TIM3_CH3_Init(1);
        TIM3_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
}
void M2_Num2(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM3_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM3_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
}
void M2_Num3(u32 rev){
    if(rev==0){
        TIM3_CH3_Init(2);
        TIM3_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
    else{
        TIM3_CH3_Init(1);
        TIM3_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
}
void M2_Num4(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(2);
        TIM3_CH2_Init(2);
        TIM3_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(1);
        TIM3_CH2_Init(1);
        TIM3_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
}
void M2_Num5(u32 rev){
    if(rev==0){
        TIM3_CH2_Init(2);
        TIM3_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
    else{
        TIM3_CH2_Init(1);
        TIM3_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
}
void M2_Num6(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(2);
        TIM3_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(1);
        TIM3_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare4(TIM3,i);
        }
    }
}
void M2_Num7(u32 rev){
    if(rev==0){
        TIM3_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare4(TIM3,i);
        }
    }
    else{
        TIM3_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare4(TIM3,i);
        }
    }
}
void M2_Num8(u32 rev){
    if(rev==0){
        TIM3_CH1_Init(2);
        TIM3_CH2_Init(2);
        TIM3_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
        }
    }
    else{
        TIM3_CH1_Init(1);
        TIM3_CH2_Init(1);
        TIM3_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
        }
    }
}
void M2_Num9(u32 rev){
    if(rev==0){
        TIM3_CH2_Init(2);
        TIM3_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
        }
    }
    else{
        TIM3_CH2_Init(1);
        TIM3_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
        }
    }
}

//---------------------------------------------------------------------------------------------------------
void H1_Set(void){
    TIM4_PWM_Init(500-1,84-1,1,1,1,1);	//84M/84=1Mhz的计数频率,重装载值50，所以PWM频率为 1M/500=2Khz.     
    TIM_SetCompare1(TIM4,500);
    TIM_SetCompare2(TIM4,500);
    TIM_SetCompare3(TIM4,500);
    TIM_SetCompare4(TIM4,500);
}
void H1_Num0To1(u32 rev){
    if(rev==0){
        TIM4_CH_Init(1,1,1,1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
        }
    }
}
void H1_Num1To2(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(2);//SetMode
        TIM4_CH2_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
        }
    }
}
void H1_Num2To3(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
        }
    }
}
void H1_Num3To4(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(2);//SetMode
        TIM4_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(1);
        TIM4_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
        }
    }
}
void H1_Num4To5(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
        }
    }
}
void H1_Num5To6(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
        }
    }
}
void H1_Num6To7(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
        }
    }
}
void H1_Num7To8(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(2);//SetMode
        TIM4_CH3_Init(2);
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(1);
        TIM4_CH3_Init(1);
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
}
void H1_Num8To9(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
        }
    }
}
void H1_Num9To0(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(2);
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(1);
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
}

void H1_Num0(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(2);
        TIM4_CH3_Init(2);
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(1);
        TIM4_CH3_Init(1);
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
}
void H1_Num1(u32 rev){
    if(rev==0){
        TIM4_CH2_Init(2);
        TIM4_CH3_Init(2);
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
    else{
        TIM4_CH2_Init(1);
        TIM4_CH3_Init(1);
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
}
void H1_Num2(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(2);
        TIM4_CH3_Init(2);
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(1);
        TIM4_CH3_Init(1);
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
}
void H1_Num3(u32 rev){
    if(rev==0){
        TIM4_CH3_Init(2);
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
    else{
        TIM4_CH3_Init(1);
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
}
void H1_Num4(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(2);
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(1);
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
}
void H1_Num5(u32 rev){
    if(rev==0){
        TIM4_CH2_Init(2);
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
    else{
        TIM4_CH2_Init(1);
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
}
void H1_Num6(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(2);
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(1);
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare4(TIM4,i);
        }
    }
}
void H1_Num7(u32 rev){
    if(rev==0){
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare4(TIM4,i);
        }
    }
    else{
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare4(TIM4,i);
        }
    }
}
void H1_Num8(u32 rev){
    if(rev==0){
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(2);
        TIM4_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
        }
    }
    else{
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(1);
        TIM4_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
        }
    }
}
void H1_Num9(u32 rev){
    if(rev==0){
        TIM4_CH2_Init(2);
        TIM4_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
        }
    }
    else{
        TIM4_CH2_Init(1);
        TIM4_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
        }
    }
}

//---------------------------------------------------------------------------------------------------------
void H2_Set(void){
    TIM5_PWM_Init(500-1,84-1,1,1,1,1);	//84M/84=1Mhz的计数频率,重装载值50，所以PWM频率为 1M/500=2Khz.     
    TIM_SetCompare1(TIM5,500);
    TIM_SetCompare2(TIM5,500);
    TIM_SetCompare3(TIM5,500);
    TIM_SetCompare4(TIM5,500);
}
void H2_Num0To1(u32 rev){
    if(rev==0){
        TIM5_CH_Init(1,1,1,1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
        }
    }
}
void H2_Num1To2(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(2);//SetMode
        TIM5_CH2_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(1);
        TIM5_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
        }
    }
}
void H2_Num2To3(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
        }
    }
}
void H2_Num3To4(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(2);
        TIM5_CH2_Init(2);//SetMode
        TIM5_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(1);
        TIM5_CH2_Init(1);
        TIM5_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
        }
    }
}
void H2_Num4To5(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
        }
    }
}
void H2_Num5To6(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(2);
        TIM5_CH2_Init(1);//SetMode
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(1);
        TIM5_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
        }
    }
}
void H2_Num6To7(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
        }
    }
}
void H2_Num7To8(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(2);
        TIM5_CH2_Init(2);//SetMode
        TIM5_CH3_Init(2);
        TIM5_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(1);
        TIM5_CH2_Init(1);
        TIM5_CH3_Init(1);
        TIM5_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
}
void H2_Num8To9(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
        }
    }
}
void H2_Num9To0(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(2);
        TIM5_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(1);
        TIM5_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
}

void H2_Num0(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(2);
        TIM5_CH2_Init(2);
        TIM5_CH3_Init(2);
        TIM5_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(1);
        TIM5_CH2_Init(1);
        TIM5_CH3_Init(1);
        TIM5_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
}
void H2_Num1(u32 rev){
    if(rev==0){
        TIM5_CH2_Init(2);
        TIM5_CH3_Init(2);
        TIM5_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
    else{
        TIM5_CH2_Init(1);
        TIM5_CH3_Init(1);
        TIM5_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
}
void H2_Num2(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(2);
        TIM5_CH3_Init(2);
        TIM5_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare3(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(1);
        TIM5_CH3_Init(1);
        TIM5_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare3(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
}
void H2_Num3(u32 rev){
    if(rev==0){
        TIM5_CH3_Init(2);
        TIM5_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare3(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
    else{
        TIM5_CH3_Init(1);
        TIM5_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare3(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
}
void H2_Num4(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(2);
        TIM5_CH2_Init(2);
        TIM5_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(1);
        TIM5_CH2_Init(1);
        TIM5_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
}
void H2_Num5(u32 rev){
    if(rev==0){
        TIM5_CH2_Init(2);
        TIM5_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
    else{
        TIM5_CH2_Init(1);
        TIM5_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
}
void H2_Num6(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(2);
        TIM5_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(1);
        TIM5_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare4(TIM5,i);
        }
    }
}
void H2_Num7(u32 rev){
    if(rev==0){
        TIM5_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare4(TIM5,i);
        }
    }
    else{
        TIM5_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare4(TIM5,i);
        }
    }
}
void H2_Num8(u32 rev){
    if(rev==0){
        TIM5_CH1_Init(2);
        TIM5_CH2_Init(2);
        TIM5_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
        }
    }
    else{
        TIM5_CH1_Init(1);
        TIM5_CH2_Init(1);
        TIM5_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
        }
    }
}
void H2_Num9(u32 rev){
    if(rev==0){
        TIM5_CH2_Init(2);
        TIM5_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
        }
    }
    else{
        TIM5_CH2_Init(1);
        TIM5_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare3(TIM5,i);
        }
    }
}
void ShowNum(u8 h2,u8 h1,u8 m2,u8 m1){
    if(h2==0)H2_Num0(0);
    if(h2==1)H2_Num1(0);
    if(h2==2)H2_Num2(0);
    if(h2==3)H2_Num3(0);
    if(h2==4)H2_Num4(0);
    if(h2==5)H2_Num5(0);
    if(h2==6)H2_Num6(0);
    if(h2==7)H2_Num7(0);
    if(h2==8)H2_Num8(0);
    if(h2==9)H2_Num9(0);
    
    if(h1==0)H1_Num0(0);
    if(h1==1)H1_Num1(0);
    if(h1==2)H1_Num2(0);
    if(h1==3)H1_Num3(0);
    if(h1==4)H1_Num4(0);
    if(h1==5)H1_Num5(0);
    if(h1==6)H1_Num6(0);
    if(h1==7)H1_Num7(0);
    if(h1==8)H1_Num8(0);
    if(h1==9)H1_Num9(0);

    if(m2==0)M2_Num0(0);
    if(m2==1)M2_Num1(0);
    if(m2==2)M2_Num2(0);
    if(m2==3)M2_Num3(0);
    if(m2==4)M2_Num4(0);
    if(m2==5)M2_Num5(0);
    if(m2==6)M2_Num6(0);
    if(m2==7)M2_Num7(0);
    if(m2==8)M2_Num8(0);
    if(m2==9)M2_Num9(0);

    if(m1==0)M1_Num0(0);
    if(m1==1)M1_Num1(0);
    if(m1==2)M1_Num2(0);
    if(m1==3)M1_Num3(0);
    if(m1==4)M1_Num4(0);
    if(m1==5)M1_Num5(0);
    if(m1==6)M1_Num6(0);
    if(m1==7)M1_Num7(0);
    if(m1==8)M1_Num8(0);
    if(m1==9)M1_Num9(0);
}
void M_09To10(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M_19To20(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH2_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M_29To30(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M_39To40(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH2_Init(2);
        TIM3_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH2_Init(1);
        TIM3_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare2(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M_49To50(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void M_59To00(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_00To01(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_01To02(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_02To03(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_03To04(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(2);
        TIM4_CH3_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(1);
        TIM4_CH3_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_04To05(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_05To06(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_06To07(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_07To08(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(2);
        TIM4_CH3_Init(2);
        TIM4_CH4_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(1);
        TIM4_CH3_Init(1);
        TIM4_CH4_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare3(TIM4,i);
            TIM_SetCompare4(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_08To09(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_09To10(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(2);
        TIM4_CH4_Init(2);
        TIM5_CH1_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare4(TIM4,i);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(1);
        TIM4_CH4_Init(1);
        TIM5_CH1_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare4(TIM4,i);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}

void H_19To20(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(2);
        TIM4_CH4_Init(2);
        TIM5_CH1_Init(2);
        TIM5_CH2_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare4(TIM4,i);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(1);
        TIM4_CH4_Init(1);
        TIM5_CH1_Init(1);
        TIM5_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare1(TIM5,i);
            TIM_SetCompare4(TIM4,i);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void H_23To00(u32 rev){
    if(rev==0){
        TIM2_CH1_Init(2);
        TIM2_CH4_Init(2);
        TIM3_CH1_Init(2);
        TIM3_CH3_Init(2);
        TIM4_CH1_Init(2);
        TIM4_CH2_Init(2);
        TIM5_CH2_Init(2);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
    else{
        TIM2_CH1_Init(1);
        TIM2_CH4_Init(1);
        TIM3_CH1_Init(1);
        TIM3_CH3_Init(1);
        TIM4_CH1_Init(1);
        TIM4_CH2_Init(1);
        TIM5_CH2_Init(1);
        for(u16 i=0;i<=500;++i){
            delay_ms(1);
            TIM_SetCompare2(TIM5,i);
            TIM_SetCompare2(TIM4,i);
            TIM_SetCompare1(TIM4,i);
            TIM_SetCompare1(TIM3,i);
            TIM_SetCompare3(TIM3,i);
            TIM_SetCompare1(TIM2,i);
            TIM_SetCompare4(TIM2,i);
        }
    }
}
void ChangeNum(u8 h2,u8 h1,u8 m2,u8 m1){
    if(m1!=0){
        if(m1==1) M1_Num0To1(0);
        if(m1==2) M1_Num1To2(0);
        if(m1==3) M1_Num2To3(0);
        if(m1==4) M1_Num3To4(0);
        if(m1==5) M1_Num4To5(0);
        if(m1==6) M1_Num5To6(0);
        if(m1==7) M1_Num6To7(0);
        if(m1==8) M1_Num7To8(0);
        if(m1==9) M1_Num8To9(0);
    }
    if(m1==0){
        if(m2!=0){
            if(m2==1) M_09To10(0);
            if(m2==2) M_19To20(0);
            if(m2==3) M_29To30(0);
            if(m2==4) M_39To40(0);
            if(m2==5) M_49To50(0);
        }
        else{
            if(h2==0){
                if(h1==0) H_23To00(0);
                if(h1==1) H_00To01(0);
                if(h1==2) H_01To02(0);
                if(h1==3) H_02To03(0);
                if(h1==4) H_03To04(0);
                if(h1==5) H_04To05(0);
                if(h1==6) H_05To06(0);
                if(h1==7) H_06To07(0);
                if(h1==8) H_07To08(0);
                if(h1==9) H_08To09(0);
            }
            if(h2==1){
                if(h1==0) H_09To10(0);
                if(h1==1) H_00To01(0);
                if(h1==2) H_01To02(0);
                if(h1==3) H_02To03(0);
                if(h1==4) H_03To04(0);
                if(h1==5) H_04To05(0);
                if(h1==6) H_05To06(0);
                if(h1==7) H_06To07(0);
                if(h1==8) H_07To08(0);
                if(h1==9) H_08To09(0);
            }
            if(h2==2){
                if(h1==0) H_19To20(0);
                if(h1==1) H_00To01(0);
                if(h1==2) H_01To02(0);
                if(h1==3) H_02To03(0);
            }
        }
    }
}

