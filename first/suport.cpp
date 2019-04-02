#include"pch.h"
#include<iostream>


using namespace std;

extern int count_extern;

extern int gloable; 

void write_extern(void) {
	cout << count_extern << endl;
	//cout << "I'am from first gloable is :" << gloable << endl;
}