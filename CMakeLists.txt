cmake_minimum_required(VERSION 3.20)
project(DataStructure_C CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 源码以 UTF-8 保存，但 Windows 中文控制台默认代码页为 GBK(936)。
# 让 GCC/MinGW 把字符串字面量按 GBK 编码进可执行文件，避免控制台输出中文乱码。
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=GBK)
endif()

add_subdirectory(01_Basic_C)
add_subdirectory(02_SeqList)
add_subdirectory(03_LinkedList)
add_subdirectory(04_Stack)
add_subdirectory(05_Queue)
add_subdirectory(06_String)
add_subdirectory(07_BinaryTree)
add_subdirectory(08_Tree)
add_subdirectory(09_Graph)
add_subdirectory(10_Search)
add_subdirectory(11_Sort)
add_subdirectory(12_HashTable)
add_subdirectory(13_OJ_Practice)
