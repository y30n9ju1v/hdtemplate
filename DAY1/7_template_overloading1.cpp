#include <iostream>

// 템플릿과 특정 버전(int) 의 함수를 동시제공 가능합니다.
// 템플릿을 통해서 만들어진 "square(int)" 와
// 사용자가 직접 만든 "square(int)" 의 내부 함수 이름은 다릅니다.
// 이코드 "godbolt.org"에 넣어 보세요

template<typename T> 
T square(T a)
{
	std::cout << "T" << std::endl;
	return a * a;
}
int square(int a)
{
	std::cout << "int" << std::endl;
	return a * a;
}
int main()
{
	square(3);		// int
	square(3.4);	// T
	square<int>(3);	// T
	square<>(3);	// T

}