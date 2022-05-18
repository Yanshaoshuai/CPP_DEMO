#include"test.h"

#ifdef LINUX
int MAX=100;
#else
int MAX = 99;
#endif

void type() {
    int a = 0;
    double b = 0.11;
    float c = 0.11;
    int *p = &a;
    char ch = 97;
    printf("int a= %d,double b=%f,float c=%f,int* p=%d,char ch=%c\n", a, b, c, *p, ch);
    //int 范围-2147483648～2147483647（-2^{31} \sim 2^{31}-1）
    printf("INT_MAX=%d,INT_MIN%d\n", INT_MAX, INT_MIN);
    //溢出
    printf("INT_MAX+1=%d,INT_MIN-1=%d\n", INT_MAX + 1, INT_MIN - 1);
}

void type_len() {
    printf("char is take %llu byte\n", sizeof(char));
    printf("short is take %llu byte\n", sizeof(short));
    printf("int is take %llu byte\n", sizeof(int));
    printf("long is take %llu byte\n", sizeof(long));
    printf("long long is take %llu byte\n", sizeof(long long));
    printf("float is take %llu byte\n", sizeof(float));
    printf("double is take %llu byte\n", sizeof(double));
}

void io() {
    //输出-128表示char在本地是有符号的
    //输出0表示char是无符号的
    printf("CHAR_MIN=%d\n", CHAR_MIN);

    //getchar() ???????
    /*char c;
    while ((c = getchar()) != EOF)
    {
        printf("c=%c\n", c);
    }*/
    /*char ch;
    ch = getchar();
    putchar('1');
    putchar(ch);
    putchar('\n');
    ch = getchar();
    putchar('2');
    putchar(ch);
    putchar('\n');*/


    /*char str[30];
    char c;*/
    //gets不会读入回车
    /*gets(str);
    puts(str);
    c = getchar();
    putchar(c);*/

    char str[5];
    char c;
    short int i;
    int result;
    //因为要赋值所以用指针
    result = scanf("%c,%hd %5s", &c, &i, str);
    printf("c=%c,i=%d,str=%s,result=%d\n", c, i, str, result);
}

//比较浮点数
void compare_float() {
    float a = 0.33f;
    float b = 0.11f;
    b += 0.22f;
    //返回0
    if (a == b) {
        printf("a==b is true\n");
    }
    if (fabs(b - a) < FLT_EPSILON) {
        printf("a==b is true\n");
    }
}

//比较字符串长度
void compare_str_len() {
    char str1[] = "abcdefg";
    char str2[] = "abc";
    //溢出 true
    if (strlen(str2) - strlen(str1) > 0) {
        printf("strlen(str2)-strlen(str1)>0 \n");
    }
    if (strlen(str2) > strlen(str1)) {
        printf("strlen(str2) > strlen(str1) \n");
    }
}

// array length
void arr_len() {
    int a[] = {0, 1, 2, 3, 4, 5};
    char c[] = {'a', 'b'};
    int *ip = a;
    char *cp = c;
    printf("sizeof(ip)=%llu\n,sizeof(cp)=%llu\n", sizeof(ip), sizeof(cp));
    //int 4字节 char 1字节
    printf("sizeof(a)=%llu\n,sizeof(c)=%llu\n", sizeof(a), sizeof(c));
}

//loop and branch
void loop_branch() {
    int i;
    for (i = 0; i < 100; i++) {
        printf("%d ", i);
    }
    printf("\n");
    i = 0;
    while (i < 100) {
        printf("%d ", i++);
    }
    printf("\n");
    i = 0;
    do {
        printf("%d ", i++);
    } while (i < 100);
    printf("\n");
    char c = getchar();
    switch (c) {
        case 'a':
            printf("is a \n");
            break;
        case 'b':
            break;
        default:
            break;
    }
    for (i = 0; i < 10; i++) {
        if (i == 5) {
            goto a_label;
        }
    }
    a_label:
    printf("%d\n", i);

}

//宏
void macro() {
    printf("MAX=%d\n", MAX);
    PRINT_HELLO;
    double area = AREA_CIRCULAR(1);
    printf("%f\n", area);
}

//const
void const_test() {
    char c = 'c';
    char *p = &c;
    printf("%c\n", *p);
    char a = 'a';
    //修改指针中的内容
    *p = a;
    printf("%c\n", *p);
    //修改指针本身
    p = &a;
    printf("%c\n", *p);

    //指针本身可修改 指向一个const的char 指针中的值不可修改
    const char *const_ch_p = &c;
    //指针中的值不可修改
    //*const_ch_p = a;
    //指针本身可修改
    const_ch_p = &a;
    printf("%c\n", *const_ch_p);

    //一个const指针 指针本身不可修改 指针中的值可修改
    char *const const_p = &c;
    //指针指向的值可修改
    *const_p = 'a';
    printf("%c\n", *const_p);
    // 指针本身不可修改
    //const_p = &a;
}

//static
void static_test() {
    //默认值为0
    static int count;

    printf("static_test has been called %d time\n", ++count);
}

//声明和定义
//声明一个函数 不分配内存
int foo(int i);

//声明一个变量 不申请内存
extern int k;
//声明一个变量 并分配内存
int have_mem;

//定义一个函数 函数定义可以在main函数后
int foo(int i) {
    int j = 5;//定义一个变量
}

//字符串操作
void string_test() {
    //c语言字符穿结尾标识符为\0
    char a[5] = {'1', '2', '3', '\0', '4'};
    printf("a=%s\n", a);

    //字符串溢出 末尾没有空间放\0 会向高地址寻找直到找到\0字符为止
    //c编译器并不会检查.运行时也不会检查
    char str1[6] = {"world!"};
    char str2[5] = {"hello"};
    printf("str1=%s,str2=%s\n", str1, str2);
    //address str1=00000069123ffab5,str2=00000069123ffab0
    //address str1 > address str2 内存从高到低分配
    printf("address str1=%p,str2=%p\n", str1, str2);

    //strcat与strcpy均会发生字符串溢出

    char src[8] = {"world!"};
    char des[11] = {"hello"};
    //把src中的内容连接接到des之后
    strcat(des, src);
    printf("src=%s,des=%s\n", src, des);

    char src_cpy[7] = {"world!"};
    char des_cpy[6] = {"hello"};
    printf("src_cpy=%s,des_cpy=%s\n", src_cpy, des_cpy);
    //把src中的内容复制到des中
    strcpy(des_cpy, src_cpy);
    printf("src_cpy=%s,des_cpy=%s\n", src_cpy, des_cpy);


    //使用strncpy和strncat等簇函数可以避免字符串溢出

    char src_ncat[8] = {"world!"};
    printf("%c\n", src_ncat[0]);
    char des_ncat[10] = {"hello"};
    printf("address src_ncat=%p\n", src_ncat);
    int len_des_ncat = strlen(des_ncat);
    int size_des_ncat = sizeof(des_ncat);
    //注意这里减一是因为最后一个字符留给'\0'用 否则也会溢出
    // 溢出会覆盖到相邻高地址 如果src和des相邻 src可能会被覆盖
    strncat(des_ncat, src_ncat, size_des_ncat - len_des_ncat - 1);
    printf("src_ncat=%s,des_ncat=%s\n", src_ncat, des_ncat);
    printf("address src_ncat=%p\n", src_ncat);
    printf("%c\n", src_ncat[0]);

    char src_ncp[7] = {"world!"};
    char des_ncp[6] = {"hello"};
    //注意这里减一是因为最后一个字符留给'\0'用 否则也会溢出
    strncpy(des_ncp, src_ncp, sizeof(des_ncp) - 1);
    printf("src_ncp=%s,des_ncp=%s\n", src_ncp, des_ncp);

    //strtok
    char str[] = "This, is ,a ,sample, string";
    char *pch;
    printf("splitting string\"%s\"into tokens:\n", str);
    //把str中的delim替换成\0
    pch = strtok(str, ",");
    while (pch != NULL) {
        printf("%s\n", pch);
        //第二次调用需要传NULL
        pch = strtok(NULL, ",");
    }
    printf("%s\n", str);

    printf("%d\n", strlen_source(str));
}

size_t strlen_source(const char *str) {
    const char *eos = str;
    while (*eos++);
    return (eos - str - 1);
}


void time_test() {
    char a[100];
    time_t now;
    //获取秒数 1970年1月1日0时0秒~now
    time(&now);//or now= time(NULL);
    //获取时间字符串
    printf("%s", ctime(&now));

    /**
     * 利用time返回值构建表达式
     */
    printf("%d\n", time(NULL) + 60 * 60 * 24 * 7);

    struct tm *local_time = localtime(&now);
    //得到自定义时间字符串
    strftime(a, 100, "%d-%m-%Y", local_time);
    printf("now is %s\n", a);
    //获取本地时间
    printf("Local time:年->%d 月->%d 日->%d 时->%d 分->%d 秒->%d\n",
           local_time->tm_year, local_time->tm_mon, local_time->tm_mday,
           local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
    struct tm *pTm = gmtime(&now);
    printf("GMT time:年->%d 月->%d 日->%d 时->%d 分->%d 秒->%d\n",
           pTm->tm_year, pTm->tm_mon, pTm->tm_mday, pTm->tm_hour, pTm->tm_min, pTm->tm_sec);

}

void array_test() {
    //数组定义必须指明长度
    //此种定义也隐含了数组长度
    int arr[] = {1, 2, 3, 4, 5};
    //遍历数组
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    int arr2[] = {1, 2, 3};
    //不能把数组变量放到左边
    //arr=arr2;
    //建议使用memcpy给数组遍历重新赋值
    memcpy(arr, arr2, sizeof(arr2));
    //不能计算数组变量
    //arr++;
    //不检查数组越界 ***注意数组越界修改其它遍历的内存***
    //vs的debug可能会在两个相邻数组之间加上额外元素 如果操作中间的两个元素会产生异常
    printf("%d\n", arr[5]);

    //不指定指初始化 值随机
    int a[100];
    for (int i = 0; i < 100; ++i) {
        printf("%d\n", a[i]);
        //可以手动清零数组
        //a[i]=0;
    }
    //建议使用memset清零
    memset(a, 0, sizeof(a));

    //函数参数中的数组参数是数组引用传递
    void test_trans_arr(int arr[]);
    test_trans_arr(a);
    printf("a[0]=%d\n", *a);

    //二维数组
    int two_dim_arr1[2][3] = {1, 2, 3, 4, 5, 6};
    //隐式包含了第一维
    int two_dim_arr2[][3] = {{1, 2, 3},
                             {4, 5, 6}};
    //这样初始化不行 第二维必须指定
    //int two_dim_arr3[2][]={{1,2,3},{4,5,6}};
    for (int i = 0; i < 2; ++i) {
        //two_dim_arr1[i]的值是一个一维数组
        printf("two_dim_arr1[%d]=%p\n", i, two_dim_arr1[i]);
        for (int j = 0; j < 3; ++j) {
            printf("%d\n", two_dim_arr1[i][j]);
        }
    }
    //通过指针的方式遍历 int a[M][N] a[m][n]=*(p+(m*N+n))
    int *p = two_dim_arr2;
    for (int i = 0; i < sizeof(two_dim_arr2) / sizeof(int); ++i) {
        printf("two_dim_arr2[%d]=%d\n", i, *(p + i));
    }

    //奇葩
    int arr_0=0[arr];
    printf("%d\n",arr_0);
    printf("%c",5["abcdef"]);
}
//数组不能作为返回值
//int[] return_arr(){
//    int a[100];
//   return a;
//}
void test_trans_arr(int arr[]) {
    arr[0] = 1110;
}

void pointer_test() {
    char a = 'a';
    char *p1;
    char *p2;
    char *p3, p4;
    p1 = &a;
    printf("*p1=%c,*p1=%d\n", *p1, *p1);
    printf("2**p1=%d\n", 2 * *p1);
    printf("*p1**p1=%d\n", *p1 * *p1);
    printf("*p1/(*p1)=%d\n", *p1 / (*p1));

    //指针 类型的作用:类型决定寻址时取出数据的长度 和 计算单位
    char str[30];
    //'\1'=0000,0001
    int num='\1';
    itoa(num, str, 2);
    printf("'\\1'=%s\n",str) ;

    //0000,0001 0000,0001 0000,0001 0000,0001
    char ch[] = {'\1', '\1', '\1', '\1'};
    char *ch_ptr = &ch;
    short *sh_ptr = &ch;
    int *i_ptr = &ch;
    //0000,0001=1
    itoa(*ch_ptr, str, 2);
    printf("*ch_ptr(二进制)=%s,*ch_ptr(十进制)=%d\n",str,*ch_ptr);
    //0000,0001=1*2^8+1=257
    itoa(*sh_ptr, str, 2);
    printf("*sh_ptr(二进制)=%s,*sh_ptr(十进制)=%d\n",str,*sh_ptr);
    itoa(*sh_ptr, str, 2);
    printf("*(sh_ptr+1)(二进制)=%s,*(sh_ptr+1)(十进制)=%d\n",str,*(sh_ptr+1));
    itoa(*i_ptr, str, 2);
    //0000,0001 0000,0001 0000,0001 0000,0001=1*2^24+1*2^16+1*2^8+1=16843009
    printf("*i_ptr(二进制)=%s,*i_ptr(十进制)=%d\n",str,*i_ptr);

    //野指针
    //定义指针不初始化 指向一个不确定的地址
    //short *p;
    //运行时会产生错误 因为在试图访问一个非法内存
    //printf("%p\n",p);
    //printf("%d\n",*p);
    //*p=5;

    //避免野指针 初始化时赋值为NULL或者其它变量地址
//    short *p=NULL;
//    printf("%p\n",p);
//    printf("%d\n",*p);
//    *p=5;
}

void void_and_null(){
    //void 用处
    // 1.函数没有返回值或参数 声明为void 提高移植性(有的编译器把没有返回值的函数默认返回一个int型)
    // 2.声明一个void类型的指针 此类型的指针只有地址没有类型
    void *void_ptr;
    //任何类型的指针都可以赋值给void指针
    int a=100;
    void_ptr=&a;
    //赋值给void指针后类型信息丢失 取值不再允许
    //printf("%d\n",*void_ptr);
    //计算以单字节为单位
    printf("%d\n",void_ptr);
    void_ptr++;
    printf("%d\n",void_ptr);
    //将void*赋值给其它指针
    int *b=--void_ptr;
    printf("%d\n",*b);

    //申请一块4字节的内存并将void*转换为int类型的指针
    int* p_int=(int*) malloc(sizeof(int));
    printf("*p_int=%d\n",*p_int);

    //NULL 源码中定义为0 并不是指针类型
    //下面定义意味着指针不指向任何可用地址 避免野指针
    int* null_ptr=NULL;
    //函数返回为NULL表示函数调用不成功如fopen和fgets等

}


