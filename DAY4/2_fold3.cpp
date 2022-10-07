#include <iostream>

// fold3.  fold2복사하세요


// C++17 fold 를 사용하는 경우. 
template<typename ... Types>
auto sum1(Types... args)
{
	return (args + ... + 0);
}

// fold expression 이 없는 경우(C++11/14)
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
