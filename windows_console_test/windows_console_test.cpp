
#include "pch.h"
#include<iostream>
#include<Windows.h>
using std::cout;
using std::endl;

void main()
{
	for (int i = 0; i < 100; i++) {
		Sleep(100);
		system("cls");
		cout << i << endl;
	}

}

