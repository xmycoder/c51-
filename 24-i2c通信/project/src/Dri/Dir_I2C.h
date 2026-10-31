#ifndef __DIR_I2C_H__
#define __DIR_I2C_H__
void I2C_Start(void);
// 停止发送
void I2C_Stop(void);
// 发送一个字节
void I2C_SendByte(unsigned char Byte);
// 接收一个字节
unsigned char I2C_Receive_Byte(void);
// 发送应答
void I2C_SendAck(unsigned char AckBit);
// 接收应答
unsigned char I2C_ReceiveAck(void);
#endif // !
