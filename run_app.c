#include "test_c/test.h"

int main() {
    type();
    type_len();
    io();
    compare_float();
    compare_str_len();
    arr_len();
    loop_branch();
    macro();
    printf("%d\n", MAX);
    const_test();
    for (size_t i = 0; i < 10; i++) {
        static_test();
    }
    return 0;
}
