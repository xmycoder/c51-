#ifndef KEY_DEBOUNCE_H
#define KEY_DEBOUNCE_H

/* 函数指针类型：使用者提供读取函数，返回引脚实际电平 0 或 1，库不依赖具体芯片。 */
typedef unsigned char (*KeyReadPin)(void);

/* 每个按键使用独立对象；引脚输入模式和上拉由使用者配置。 */
typedef struct
{
    KeyReadPin read_pin;             /* 保存读取函数，后续通过它获取当前引脚电平。 */
    unsigned int debounce_ms;        /* 新电平需持续稳定的毫秒数，例如 20。 */
    unsigned long last_change_ms;    /* 最近一次采样电平变化的时间，不是按下确认时间。 */
    unsigned char active_level;      /* 按下时的电平：接地按键通常为 0。 */
    unsigned char raw_level;         /* 当前候选电平，可能仍处于机械抖动中。 */
    unsigned char stable_level;      /* 消抖后确认的电平，业务逻辑以它为准。 */
    unsigned char pressed_event;     /* 待消费的按下事件；同类未消费事件会合并，不计次数。 */
    unsigned char released_event;    /* 待消费的松开事件，不是当前是否松开的状态。 */
} Key;

/* 初始化对象，记录开机电平；开机时已按住不会自动产生一次按下事件。 */
void Key_Init(Key *key, KeyReadPin read_pin,
              unsigned char active_level, unsigned int debounce_ms);
/* 在主循环中定期调用，建议采样间隔不超过 5ms；now_ms 是持续递增、允许回绕的毫秒计数。 */
void Key_Update(Key *key, unsigned long now_ms);
/* 取出并清除按下事件：返回 1 表示发生过一次按下，不表示按键一直被按住。 */
unsigned char Key_TakePressed(Key *key);
/* 取出并清除松开事件；Update 和 Take 应在同一执行上下文中调用，避免并发访问。 */
unsigned char Key_TakeReleased(Key *key);

#endif
