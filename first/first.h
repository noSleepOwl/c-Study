#pragma once


#include "pch.h"
#include <iostream>

using namespace std;
// ȫ�ֱ���
static int gloable = 0;
// ����������
void function();

int count_extern;

// extern ��һ�ֻ�ȡ�ķ�ʽ��ָʾ���������ñ������߷����Ѿ��ڱ���ļ��������ˣ������ٴεĽ��г�ʼ�� ��
// ���� extern int a = 0 �÷����ᱨ�ظ������Ĵ�����Ϊ���������������ļ��г�ʼ������
extern  void write_extern(void);


int max(int a, int b);
//����ʹ��ָ����� �ú���������X ��Y ��ֵ
void swap(int *x, int *y);
/*���ô��ݣ������ڽ� ��Ӧ�ı���ָ����ڴ� �ٴεĽ��и�ֵ��Ūһ������һ���Ķ���*/
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
