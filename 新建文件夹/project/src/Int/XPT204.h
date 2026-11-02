#ifndef __XPT2046_H__
#define __XPT2046_H__

#define XPT2046_XP_8    0X9C
#define XPT2046_YP_8    0XDC
#define XPT2046_VBAT_8  0XAC
#define XPT2046_AUX_8   0XEC

#define XPT2046_XP_12   0X94
#define XPT2046_YP_12   0XD4
#define XPT2046_VBAT_12 0XA4
#define XPT2046_AUX_12  0XE4
unsigned int XPT2046_ReadAD(unsigned char Command);

#endif // !__XPT2046_H__
