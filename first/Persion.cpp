#include "pch.h"
#include "Persion.h"


string Persion::countory = "china";

Persion::Persion()
{
}

// 快速的进行初始化
Persion::Persion(string name, int age):name(name),age(age)
{

}

Persion::Persion(const Persion & persion)
{
	ptr = new int;
	*ptr = *persion.ptr;
}

Persion::~Persion()
{
	cout << "Persion析构函数已经执行" << endl;
}

void Persion::talkSelf(void)
{
	cout << "我的名字是" << name << "我今年" << age << "岁了" << endl;
	cout << "我的身份证号码是:" <<code << endl;
}
/*需要注意的是，该函数不属于任何的类 ，只是一个函数*/
void printName(Persion persion)
{
	cout << persion.code << endl; // 此处的code 为 private 的
	// 此为友元函数，可以访问对象内部的private  和protected 修饰的属性和方法；
}

void Student::talkSelf(void)
{
	cout<< "我是XXX" <<endl;
}

Student Student::operator+()
{
	
	return Student();
}
