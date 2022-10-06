#include <iostream>
#include <type_traits>


// enable_if< 조건, T >::type 
// 조건이 참이면   : 최종 결과는 "T"
// 조건이 거짓이면 : ::type 은 없다!

// 아래 코드의 의미
// T의 타입이 정수 계열이면 반환 타입은 "T"
// T의 타입이 정수 계열이아니면 "gcd 템플릿" 사용안함(SFINAE 규칙)
// => 다른 버전(gcd(double)) 사용가능. 

// "T가 정수일때만 사용하겠다" 는 것
template<typename T> 
//typename std::enable_if< std::is_integral_v<T>, T>::type 

std::enable_if_t< std::is_integral_v<T>, T>

gcd(T a, T b)
{
	return 0;
}

double gcd(double a, double b)
{
	std::cout << "double version" << std::endl;
	return 0;
}
int main()
{
	gcd(6, 9);
	gcd(3.1, 5.4);		
	gcd(3.1f, 5.4f);	

}