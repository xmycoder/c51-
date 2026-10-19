#include "Int_MatrixLED.h"
#include <STC89C5xRC.H>
void main()
{
    // 注意j24的跳线帽
    u8 pic[8] = {
        0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
    Int_MatrixLED_SetPic(pic);
    while (1)
    {
        Int_MatrixLED_Refresh();
    }
}