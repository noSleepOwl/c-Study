#pragma once


#include "pch.h"
#include <iostream>

using namespace std;
// 全局变量
static int gloable = 0;
// 声明方法；
void function();

int count_extern;

// extern 是一种获取的方式，指示编译器，该变量或者方法已经在别的文件中声明了，无需再次的进行初始化 ，
// 所以 extern int a = 0 该方法会报重复声明的错误，因为该属性是在其他文件中初始化过的
extern  void write_extern(void);


int max(int a, int b);
//测试使用指针调用 该函数将交换X 和Y 的值
void swap(int *x, int *y);
/*引用传递，类似于将 对应的变量指向的内存 再次的进行赋值，弄一个别名一样的东西*/
void swap_ref(int &x, int &y);

void charTest(void);

void pointTest(void);

int & returnRi(int index , int  arr []);

void timeTest(void);

struct Book
{
	string title;
	string name;
	float count;
};

void printBook(struct Book book);
