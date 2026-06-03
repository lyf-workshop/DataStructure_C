# DataStructure_C

这是一个用于学习数据结构的 C++11 项目。项目整体按照数据结构课程章节拆分，每个章节都是一个独立的 CMake 可执行目标，方便单独编写、运行和调试。

项目代码目前采用“C 风格数据结构 + C++11 编译”的写法：主要使用 `struct`、指针、函数接口来实现数据结构，同时使用 C++ 引用参数简化部分传参形式。

## 开发环境

- 语言标准：C++11
- 构建工具：CMake
- 推荐 IDE：CLion

根目录的 `CMakeLists.txt` 已配置：

```cmake
project(DataStructure_C CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

## 项目结构

```text
DataStructure_C/
├── 01_Basic_C/          C/C++ 基础
├── 02_SeqList/          顺序表
├── 03_LinkedList/       链表
├── 04_Stack/            栈
├── 05_Queue/            队列
├── 06_String/           字符串
├── 07_BinaryTree/       二叉树
├── 08_Tree/             树
├── 09_Graph/            图
├── 10_Search/           查找
├── 11_Sort/             排序
├── 12_HashTable/        哈希表
├── 13_OJ_Practice/      OJ 练习
├── common/              公共头文件
├── CMakeLists.txt       根 CMake 配置
└── README.md
```

## 章节说明

| 目录 | 内容 | 状态 |
| --- | --- | --- |
| `01_Basic_C` | 基础语法与简单结构定义 | 初始示例 |
| `02_SeqList` | 顺序表 | 部分实现 |
| `03_LinkedList` | 单链表、双向链表、静态链表 | 正在实现 |
| `04_Stack` | 栈 | 待实现 |
| `05_Queue` | 队列 | 待实现 |
| `06_String` | 字符串 | 待实现 |
| `07_BinaryTree` | 二叉树 | 待实现 |
| `08_Tree` | 树 | 待实现 |
| `09_Graph` | 图 | 待实现 |
| `10_Search` | 查找 | 待实现 |
| `11_Sort` | 排序 | 待实现 |
| `12_HashTable` | 哈希表 | 待实现 |
| `13_OJ_Practice` | OJ 练习题 | 待实现 |

## 链表模块结构

`03_LinkedList` 已经按链表类型拆分：

```text
03_LinkedList/
├── main.cpp
├── singly_linked_list.h
├── singly_linked_list.cpp
├── doubly_linked_list.h
├── doubly_linked_list.cpp
├── static_linked_list.h
└── static_linked_list.cpp
```

各文件职责：

- `singly_linked_list.*`：单链表相关结构和操作函数
- `doubly_linked_list.*`：双向链表相关结构和操作函数
- `static_linked_list.*`：静态链表相关结构和操作函数
- `main.cpp`：当前章节的测试与演示入口

## 公共定义

公共头文件位于 `common/utils.h`，目前包含常用状态码和元素类型：

```cpp
#define OK    1
#define ERROR 0
#define TRUE  1
#define FALSE 0

typedef int Status;
typedef int ElemType;
```

其中：

- `Status` 用于表示函数执行状态
- `ElemType` 表示数据结构中存储的元素类型，当前默认为 `int`

## 构建方式

在项目根目录下执行：

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
```

也可以只构建某一章，例如链表章节：

```bash
cmake --build cmake-build-debug --target 03_LinkedList
```

构建完成后，可执行文件会生成在对应的 CMake 构建目录中。

## 编码约定

当前项目主要保持教材式数据结构写法：

- 使用 `struct` 定义结点和表结构
- 使用 `Status` 表示函数执行结果
- 使用 `ElemType` 统一元素类型
- 使用 `LinkList &L` 这类 C++ 引用参数表示需要修改的链表指针
- 每个章节尽量保持独立，公共定义放在 `common/`

示例：

```cpp
Status ListInsert_L(LinkList &L, int i, ElemType &e);
Status ListDelete_L(LinkList &L, int i, ElemType &e);
Status GetElem_L(LinkList L, int i, ElemType &e);
```

## 学习目标

这个项目的重点不是使用 STL 容器替代数据结构，而是手动实现底层逻辑，理解：

- 顺序存储与链式存储
- 插入、删除、查找、遍历等基本操作
- 栈、队列、树、图等结构的核心算法
- 指针、动态内存和结构体之间的关系
- 常见 OJ 题目中的数据结构应用

## 当前备注

项目仍处于学习和完善阶段，部分章节只有函数框架或演示入口。建议每完成一个章节后，补充对应的测试代码或简单示例，保证每个数据结构的核心操作都可以独立运行验证。
