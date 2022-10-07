#include <iostream>

// fold3.  fold2�����ϼ���


// C++17 fold �� ����ϴ� ���. 
template<typename ... Types>
auto sum1(Types... args)
{
	return (args + ... + 0);
}

// fold expression �� ���� ���(C++11/14)
int sum2() { return 0; }

template<typename T, typename ... Types>
auto sum2(T value, Types... args)
{
	return value + sum2(args...);
}

int main()
{
	auto ret1 = sum1(1, 2, 3, 4, 5);
	auto ret2 = sum2(1, 2, 3, 4, 5);

	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
}
