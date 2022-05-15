//c和cpp 混合编程通用头文件
//cpp为了支持函数重载 会在编译后改变函数名(name mangling 名称修改) c则不会
//extern "C"是cpp的语法 c并不支持

//如果是cpp编译器编译 则带上 extern "C" 否则不带上
//效果是cpp编译后不会修改函数名(告诉编译器不要进行name mangling)
#ifndef TEST_MIX_CPP
#define TEST_MIX_CPP
	#ifdef __cplusplus
	extern "C" {
	#endif
        //此处不能声明c语言没有的内容 比如class等
		int sum(int,int);
		int add_one(int);
        int delta(int a, int b);
		#include <stdio.h>
		
	#ifdef __cplusplus
	}
	#endif // __cplusplus
#endif // TEST_MIX_CPP
