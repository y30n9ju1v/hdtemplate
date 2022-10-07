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

// concept2.cpp �� �Ʒ� ó�� ���� �˴ϴ�.

void fn(container auto& c)
{
	std::cout << "container" << std::endl;
}

void fn(std::input_iterator auto& c)
{
	std::cout << "iterator" << std::endl;
}

//void fn(std::is_integral_v auto& c) // error. type traits�� �ȵ˴ϴ�.
void fn(std::integral auto& c)  // ok.. is_integral_v �� ���� ����� concept
{
	std::cout << "integer" << std::endl;
}

// traits  : ���� �Ѵٴ� �ǹ̷� ���ξ� "is" ���. is_integral ��
// concept : ������ ������ �ƴ�, �䱸 ������ ����!!! "is" ���ξ� ������


int main()
{
	int n = 10;
	std::vector<int> v = { 1,2,3 };

	auto p = v.begin();

	fn(v); // container
	fn(p); // iterator
	fn(n); // integer
}