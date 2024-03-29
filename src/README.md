# 代码目录索引

## 第一章
* [1.7-抽象类型Triplet的表示和实现](./chapter01/1-7/main.cpp)

## 第二章

### 顺序表示和实现
* [2.1-线性集合A=AUB](./chapter02/2-1/main.cpp)
* [2.2-线性集合A(升序)和B(升序)合并（值相同不覆盖），合并后结果也为升序](./chapter02/2-2/main.cpp)
* [2.3-线性表初始化](./chapter02/2-3/main.cpp)
* [2.4-线性表插入](./chapter02/2-4/main.cpp)
* [2.5-线性表删除](./chapter02/2-5/main.cpp)
* [2.6-线性表元素定位](./chapter02/2-6/main.cpp)
* [2.7-线性表合并【针对2.2算法的改进，指针版本】](./chapter02/2-7/main.cpp)

### 链式表示和实现

#### 线性链表

##### 基于动态结点实现
* [2.8-线性链表获取结点元素](./chapter02/2-8/main.cpp)
* [2.9-线性链表插入结点元素](./chapter02/2-9/main.cpp)
* [2.10-线性链表删除结点元素](./chapter02/2-10/main.cpp)
* [2.11-线性链表创建](./chapter02/2-11/main.cpp)
* [2.12-线性链表合并【2.2指针存储结构实现】](./chapter02/2-12/main.cpp)

##### 静态链表（基于数组实现）
* [2.13-静态链表查找](./chapter02/2-13/main.cpp)
* [2.14-静态链表初始化](./chapter02/2-14/main.cpp)
* [2.15-静态链表结点分配](./chapter02/2-15/main.cpp)
* [2.16-静态链表结点释放](./chapter02/2-16/main.cpp)
* [2.17-静态链表(A - B) U (B - A)运算](./chapter02/2-17/main.cpp)

#### 循环链表

#### 双向链表
* [2.18-双向链表删除](./chapter02/2-18/main.cpp)
* [2.19-双向链表插入](./chapter02/2-19/main.cpp)

#### 实际链表应用
* [2.20-在第i个元素之前插入元素](./chapter02/2-20/main.cpp)
* [2.21-合并两个线性表](./chapter02/2-21/main.cpp)

### 一元多项式的表示及相加
* [2.22-输入m项的系数和指数,建立一元多项式P](./chapter02/2-22main.cpp)
* [2.23-完成多项式相加运算,即:Pa=Pa+Pb,并销毁一元多项式Pb](./chapter02/2-23/main.cpp)

## 第三章

### 栈

* [栈的表示和实现](./chapter03/3-0/main.cpp)

### 栈的应用举例

* [3.1-数制转换](./chapter03/3-1/main.cpp)
* [括号匹配的检验](./chapter03/3-1-1/main.cpp)
* [3.2-行编辑程序](./chapter03/3-2)
* [3.3-迷宫求解](./chapter03/3-3)
* [3.4-表达式求值](./chapter03/3-4/main.cpp)
  
### 栈与递归的实现
* [3.5-n阶Hanoi塔问题](./chapter03/3-5/main.cpp)
### 队列
* [链队列-队列的链式表示和实现](./chapter03/3-5-1/main.cpp)
* [循环队列-队列的顺序表示和实现](./chapter03/3-5-2/main.cpp)
* [离散事件模拟](./chapter03/3-6/main.cpp)

## 第四章

### 串类型的定义

### 串的表示和实现

#### 定长顺序存储表示
* [4.2-串联接 Concat(&T,S1,S2)](./chapter04/4-2/main.cpp)
* [4.3-求子串 SubString(&Sub,S,pos,len)](./chapter04/4-3/main.cpp)
#### 堆分配存储表示
* [4.4-字符序列的复制](./chapter04/4-4/main.cpp)
* [堆分配存储表示和实现](./chapter04/4-4-1/main.cpp)
#### 串的块链存储表示

### 串的模式匹配算法
* [4.5-求子串位置的定位函数 Index(S,Tpos)](./chapter04/4-5/main.cpp)
#### 模式匹配的一种改进算法
* [4.6-kmp算法改进Index](./chapter04/4-6/main.cpp)
* [4.7-模式串的next函数值](./chapter04/4-7/main.cpp)
* ~~4.8-求模式串T的next函数修正值并存入数组 nextval~~
### 串操作应用的举例
#### 文本编辑
#### 建立词索引表
* [4.9-创建查询索引表主函数](./chapter04/4-9/main.cpp)
* [4.10-索引表初始化](./chapter04/4-9/wordindex.cpp)
* [4.11-获取从文件中读取的一行字符串](./chapter04/4-9/wordindex.cpp)
* [4.12-定位索引表关键字是否已经创建](./chapter04/4-9/wordindex.cpp)
* [4.13-在索引表中创建一个新的key](./chapter04/4-9/wordindex.cpp)
* [4.14-在索引表的关键字出入新的条目](./chapter04/4-9/wordindex.cpp)

## 第五章

### 数组的顺序表示和实现
* [数组的顺序表示和实现(三/四维演示)](./chapter05/5-0/main.cpp)