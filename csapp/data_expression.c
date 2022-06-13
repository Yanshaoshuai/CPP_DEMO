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

    //有符号数只有算术右移(c只有算术右移=>高位用符号位补齐)
    // a=[0110 0011] b=[1001 0101](-107的补码)
    int a = 0x63;
    int b = -107; //-128+16+4+1=-107
    //逻辑右移4位[0000 0110] [1111 1001]
    printf("a=%.2x,b=%.2x\n", ((unsigned char)a), ((unsigned char)b));
    printf("a>>4=%.2x,b>>4=%.2x\n", ((unsigned char)(a >> 4)), ((unsigned char)(b >> 4)));
}

void type_convert()
{
    //相同长度整数 类型转换，底层位表示不变数值改变
    int x = -12345;
    unsigned y = x;
    printf("x=%d,y=%u\n", x, y);
    show_bytes((byte_pointer)&x, 4);
    show_bytes((byte_pointer)&y, 4);
    unsigned a = UINT_MAX;
    int b = a;
    printf("a=%u,b=%d\n", a, b);
    show_bytes((byte_pointer)&a, 4);
    show_bytes((byte_pointer)&b, 4);

    //不同长度整数 类型转换
    // 1.小转大 数值不变符号位填充
    //整数
    char c = 41;
    int ci = c;
    printf("c=");
    show_bytes((byte_pointer)&c, 1);
    printf("ci=");
    show_bytes((byte_pointer)&ci, 4);
    //负数
    char cn = -41;
    int cni = cn;
    printf("c=");
    show_bytes((byte_pointer)&cn, 1);
    printf("ci=");
    show_bytes((byte_pointer)&cni, 4);
    //大转小 截断高位，保留低位
    unsigned ux = 129;
    char cux = ux;
    int ix = -129;
    char cix = ix;
    printf("ux=");
    show_bytes((byte_pointer)&ux, 4);
    printf("cux=");
    show_bytes((byte_pointer)&cux, 1);
    printf("ix=");
    show_bytes((byte_pointer)&ix, 4);
    printf("cix=");
    show_bytes((byte_pointer)&cix, 1);

    //既有有符号和无符号转换又有长度大小转换 先进行长度大小转换再进行有符号数无符号数转换
    short sx = -12345;
    unsigned uy = sx; //<=> (unsigned)(int)sx
    printf("sx=");
    show_bytes((byte_pointer)&sx, 2);
    printf("uy=");
    show_bytes((byte_pointer)&uy, 4);
}

// get_last_unsigned
int fun1(unsigned word)
{
    return (int)((word << 24) >> 24);
}
// get_last_sign
int fun2(unsigned word)
{
    return ((int)word << 24) >> 24;
}

void test_2_23()
{
    printf("fun1(0x00000076)=%d\n", fun1(0x00000076));
    printf("fun1(0x87654321)=%d\n", fun1(0x87654321));
    printf("fun1(0x000000C9)=%d\n", fun1(0x000000C9));
    printf("fun1(0xEDCBA987)=%d\n", fun1(0xEDCBA987));

    printf("fun2(0x00000076)=%d\n", fun2(0x00000076));
    printf("fun2(0x87654321)=%d\n", fun2(0x87654321));
    printf("fun2(0x000000C9)=%d\n", fun2(0x000000C9));
    printf("fun2(0xEDCBA987)=%d\n", fun2(0xEDCBA987));
}

float sum_elements(float a[], unsigned length)
{
    int i;
    float result = 0;
    unsigned x = length - 1; // 0-1溢出为UINT_MAX
    unsigned umax = UINT_MAX;
    for (i = 0; i <= length - 1; i++)
    {
        result += a[i];
    }
    return result;
}
float sum_elements_upgrade(float a[], int length)
{
    int i;
    float result = 0;
    unsigned x = length - 1; // 0-1溢出为UINT_MAX
    unsigned umax = UINT_MAX;
    for (i = 0; i <= length - 1; i++)
    {
        result += a[i];
    }
    return result;
}
void test_sum_elements()
{
    float a[] = {};
    // sum_elements(a,0);
    sum_elements_upgrade(a, 0);
}

size_t strlen(const char *s);

int strlonger(char *s, char *t)
{
    return strlen(s) - strlen(t)>0;//len(s)<len(t)时会溢出
}
int strlonger_upgrade(char *s, char *t)
{
    return strlen(s) > strlen(t);
}
void test_strlonger(){
    char* a="123";
    char* b="4567";
    // printf("len(a)-len(b)>0 is %d",strlonger(a,b));
    printf("len(a)>len(b) is %d\n",strlonger_upgrade(a,b));
}