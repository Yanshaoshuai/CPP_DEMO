#include"test.h"

#ifdef LINUX
	int MAX=100;
#else
	int MAX=99;
#endif
void type() {
	int a = 0;
	double b = 0.11;
	float c = 0.11;
	int* p = &a;
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

	//getchar() �����س�
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
	//�����
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
	int a[] = { 0,1,2,3,4,5 };
	char c[] = { 'a','b' };
	int* ip = a;
	char* cp = c;
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
	while (i < 100)
	{
		printf("%d ", i++);
	}
	printf("\n");
	i = 0;
	do {
		printf("%d ", i++);
	} while (i < 100);
	printf("\n");
	char c = getchar();
	switch (c)
	{
	case 'a': printf("is a \n");
		break;
	case 'b':
		break;
	default:
		break;
	}
	for (i = 0; i < 10; i++)
	{
		if (i == 5) {
			goto a_label;
		}
	}
a_label: printf("%d\n", i);

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
	char* p = &c;
	printf("%c\n", *p);
	char a = 'a';
    //修改指针中的内容
	*p = a;
	printf("%c\n", *p);
    //修改指针本身
	p = &a;
	printf("%c\n", *p);

    //指针本身可修改 指向一个const的char 指针中的值不可修改
	const char* const_ch_p = &c;
    //指针中的值不可修改
	//*const_ch_p = a;
    //指针本身可修改
	const_ch_p = &a;
	printf("%c\n", *const_ch_p);

    //一个const指针 指针本身不可修改 指针中的值可修改
	char* const const_p = &c;
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
