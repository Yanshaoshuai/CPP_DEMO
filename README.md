# CPP_DEMO

###编译过程

1. 预处理 gcc -E 展开#开头的语句  生成.i文件

2. 编译 gcc -S 生成.s文件(汇编文件)

3. 汇编  gcc -c 生成二进制文件 .o文件

4. 链接 生成二进制可执行文件

   1. 静态链接 -static

   > 把依赖函数的实现放到此二进制文件 尺寸大 对环境依赖小

   2. 动态链接

   > 运行时找到依赖函数二进制文件的位置 尺寸小 对环境依赖大

###动态库 静态库