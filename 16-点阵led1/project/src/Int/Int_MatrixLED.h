#ifndef __INT_MATRIXLED_H__
#define __INT_MATRIXLED_H__
typedef unsigned char u8;

// 初始化led
void Int_MatrixLED_Init();

// 设置要显示的图像
void Int_MatrixLED_SetPic(u8 *pic);

//点阵刷新
void Int_MatrixLED_Refresh();


#endif // !1