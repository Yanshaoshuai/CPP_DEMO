#include "test.h"
// #define NDEBUG//Release时 使用该宏关闭assert函数
#include<assert.h>
#include<errno.h>
//文件
void test_file()
{
    // r读 w写
    // r+读写 文件不存在就失败 文件存在就追加
    // w+文件不存在会新建    文件存在就清空
    FILE *fp = fopen("/home/yan/code/c/CPP_DEMO/test_c/file/test_read.txt", "r");
    char ch = 0;
    do
    {
        ch = fgetc(fp);
        printf("%c", ch);
    } while (!feof(fp));
    printf("\n");
    // b以二进制方式打开
    //非linux环境下
    // fputs fgets fputc fgetc fprintf 用文本模式打开(不加b)
    // fread fwrite fseek rewind ftell 用二进制模式打开
    //防止 非linux \n = 0A问题
    // linux \n(LF 0A) windows \r\n(CRLF 0D0A) //windows遇到0A自动加0D
    fp = fopen("/home/yan/code/c/CPP_DEMO/test_c/file/test_write.txt", "wb+");
    int i = 0x000a0000;
    printf("%d\n", i);
    fwrite(&i, sizeof(int), 1, fp);
    do
    {
        ch = fgetc(fp);
        if (!feof(fp))
        {
            printf("%c", ch);
        }
    } while (!feof(fp));
    printf("\n");
    char *str = "the first line\n";
    char *str1 = "the second line\n";
    fp = fopen("/home/yan/code/c/CPP_DEMO/test_c/file/test_write2.txt", "wb+");
    fputs(str, fp);
    fputs(str1, fp);

    // EOF test
    // EOF是缓冲区中在末尾处添加的一个标志 不是文件本身的内容
    // feof返回上一个读操作是否读取到了EOF
    // ferror返回是否读取出错
    fp = fopen("/home/yan/code/c/CPP_DEMO/test_c/file/test_read.txt", "r");
    if(NULL==fp){
        printf("%d\n",errno);//输出错误编号 出现错误被设为非0值
        perror("test_read.txt");//输出错误
    }
    while (ch = fgetc(fp))//标准读数据做法
    {
        if (ch == EOF)
        {
            if (feof(fp) != 0)
            {
                break;
            }
            if (ferror(fp) != 0)
            {
                printf("error occur here!\n");
                break;
            }
        }
        printf("%c", ch);
    }

    fclose(fp);
    assert(0==0);

}
