#include <iostream>
#include <type_traits>

// C++20 이전에는 "auto" 를 함수 인자로 사용할수 없습니다.
// C++20 부터는   "auto" 를 함수 인자로 사용할수 있습니다.

// 아래 코드는 "template_return_type6.cpp" 의 add 와 완벽히 동일합니다.
// 단, C++20 부터 가능
// 아래 코드에서 a, b 는 서로 다른 템플릿 입니다.
auto add(const auto& a, const auto & b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3, 4.3) << std::endl;


}



