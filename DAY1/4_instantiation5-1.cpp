#include <iostream>
#include <functional>
#include <type_traits> // std::type_identity

template<typename T>
void foo(T a, T b)
{
}

// C++20 안되시는 분은 "type_identity" 복사해 오세요
template<typename T>
void goo(T a, typename std::type_identity<T>::type  b)
{
}

int main()
{
	foo(3.4, 10);	// error. 타입 전달을 안했으므로 "함수인자로 결정"해야 하는데
					// 1번째 인자를 보면 "double"
					// 2번째 인자를 보면 "int" 이므로 타입 결정 안됨

	goo(3.4, 10);	// ok.. 1번째 인자로만 타입 결정
					// 2번째 인자의 타입은 무조건 1번째와 같은 타입
					// goo(double, double) 로 결정
					// 2번째 인자는 "10" 은 double로 전달 가능
}