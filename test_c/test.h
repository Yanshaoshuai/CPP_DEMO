//#pragma once
#ifndef TEST_H
#define TEST_H
	#define _CRT_SECURE_NO_WARNINGS 1
	//宏替换
    //#define NAME stuff 在预处理阶段,把源码中的NAME替换成stuff 只是简单替换，不会做校验
	#define PRINT_HELLO printf("hello world!\n");
	#define PI 3.1415926
    //可以拆成多行 每行末尾加'\'
	#define AREA_CIRCULAR(r) \
	(PI*(r)*(r))

    //声明全局变量
	extern int MAX;
	#include<stdio.h>
	#include<limits.h>
	#include<math.h>
	#include<float.h>
	#include<string.h>
    #include <time.h>
    #include<stdlib.h>
    //函数声明
	void type();
	void type_len();
	void io();
	void compare_float();
	void compare_str_len();
	void arr_len();
	void loop_branch();
	void macro();
	void const_test();
	void static_test();
    void string_test();
    size_t strlen_source(const char* str);
    void time_test();
    void array_test();
    void pointer_test();
    void void_and_null();
#endif // !TEST_H

