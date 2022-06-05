#include <stdio.h>

/**
 * a=ffffffff
 * ,b=1
 * ,c=1
 * C语言 有符号数用补码表示
 * */
void bit_test_base(){
    int a=-1;
    int b=1;
    unsigned c=1;
    printf("a=%x\n,b=%x\n,c=%x\n",a,b,c);
}