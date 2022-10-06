#include <iostream>
#include <type_traits>

// 최대 공약수를 구하는 함수를 생각해 봅시다.
template<typename T> T gcd(T a, T b)
{
	// 현재 템플릿을 정수일때만 사용하게 해봅시다.
	static_assert( std::is_integral_v<T>, "error, T is not integer");

	return 0;// 구현은 생략.. 
}

double gcd(double a, double b)
{
	std::cout << "double version" << std::endl;
	return 0;
}

int main()
{
	gcd(6, 9);

	gcd(3.1,  5.4);
}