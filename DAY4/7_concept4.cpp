#include <iostream>
#include <type_traits>
#include <vector>
#include <iterator>
#include <concepts>

template<typename T>
concept container = requires(T & c)
{
	std::begin(c);
	std::end(c);
};

// concept2.cpp 는 아래 처럼 만들어도 됩니다.

void fn(container auto& c)
{
	std::cout << "container" << std::endl;
}

void fn(std::input_iterator auto& c)
{
	std::cout << "iterator" << std::endl;
}

//void fn(std::is_integral_v auto& c) // error. type traits는 안됩니다.
void fn(std::integral auto& c)  // ok.. is_integral_v 와 같은 기능의 concept
{
	std::cout << "integer" << std::endl;
}

// traits  : 조사 한다는 의미로 접두어 "is" 사용. is_integral 등
// concept : 조사라는 개념이 아닌, 요구 조건의 정의!!! "is" 접두어 사용안함


int main()
{
	int n = 10;
	std::vector<int> v = { 1,2,3 };

	auto p = v.begin();

	fn(v); // container
	fn(p); // iterator
	fn(n); // integer
}