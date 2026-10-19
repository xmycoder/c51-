#include "Int_MatrixLED.h"
#include <STC89C5xRC.H>
#include "Com_util.h"
#define SRE P34
#define RCLK P35
#define SRCLK P36



static s_led_buff[8];
void Int_MatrixLED_Init()
{
}


void Int_MatrixLED_SetPic(u8 *pic)
{
    u8 i;
    for(i=0;i<8;i++){
        s_led_buff[i] = pic[i];
    }

}

void Int_MatrixLED_Refresh()
{
    u8 i;
    SRE = 1;
    SRCLK = 1;
    SRCLK = 0;
    SRE = 0;
    for(i=0;i<8;i++){
        // 展示下一行数据前关闭
        P0 = 0xff;
        RCLK = 1;
        RCLK = 0;

        // 当前想要展示的数据
        P0 = ~s_led_buff[i];
        SRCLK = 1;
        SRCLK = 0;
        Delayms(1);
        
    }
}
