#pragma once
#include<string>
#include<iostream>
// 导入string 需要使用
using namespace std;
class Persion
{
public:
	string name; 
	int age;
	static string countory;
	Persion();
	Persion(string name,int age);
	Persion(const Persion &persion);
	~Persion();
	friend void printName(Persion persion);
	// 可以 先声明 , 之后进行实现 
	void talkSelf(void);
	// 声明并且实现
	void talkSelf_2(void) {
		cout << "我的名字是" << name << "我今年" << age << "岁了" << endl;
	}
private :
	string code = "3203212155456456464";
	int *ptr;
};


class Student : public Persion {
public :
	string school;
	void talkSelf(void);
	Student operator+();
};

