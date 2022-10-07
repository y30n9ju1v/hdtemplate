#include <iostream>

int f(int a, double b) { return 0; }

template<typename T> struct result
{
	using type = T;
};

// 1번예제는 "인자가 2개인 함수" 만 사용가능합니다
// 모든 함수의 반환 타입을 구할수 있게 변경해 봅시다.

template<typename R, typename ... Types>
struct result<R(Types... )>
{
	using type = R;
};

template<typename T> void foo(T& a)
{
	// T : int(int, double) 입니다.
	typename result<T>::type n;  // int 

	std::cout << typeid(n).name() << std::endl;
}


int main()
{
	foo(f);
}