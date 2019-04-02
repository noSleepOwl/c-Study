#include "pch.h"
#include "read_file.h"

namespace content_name_space {
	namespace first {
		void firstNamespaceTalk() {
			cout << "I'am from first namespace" << endl;
		}
	}
	namespace second {
		void secondNamespaceTalk() {
			cout << "I'am from second namespace " << endl;
		}
	}

}
using namespace content_name_space;
using namespace content_name_space::second;

template <typename T>

inline T const & max(T const & a, T const &b) {
	return a > b ? a : b;
}



int main()
{
	vector<int> ve;

	for (int i = 0; i < 10; i++) {
		ve.push_back(i);
	}
	cout << ve.size ()<< endl;
	
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

