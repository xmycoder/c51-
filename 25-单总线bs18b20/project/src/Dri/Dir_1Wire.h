#ifndef __DIR_1WIRE_H__
#define __DIR_1WIRE_H__

#define u8 unsigned char

// 定义初始化函数
// 1表示存在，0表示不存在
bit Dir_1Wire_Init();


// 写字节
void Dir_1Wire_WriteByte(u8 byte);

// 读字节
u8 Dire_1Wire_ReadByte();


#endif //
