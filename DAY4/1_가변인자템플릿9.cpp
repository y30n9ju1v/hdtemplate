// 1_가변인자템플릿9
#include <iostream>
#include <mutex>

void f1(int n) {}

int main()
{
	f1(10); // 동기화 안되는 함수.

	std::mutex mtx;
	lockAndCall(mtx, f1, 10); // f1(10) 호출을 mtx 로 동기화 해달라
}