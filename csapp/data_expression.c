#include "csapp.h"
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (size_t i = 0; i < len; i++)
    {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(x));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(x));
}

void pointer_len()
{
    int *p;
    char *q;
    typedef struct
    {
        int age;
        int high;
    } Student;
    Student *stu;
    // 64位系统上指针大小固定为8字节
    printf("int* len=%d,char* len=%d,Student * len=%d\n", sizeof(p), sizeof(q), sizeof(stu));
}

void byte_order()
{
    int x = 0x01234567;
    char *p = &x;
    // 67  45  23  1     低位存在低地址，高位存在高地址 表示机器是小端模式
    // 1  23  45  67     高位存在低地址，低位存在高地址 表示机器是大端模式
    for (size_t i = 0; i < sizeof(x); i++)
    {
        printf("[%x] %x ", p, *p);
        p++;
    }
    printf("\n");
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)val;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void test_ascii()
{
    //数字ascii码0x30~0x39
    show_bytes("0123456789", 10);
    //小写字母0x61~0x7a
    const char *s = "abcdefghijklmnopqrstuvwxyz";
    show_bytes(s, strlen(s));
    //大写字母0x41~0x5a
    const char *S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    show_bytes(S, strlen(S));
}

void test_bit_calculate()
{
    // 0x41=[0100 1011]
    unsigned char a = 0x4b;
    // 0x14=[0001 0111]
    unsigned char b = 0x17;
    // a&b=[0000 0011]
    printf("a&b=%.2x\n", a & b);
    // a|b=[0101 1111]
    printf("a|b=%.2x\n", a | b);
    // a^b=[0101 1100]
    printf("a^b=%.2x\n", a ^ b);

    //~a=[1011 0100]
    printf("~a=%.2x\n", ((unsigned char)(~a)));
    //~b=[1110 1000]
    printf("~b=%.2x\n", ((unsigned char)(~b)));
}

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void test_inplace_swap()
{
    int x = 1;
    int y = 2;
    inplace_swap(&x, &y);
    printf("x=%d,y=%d\n", x, y);
}

/**
 * 反转数组
 */
void reverse_array(int a[], int count)
{
    int first, last;
    for (first = 0, last = count - 1; first < last; first++, last--)
    {
        inplace_swap(&a[first], &a[last]);
    }
}

void test_reverse_array()
{
    int a[] = {1, 3, 2, 5, 4};
    reverse_array(a, sizeof(a) / sizeof(int));
    for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

/**
 * 位级运算和逻辑运算
 */
void diff_bit_logic()
{
    unsigned char x = 0x66;
    unsigned char y = 0x39;
    //逻辑运算的结果只有0或1
    printf("x&y=%.2x\n", ((unsigned char)(x & y)));
    printf("x|y=%.2x\n", ((unsigned char)(x | y)));
    printf("~x|~y=%.2x\n", ((unsigned char)(~x | ~y)));
    printf("x&!y=%.2x\n", ((unsigned char)(x & !y)));
    printf("x&&y=%.2x\n", ((unsigned char)(x && y)));
    printf("x||y=%.2x\n", ((unsigned char)(x || y)));
    printf("!x||!y=%.2x\n", ((unsigned char)(!x || !y)));
    printf("x&&~y=%.2x\n", ((unsigned char)(x && ~y)));

    //逻辑运算 &&从左到右的表达式有一个为0就停止计算结果为0
    //|| 从左到右的表达式有一个为1就停止计算结果为1
    int count = 0;
    0 && ++count;
    printf("count=%d\n", count);
    1 && ++count;
    printf("count=%d\n", count);
    0 || ++count;
    printf("count=%d\n", count);
    1 || ++count;
    printf("count=%d\n", count);
}

/**
 * 实现x==y
 */
int eq(int x, int y)
{
    return !(x ^ y);
}
void test_eq()
{
    printf("1==2 =%d\n", eq(1, 2));
    printf("2==2 =%d\n", eq(2, 2));
}

/**
 * 移位运算
 */
void move_bit()
{
    // x=[0110 0011] y=[1001 0101]
    unsigned char x = 0x63;
    unsigned char y = 0x95;
    //左移4位 [0011 1001] [0101 0000]
    printf("x<<4=%.2x,y<<4=%.2x\n", ((unsigned char)(x << 4)), ((unsigned char)(y << 4)));
    x = 0x63;
    y = 0x95;
    //右移4位[0000 0110] [0011 1001]
    printf("x>>4=%.2x,y>>4=%.2x\n", ((unsigned char)(x >> 4)), ((unsigned char)(y >> 4)));

    //有符号数只有算术右移(c只有算术右移=>每字节高位用符号位补齐)
    // a=[0110 0011] b=[1001 0101](-107的补码)
    int a = 0x63;
    int b = -107; //-128+16+4+1=-107
    //逻辑右移4位[0000 0110] [1111 1001]
    printf("a=%.2x,b=%.2x\n", ((unsigned char)a), ((unsigned char)b));
    printf("a>>4=%.2x,b>>4=%.2x\n", ((unsigned char)(a >> 4)), ((unsigned char)(b >> 4)));
}