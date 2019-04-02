#include "pch.h"
#include "Stack.h"

template<class T>
Stack<T>::Stack(const Stack & stack)
{
	stack.elements.vector(elements);
}

template<class T>
Stack<T>::Stack()
{
}

template<class T>
void Stack<T>::push(T const & element)
{
	elements.push_back(element);
}

template<class T>
void Stack<T>::pop()
{
	if (isEmpty) {
		throw out_of_range("pop error ");
	}
	elements.pop_back();
}

template<class T>
T Stack<T>::pop() const
{
	if (isEmpty) {
		throw out_of_range("pop get  error");
	}
	return elements.back();
}

template<class T>
bool Stack<T>::isEmpty() const
{
	return elements.empty();
}


