#include <iostream>
#include <type_traits>

// 방법 3. 2개의 템플릿 인자
// => 반환 타입을 표기할수 있어야 한다.
// => "다양한 방법이 있습니다... 이어지는 예제들 참고..."
template<typename T1, typename T2>
?  add(const T1& a, const T2& b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;   // int, int
	std::cout << add(3, 4.3) << std::endl; // int, double
}



