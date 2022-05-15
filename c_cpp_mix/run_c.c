#include "c_call_cpp.h"
#include "test_mix_cpp.h"
#include <stdio.h>
int main() {
	int sum_result = sum(3, 4);
	int add_one_result = add_one(1);
	printf("sum_result=%d,add_one_result=%d\n", sum_result, add_one_result);
	int result = delta(1,2);
	printf("c call c++ delta(1,2)=%d\n",result);
	return 0;
}