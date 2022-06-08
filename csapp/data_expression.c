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