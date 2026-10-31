/* PC 端测试：用模拟电平和时间验证消抖算法，不验证 C51 定时器或实际 GPIO。 */
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include "../key.h"

/* 测试直接改变变量模拟引脚抖动，不需要真实按键或延时等待。 */
static unsigned char pin1;
static unsigned char pin2;

static unsigned char ReadPin1(void)
{
    return pin1;
}

static unsigned char ReadPin2(void)
{
    return pin2;
}

static void TestBounceAndHold(void)
{
    Key key;

    pin1 = 1;
    Key_Init(&key, ReadPin1, 0, 20);
    Key_Update(&key, 0);
    assert(Key_TakePressed(&key) == 0);

    pin1 = 0;
    Key_Update(&key, 5);
    pin1 = 1;
    Key_Update(&key, 10);
    pin1 = 0;
    Key_Update(&key, 15);
    Key_Update(&key, 34);
    assert(Key_TakePressed(&key) == 0);
    Key_Update(&key, 35);
    assert(Key_TakePressed(&key) == 1);
    assert(Key_TakePressed(&key) == 0);
    Key_Update(&key, 1000);
    assert(Key_TakePressed(&key) == 0);

    pin1 = 1;
    Key_Update(&key, 1005);
    pin1 = 0;
    Key_Update(&key, 1010);
    pin1 = 1;
    Key_Update(&key, 1015);
    Key_Update(&key, 1034);
    assert(Key_TakeReleased(&key) == 0);
    Key_Update(&key, 1035);
    assert(Key_TakeReleased(&key) == 1);
    assert(Key_TakeReleased(&key) == 0);

    pin1 = 0;
    Key_Update(&key, 1040);
    Key_Update(&key, 1060);
    assert(Key_TakePressed(&key) == 1);
}

static void TestActiveHighAndIndependentKeys(void)
{
    Key key1;
    Key key2;

    pin1 = 1;
    pin2 = 0;
    Key_Init(&key1, ReadPin1, 0, 20);
    Key_Init(&key2, ReadPin2, 1, 10);

    pin1 = 0;
    pin2 = 1;
    Key_Update(&key1, 5);
    Key_Update(&key2, 5);
    Key_Update(&key1, 15);
    Key_Update(&key2, 15);
    assert(Key_TakePressed(&key1) == 0);
    assert(Key_TakePressed(&key2) == 1);
    Key_Update(&key1, 25);
    assert(Key_TakePressed(&key1) == 1);
    assert(Key_TakePressed(&key2) == 0);
}

static void TestClockWrap(void)
{
    Key key;

    pin1 = 1;
    Key_Init(&key, ReadPin1, 0, 20);
    pin1 = 0;
    Key_Update(&key, ULONG_MAX - 9UL);
    Key_Update(&key, 9UL);
    assert(Key_TakePressed(&key) == 0);
    Key_Update(&key, 10UL);
    assert(Key_TakePressed(&key) == 1);
}

static void TestInitiallyHeld(void)
{
    Key key;

    pin1 = 0;
    Key_Init(&key, ReadPin1, 0, 20);
    Key_Update(&key, 100);
    assert(Key_TakePressed(&key) == 0);
    pin1 = 1;
    Key_Update(&key, 105);
    Key_Update(&key, 125);
    assert(Key_TakeReleased(&key) == 1);
    pin1 = 0;
    Key_Update(&key, 130);
    Key_Update(&key, 150);
    assert(Key_TakePressed(&key) == 1);
}

static void TestUnconfirmedPulse(void)
{
    Key key;

    pin1 = 1;
    Key_Init(&key, ReadPin1, 0, 20);
    pin1 = 0;
    Key_Update(&key, 5);
    pin1 = 1;
    Key_Update(&key, 10);
    Key_Update(&key, 100);
    assert(Key_TakePressed(&key) == 0);
    assert(Key_TakeReleased(&key) == 0);
}

int main(void)
{
    TestBounceAndHold();
    TestActiveHighAndIndependentKeys();
    TestClockWrap();
    TestInitiallyHeld();
    TestUnconfirmedPulse();
    puts("All key debounce tests passed.");
    return 0;
}
