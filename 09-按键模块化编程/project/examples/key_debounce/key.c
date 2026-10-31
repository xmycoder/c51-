#include "key.h"

void Key_Init(Key *key, KeyReadPin read_pin,
              unsigned char active_level, unsigned int debounce_ms)
{
    key->read_pin = read_pin;
    key->debounce_ms = debounce_ms;
    key->last_change_ms = 0;
    key->active_level = active_level;
    /* 以初始化时的电平为基准，避免把开机时已按住误报成一次新按下。 */
    key->raw_level = read_pin();
    key->stable_level = key->raw_level;
    key->pressed_event = 0;
    key->released_event = 0;
}

void Key_Update(Key *key, unsigned long now_ms)
{
    unsigned char level;

    /* 调用使用者传入的函数；库无需知道引脚是 P3.1 还是其他 GPIO。 */
    level = key->read_pin();
    if (level != key->raw_level)
    {
        key->raw_level = level;
        /* 每次抖动都重新计时，要求最后一次变化之后连续稳定满消抖时间。 */
        key->last_change_ms = now_ms;
    }

    /* 候选电平与已确认电平不同才处理，保持按住不会重复生成按下事件。 */
    /* 无符号时间差可跨计数回绕；消抖判断必须在一个完整计数周期内完成。 */
    if (key->raw_level != key->stable_level &&
        (unsigned long)(now_ms - key->last_change_ms) >= key->debounce_ms)
    {
        key->stable_level = key->raw_level;
        /* 按下、松开共用同一套消抖逻辑，只按有效电平区分事件。 */
        if (key->stable_level == key->active_level)
        {
            key->pressed_event = 1;
        }
        else
        {
            key->released_event = 1;
        }
    }
}

unsigned char Key_TakePressed(Key *key)
{
    unsigned char event;

    /* 先保存再清零，主循环多次查询也只消费一次已确认的事件。 */
    event = key->pressed_event;
    key->pressed_event = 0;
    return event;
}

unsigned char Key_TakeReleased(Key *key)
{
    unsigned char event;

    /* 事件独立保存，即使读取前电平又改变，也不会立刻丢失此次松开通知。 */
    event = key->released_event;
    key->released_event = 0;
    return event;
}
