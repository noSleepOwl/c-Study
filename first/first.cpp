// first.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include "first.h"
#include <cstring>
#include<ctime>
#include<string>
#include "Persion.h"



int main()
{
	
	count_extern = 100;
	// 调用方法
	function();
	for (int i = 0; i < 1000; i++) {
		function();
	}
	
	cout << "结果：" << gloable << "\n";
	cout << "max 结果：" << max(1, 100) << endl;
	write_extern();

	int x = 1;
	int y = 2; 

	cout << "x=" << x << " y=" << y << endl;
	swap(x, y);
	cout << "x=" << x << " y=" << y << endl;


	cout << "-------------------------char-----testing-----" << endl;

	charTest();
	pointTest();
	timeTest();

	Book book;
	book.name = "书名";
	book.title = "数的标题";
	book.count = 100.5;

	printBook(book);

	struct Book *pBook;

	pBook = &book;
	// 指针类型的数据类型, 需要使用 -> 进行访问
	pBook->name = "wo wo oowowowoo ";

	printBook(*pBook);

	Persion p;
	p.name = "m;m;m; ";
	p.age = 100;

	p.talkSelf();

	Persion xiaoMing = Persion("王小明", 10);

	xiaoMing.talkSelf_2();

	Student student;
	student.name = "王小明的儿子";
	student.age = 10;

	student.talkSelf();

	Persion *student_persion = &student;

	student_persion->talkSelf();

	return 0;
}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

void function()
{
	gloable++;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void swap(int * x, int * y)
{	
	// 取出
	int temp = *x;
	// 赋值
	*x = *y;
	//放回
	*y = temp;
	return;
}

void swap_ref(int & x, int & y)
{
	int temp;
	temp = x; /*保存x 地址*/
	x = y;  /*x赋值Y*/
	y = temp;/*y赋值 x*/
	return;
}

void charTest(void)
{
	// c 语言形式的字符串
	char greating[6] = {'g','r','e','e','t','\0'};
	cout << greating << endl;

	cout << "一些字符串操作" << endl;

	char str_1[12] = "hello";
	char str_2[12] = "world";
	char str_3[12] ;
	int len;
	// 复制 ..  使用这个函数需要在预处理器里面添加 _CRT_SECURE_NO_WARNINGS  这个东西。。。。 
	strcpy(str_3, str_1);
	cout << "		str_1=" << str_1 << "			str_2=" << str_2 << "		 str_3=" << str_3 << "		strcpy(str_1, str_3);" <<endl;
	// 链接
	strcat(str_1, str_2);
	cout << " str_1=" << str_1 << "		str_2=" << str_2 << "	 str_3=" << str_3 << "		strcat(str_1, str_2);" << endl;
	len = strlen(str_1);
	cout << "len=" << len << endl;

	cout << "-------------------------" << "c++ 自带string 类型" << endl;

	string ca_str_1 = "hello";
	string ca_str_2 = "world";
	string ca_str_3;
	int length;

	ca_str_3 = ca_str_1;  // 复制
	cout << ca_str_1 << endl;
	ca_str_3 = ca_str_1 + ca_str_2; // 链接
	cout << ca_str_3 << endl;
	length = ca_str_3.size(); // 字符串长度；
	cout << length << endl;


}

void pointTest(void)
{

	int var1 = 10;
	char var2[10];
	/*输出内存地址*/
	cout << &var1 << endl;

	cout << &var2 << endl;

	int *ip = NULL;

	cout << " int *ip = NULL ip为=" << ip << endl;

	if (!ip) {
		cout << "空指针可以进行判断使用 if(ip) 非空判断 if(!ip)" << endl;
	}

	ip = &var1; //赋值；
	
	

	cout << "ip 指向的指针地址是："<< ip << endl;  // 取指针指向的地址
	 
	cout << "ip指针指向的值是：" << *ip << endl; // 取指针指向的变量

	cout << "---------------使用指针访问数组---------------" << endl;

	const int max = 10; 

	int arr[max] = { 1111,21111,3111,411,1115,1116,11117,1118,11119,111110 };

	int *arr_p = arr;

	for (int i = 0; i < max; i++)
	{
		cout << arr_p << "<==========>" << *arr_p << endl;
		arr_p++;
	}


	int i = 100;
	int & ri = i;

	i++;

	cout << i << "---" << ri << endl;

	
	returnRi(1, arr) = 100;
	returnRi(2, arr) = 10;

	for (int i = 0; i < max; i++)
	{
		cout << arr[i] << endl;
	}


}

int & returnRi(int index, int arr[])
{

	return arr[index];
}

void timeTest(void)
{

	time_t now = time(0);
	cout << "1970年到目前的秒数：" << now << endl;
	tm *ltm = localtime(&now);

	// 输出 tm 结构的各个组成部分
	cout << "年: " << 1900 + ltm->tm_year << endl;
	cout << "月: " << 1 + ltm->tm_mon << endl;
	cout << "日: " << ltm->tm_mday << endl;
	cout << "时间: " << ltm->tm_hour << ":";
	cout << ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;
}

void printBook(Book book)
{
	cout << "book.name=" << book.name << endl;
	cout << "book.title=" << book.title<< endl;
	cout << "book.count=" << book.count << endl;
}
