#pragma once
#include<vector> // 容器？？？
#include<stdexcept>  // 标准异常

using namespace std;

template <class T> 
class Stack
{
public:
	void push(T const& element); // 入栈
	void pop(); // 删除顶层
	T pop()const; // 返回堆栈顶层元素
	bool isEmpty() const;  // 是否为空 ， 为空返回true
	Stack(const Stack &stack);
	Stack();
private:
	vector<T> elements; // 元素
};

