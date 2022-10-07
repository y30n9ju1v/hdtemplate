#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args 에 있는 모든 요소를 꺼내고 싶다면
	// 
	// args 안에 있는 2번째 값을 얻고 싶다.
	// => 한번에 할수 있는 방법은 없습니다.

	// 아래 3개 방법 중에 한개를 사용해야 합니다.
	// 1. pack expansion		- C++11
	// 2. recursive 와 유사한 기술 - C++11
	// 3. fold expression - C++17

	// 방법 1. pack expansion

	// 1. 모든 요소가 동일 타입이면 배열 또는 std::initializer_list 에 담아서 사용하세요

	//	int x[] = { args... };	// int x[] = {1,2,3}
								// args 가 비어 있는 경우 error

	std::initializer_list<int> x = { args... }; // ok
									// args 가 비어 있어도 됩니다.
	// x 에 요소 접근은 반복자로 하면 됩니다.
	auto p1 = x.begin();


	// 2. 요소의 타입이 다른 경우는 tuple 에 담을수 있습니다.
	std::tuple<Types...> tp(args...);

	std::cout << std::get<0>(tp) << std::endl; // 1번째 요소 접근

}

int main()
{
	foo(1, 2, 3);
}

