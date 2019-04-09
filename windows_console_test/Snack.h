#pragma once
#include<string>

// 贪吃蛇小游戏，蛇的定义类型，

// 蛇的身体，设计成一个类型，该类型应有一个方向枚举，持有一个content 类的实例，
//蛇的头部舌设计为一个特殊的身体，其有方向枚举，但是没有preve对象
// 蛇有两个方法 （左转 ，和右转）
// 蛇面部朝向的枚举类型
enum SNACK_FACE_DIRECTION
{
	UP,DOWN,LEFT,RIGHT
};
// 蛇身体的链表，如果 next 为空则为尾巴，prev 为空则为头，其他的为身体
// 前进的时候是x+1 还是Y+1 ，？？
// 前进的时候判断前面一个的朝向是否和自己不一样，如果不一样的话则修改朝向同步至和前面的一样

struct  SnackBody
{
	SNACK_FACE_DIRECTION direction;
	SnackBody *next;
	SnackBody *prev;
	int index;
	int X;  // x 位置
	int Y; // y 位置
};

class Snack
{
public:
	Snack();
	~Snack();
	void turnLeft(); // 左转方法
	void turnRight();// 右转方法
	bool isLive();  // 判断是否存活
};

