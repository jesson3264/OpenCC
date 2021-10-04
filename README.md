# OpenSCL
OpenSCL   Open Simple C(C++) Library.


## 介绍
C语言实现的简单C库，该项目现在也包含Cpp 实现的一些库代码。


## 项目目录说明
.  
## +C  
可单独编译成 scl 库
1. 单链表、双链表，栈、队列、双向队列、hash 实现。
2. 共享内存的内存池，普通内存的内存池。
### -scl
生成的C库代码

### -source
所有的 C 源码

### -test
测试代码目录，可以你想学习，可以从这个目录的代码开始调试

### -unclassify
一些自己还在开发中的代码

## +Cpp  
Cpp 编译时会同时编译C 中的代码，因为要用到C中的一些C接口类型的代码或数据结构，比如错误码之类的。
1. Ini 文件读取类


## +cpp11

## +unclassify 
一些还未添加测试用例的代码，暂时在这个目录下进行迭代

## +windows
windows 平台的代码，主要是开发过程中的测试用

## TODO
计划中的开发项

1. 线程池

### 如何进行调试
以C代码为例， 先到 C/source/ 目录下， 
```
$ mkdir build
$ cd build
$ cmake .. && make && make install

然后进到 C/test目录
$ mkdir build
$ cd build
$ cmake .. && make 
$ cd ../bin/
$ gdb SCL_TEST
```
### Contact
微信 : jxdeng64  
QQ群 : 1067933393


