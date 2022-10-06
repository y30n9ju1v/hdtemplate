#include <iostream>

class Test
{
public:
	int size() { return 10; }
};
int main()
{
	// 목표 : Test 클래스 안에 "size()" 라는 함수가 있는지 조사해 봅시다.
	bool b = has_size_function<Test>::value; // true 나와야 합니다.
}



// cppreference.com  접속해서
// 1번째 화면에서 왼쪽 "named requirement" 선택후
// Allocator 찾아 보세요.
