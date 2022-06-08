cmake_minimum_required(VERSION 3.21)
project(CPP_DEMO C CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

# 设置启动参数
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Fno-toplevel-reorder")
# 设置编译类型
set(CMAKE_BUILD_TYPE    Debug)
# Release类型无法调试
# set(CMAKE_BUILD_TYPE    Release)
#忽略警告
add_definitions(-w)

# Add header file include directories
include_directories(./test_c ./c_cpp_mix)

# 设置编译包含的文件
file(GLOB_RECURSE TEST_C "test_c/*.c")
file(GLOB_RECURSE CSAPP "csapp/*.c")
file(GLOB_RECURSE MIX_C_CALL_CPP_FILE  "c_cpp_mix/*.c" "c_cpp_mix/*.cpp" EXCEPT "c_cpp_mix/run_cpp.cpp")
file(GLOB_RECURSE MIX_CPP_CALL_C_FILE  "c_cpp_mix/*.c" "c_cpp_mix/*.cpp" EXCEPT "c_cpp_mix/run_c.c")

# 混合编程 排除c++ main() 所在文件
list(REMOVE_ITEM  MIX_C_CALL_CPP_FILE "${CMAKE_CURRENT_SOURCE_DIR}/c_cpp_mix/run_cpp.cpp")
message(******** MIX_C_CALL_CPP_FILE exclude ==> "${CMAKE_CURRENT_SOURCE_DIR}/c_cpp_mix/run_cpp.cpp")
# 排除c main() 所在文件
list(REMOVE_ITEM  MIX_CPP_CALL_C_FILE "${CMAKE_CURRENT_SOURCE_DIR}/c_cpp_mix/run_c.c")
message(******** MIX_CPP_CALL_C_FILE exclude ==> "${CMAKE_CURRENT_SOURCE_DIR}/c_cpp_mix/run_c.c")

message(******** MIX_C_CALL_CPP_FILE ${MIX_C_CALL_CPP_FILE})
message(******** MIX_CPP_CALL_C_FILE ${MIX_CPP_CALL_C_FILE})

add_executable(CSAPP_MAIN ${CSAPP})
add_executable(TEST_C_MAIN  run_app.c ${TEST_C})
add_executable(MIX_C_CALL_CPP   c_cpp_mix/run_c.c ${MIX_C_CALL_CPP_FILE})
add_executable(MIX_CPP_CALL_C   c_cpp_mix/run_cpp.cpp ${MIX_CPP_CALL_C_FILE})