# 使用CMake运行本项目

## 1. 新建项目

在本项目基础上使用 `CLion` 新建项目。



## 2. 替换CMakeLists

将下面内容替换 `CMakeLists`

```cmake
cmake_minimum_required(VERSION 3.20)
project(MIPS_assembler___)

set(CMAKE_CXX_STANDARD 14)

add_executable(MIPS_assembler___ main.cpp LableTable.h phase2.h phase2.cpp phase1.h phase1.cpp)

```



## 3. 调整程序参数

程序参数为：

```
testfile.asm output.txt expectedoutput.txt
```



![image-20220315133233452](../../../%E7%AC%94%E8%AE%B0&md/statics/img/image-20220315133233452.png)

