#pragma once
#include<string>
#include"SnackConsole.h"
namespace snack_n {
	// 贪吃蛇小游戏，蛇的定义类型，

// 蛇的身体，设计成一个类型，该类型应有一个方向枚举，持有一个content 类的实例，
//蛇的头部舌设计为一个特殊的身体，其有方向枚举，但是没有preve对象
// 蛇有两个方法 （左转 ，和右转）
// 蛇面部朝向的枚举类型
	enum SNACK_FACE_DIRECTION
	{
		UP, DOWN, LEFT, RIGHT
	};
	// 蛇身体的链表，如果 next 为空则为尾巴，prev 为空则为头，其他的为身体
	// 前进的时候是x+1 还是Y+1 ，？？
	// 前进的时候判断前面一个的朝向是否和自己不一样，如果不一样的话则修改朝向同步至和前面的一样
	struct  SnackBody
	{
		// 方向枚举
		SNACK_FACE_DIRECTION direction;
		// 后面一个
		SnackBody *next;
		// 前面一个
		SnackBody *prev;
		// 位置 头部为0
		int index;
		// x坐标
		int X;
		// Y坐标
		int Y;
	};

	class Snack
	{
	public:
		Snack(const console_n::SnackConsole &console);
		~Snack();
		// 左转方法
		void turnLeft();
		// 右转方法
		void turnRight();
		// 判断是否存活
		bool isLive();
		// 设置速度( 计划是 0--10)
		void setSpeed(int speed);
		// 速度+1 到10 不变
		void speedAdd();
		// 速度-1 到0 不变
		void speedSubtract();
		// 移动(根据速度,方向 进行移动)
		void move();
	private:
		// 指示当前朝向(头部)
		static SNACK_FACE_DIRECTION direction;
		const console_n::SnackConsole console;
	};


}
