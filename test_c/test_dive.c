#include "test.h"

// string和内存
char *gp = "hello";  // hello1保存在常量存储区
char ga[] = "hello"; // hello2保存在静态存储区
void string_memory()
{
    char *p = "hello";  // hello3保存在常量存储区
    char a[] = "hello"; // hello4存储在栈上

    printf("gp=%p,p=%p\n", gp, p); // gp和p指向常量存储区的同一块内存
    // p[0] = 'a';//运行时出错 常量存储区不能修改
    // gp[0] = 'z';//运行时出错
    gp = a;
    printf("p=%s,gp=%s\n", p, gp);
    gp[0] = 'z'; //允许 此时gp指向栈上内存 允许修改
    printf("p=%s,gp=%s\n", p, gp);

    char *str = func();
    // str[0]='z';//运行时出错 悬垂指针 func返回的局部变量的指针
}

void change_value2(int *ptr) // ptr=p
{
    int b = 3;
    ptr = &b; //改指针本身的值没用 ptr只是局部变量 不能把它的值传递出去
}
int *change_value3(int *ptr) // ptr=p
{
    int b = 3;  // 3在常量区  //todo why can be change
    ptr = &b;   //改变ptr
    return ptr; // result=ptr ptr被销毁
}
void change_value4(int **ptr)
{ // ptr=&p
    int b = -1;
    *ptr = &b;
}
char *return_local_str_ptr()
{
    char str[100] = "yan"; // yan在栈上分配
    return str;            //返回str的值,一个栈上的地址
                           //返回后str被销毁,str地址无效
}
char *return_local_str_ptr2()
{
    char *str = "yan"; // yan在常量区分配
    return str;        //返回str的值,一个栈上的地址
                       //返回后str被销毁,str地址无效
}
//单向值传递
void test_ptr_trans()
{
    int a = 0;
    int *p = &a;
    printf("*p=%d,p=%p\n", *p, p);
    change_value1(p);
    printf("*p=%d,p=%p\n", *p, p);
    change_value2(p);
    printf("*p=%d,p=%p\n", *p, p);
    p = change_value3(p);
    printf("*p=%d,p=%p\n", *p, p);
    change_value4(&p);
    printf("*p=%d,p=%p\n", *p, p);
    // char* str=return_local_str_ptr();
    // printf("%s\n",str);
    char *str2 = return_local_str_ptr2();
    printf("%s\n", str2);
}
// todo 放在后面为啥也可以
void change_value1(int *ptr) // ptr=p
{
    int b = 1;
    *ptr = b; //直接改变指针指向内存的值 生效
}
int sum(int i, int j)
{
    return i + j;
}
//支持多种数据类型的冒泡排序
void bubble_sort(void *data, int n, int type_size,
                 int (*ptr)(const void *, const void *)) //两个类型比较的函数
{
    int i, j;
    void *temp = malloc(type_size);
    void *addr_1, *addr_2;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            addr_1 = data + i * type_size;
            addr_2 = data + j * type_size;
            if (ptr(addr_1, addr_2) > 0)
            {
                memcpy(temp, addr_1, type_size);
                memcpy(addr_1, addr_2, type_size);
                memcpy(addr_2, temp, type_size);
            }
        }
    }
    free(temp);
}
int comp_double(const void *a, const void *b)
{
    if (*(double *)a - *(double *)b > 0)
    {
        return 1;
    }
    else if (*(double *)a - *(double *)b < 0.001)
    {
        return 0;
    }
    return -1;
}
int comp_int(const void *a, const void *b)
{
    if (*(int *)a - *(int *)b > 0)
    {
        return 1;
    }
    else if (*(int *)a - *(int *)b == 0)
    {
        return 0;
    }
    return -1;
}
//函数指针
void call_func_ptr()
{
    int (*fp)() = &sum; // fp指向函数sum的地址
    printf("fp(1,2)=%d\n", fp(1, 2));
    printf("(*fp)(1,2)=%d\n", (*fp)(1, 2));

    //把函数指针作为参数传递
    double d_arr[] = {1.5, 1.2, 1.13, 1.01, 1.22};
    int i_arr[] = {1, 4, 5, 2, 3};
    bubble_sort(d_arr, sizeof(d_arr) / sizeof(double), sizeof(double), comp_double);
    for (size_t i = 0; i < sizeof(d_arr) / sizeof(double); i++)
    {
        printf("d_arr[%d]=%f ", i, d_arr[i]);
    }
    printf("\n");
    //&comp_int和都行comp_int都行
    bubble_sort(i_arr, sizeof(i_arr) / sizeof(int), sizeof(int), &comp_int);
    for (size_t i = 0; i < sizeof(i_arr) / sizeof(int); i++)
    {
        printf("i_arr[%d]=%d ", i, i_arr[i]);
    }
    int qi_arr[] = {1, 4, 5, 2, 3};
    printf("\n");
    qsort(qi_arr, sizeof(qi_arr) / sizeof(int), sizeof(int), comp_int);
    for (size_t i = 0; i < sizeof(qi_arr) / sizeof(int); i++)
    {
        printf("qi_arr[%d]=%d ", i, qi_arr[i]);
    }
}

int CE(char *c, char *e)
{
    if (strcmp(c, "你好") == 0)
    {
        strcpy(e, "hello\n");
        return 1;
    }
    strcpy(e, "sorry\n");
    return 0;
}
int EC(char *e, char *c)
{
    if (strcmp(e, "hello") == 0)
    {
        strcpy(c, "你好\n");
        return 1;
    }
    strcpy(c, "对不起\n");
    return 0;
}

//(*frp(int i))返回的指针指向int(char*,char*)
//等价于go语言 func frp(int i) int(char*,char*){}
int (*frp(int i))(char *, char *)
{
    if (i == 0)
    {
        return CE;
    }
    if (i == 1)
    {
        return EC;
    }
}
int comp_int2(const int *a, const int *b)
{
    if (*a - *b > 0)
    {
        return 1;
    }
    else if (*a - *b == 0)
    {
        return 0;
    }
    return -1;
}
void complex_ptr_and_fun()
{
    char result[100];
    frp(0)("你好", result);
    printf("%s\n", result);
    frp(1)("hello", result);
    printf("%s\n", result);
    //调用地址为0的函数
    //把0强制转换成void(*)()函数指针 然后调用
    // (*(void(*)())0)();
    ;
    int i_arr[] = {1, 4, 5, 2, 3};
    bubble_sort(i_arr, sizeof(i_arr) / sizeof(int), sizeof(int),
                ((int (*)(const void *, const void *))comp_int2)); //强制类型转换
    for (size_t i = 0; i < sizeof(i_arr) / sizeof(int); i++)
    {
        printf("i_arr[%d]=%d ", i, i_arr[i]);
    }
    printf("\n");
}
// typedef_usage
//类型重新命名
void (*ap[10])(void (*)());
typedef void (*pfv)();
typedef void (*pf_taking_pfv)(pfv);
pf_taking_pfv ap[10]; //等价于void (*ap[10])(void(*)());

void (*f())();
typedef void (*pfv)();
pfv f(); //等价于void (*f())();

//结构体变量
//使用typedef定义结构体别名
//可以省去struct关键字
typedef struct student
{
    int age;
    char name[20];
} STUD;
STUD stu1, stu2;
// 使用结构体类型定义变量
struct stu
{
    int age;
    char name[20];
} student1, student2;
//只定义变量不定义类型
struct
{
    int age;
    char name[20];
} s1, s2;

//以下两种推荐写法
struct person
{
    int age;
    char name[20];
};
struct person p;

typedef struct
{
    int age;       // 4
    char name[20]; // 20
} cleaner_person;
cleaner_person p2;

typedef struct
{
    int i;//4
    char c;//1
} test_length;

typedef struct
{
    int i;//4
    char c;//1
    short s;//2
} test_length2;
//使用结构体和使用普通类型一样
//只不过要尽量避免参数和返回值的拷贝==>使用指针
cleaner_person* change_name(cleaner_person const *p){
    //结构体指针p->name是简便写法
    strncpy(p->name,"yss",4);
    //与上面写法等价
    // strncpy((*p).name,"yss",4);
    return p;
}
void struct_test()
{
    stu1.age = 1;
    printf("%d,%s\n", stu1.age, stu1.name);
    printf("%d,%s\n", student1.age, student1.name);
    printf("%d,%s\n", s1.age, s2.name);
    printf("%d,%s\n", p.age, p.name);
    printf("%d,%s\n", p2.age, p2.name);

    //结构体大小会按四字节对齐
    printf("sizeof(person)=%d\n", sizeof(cleaner_person));
    printf("sizeof(test_length)=%d\n", sizeof(test_length));
    printf("sizeof(test_length2)=%d\n", sizeof(test_length2));

    cleaner_person person_1;
    cleaner_person person_2;
    person_2.age=100;
    strncpy(person_2.name,"yanshaoshuai",13);
    person_1=person_2;
    printf("%d,%s\n",person_1.age,person_1.name);
    printf("%d,%s\n",person_2.age,person_2.name);
    /* if (person_1==person_2){//结构体不支持比较
        printf("person_1==person_2\n");
    } */
    cleaner_person* p= change_name(&person_2);
    printf("%d,%s\n",person_2.age,person_2.name);
    printf("%d,%s\n",p->age,p->name);
}

//枚举
enum DAY{MON=1,TUE,WED,THU,FRI,SAT,SUN};
void test_enum(){
    enum DAY today;
    today=MON;
    today=2;
    printf("%d\n",today);
    // printf("%s\n",today);
    enum DAY next_day;
    next_day=MON;
    printf("%d\n",next_day);
}