#include "pch.h"
#include <iostream>
#include <string>


using namespace std;
//typedef int fact(int);
typedef int (*FACT) (int val) ;
//typedef decltype(fact) *p_fact;

namespace extend {
	class Persion {
	public:
		string name;
		int getAge() {
			return age;
		}
	
	private:
		int age;

	};
}
// 一个函数从未被使用过，将可以不用实现；
void naverUse();
// 函数声明可以不指参数的名称； 声明 也可以称之为 函数原型；
void noNameParam(int, int, string, extend::Persion);
void valueParam(extend::Persion p) {
	p.name = "whwhwhwh";
}
void quoteParam(extend::Persion &p) {
	p.name = "...... name";
}

void printPersion(const extend::Persion &persion) {
	cout << persion.name << endl;
}
void foreachArray(const int *start, const int *end) {
	while (start != end)
	{
		cout << *start++ << endl;
	}
	
}


/*阶乘函数*/
int fact(int val) {
	// 在函数第一次调用的时候被初始化为0，后面就不会进行初始化了。。即使函执行结束之后也不会被销毁；
	static int  count = 0;
	++count;
	cout << count << endl;
	int result = 1;
	const int &r2 = 23;

	while (val>1)
	{
		result *= val--;
	}
	return result;
}

void runFact(FACT fact) {
	cout << fact(16) << endl;
}

void runFunction(void (*func)(const int * ,const int *)) {
	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
	func(begin(arr), end(arr));
}
void printLine(string msg="") {
	cout << "[[--------->>" <<msg<< "<<---------]]" << endl;
}
//------------------------------------------------------------------------------------------------------------------
struct Sales_data
{
	string isbn() {
		return bookNumber;
	}

	string bookNumber;
};
//------------------------------------------------------------------------------------------------------------------
int main(int argc,char *argv[])
{

	const int i = 0, &r = i;
	auto a = r;


	a++;
	cout << a << endl;
	cout << i << endl;
	
	
	extend::Persion persion;
	persion.name = "init no name";
	// 初始化类型
	printPersion(persion);
	// 值传递
	valueParam(persion);
	//属性的改变将只在函数内执行
	printPersion(persion);
	// 引用传递
	quoteParam(persion);
	// 外部的对象将改变
	printPersion(persion);
	/*阶乘函数 1*2*3 ....*/
	for (int i = 1; i < 17; i++) {

	cout << i << "的阶乘结果是：  "<<fact(i) << endl;
	}

	int arr[9] = { 1,2,3,4,5,6,7,8,9 }; 
	foreachArray(begin(arr), end(arr));
#ifdef NDEBUG
	cerr << "---------------------" << endl;
#endif // NDEBUG

#ifdef DEBUG
	cerr << "--------------------" << endl;
#endif // DEBUG
	// 函数指针
	printLine("函数指针");
	auto func = foreachArray;
	runFunction(foreachArray);
	printLine("函数指针——typedef");
	runFact(fact);
}



