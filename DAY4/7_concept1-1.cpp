#include <iostream>
#include <vector>
#include <type_traits>

// Container 라는 개념(Concept)을 설계해 봅시다.

template<typename T>
concept container = requires(T& c)
{
	// 의미 : 컨테이너는 begin(), end() 멤버 함수가 있어야 한다.
	// c.begin();
	// c.end();
	
	// 의미 : 컨테이너는 std::begin()/std::end() 의 인자가 될수 있는 것이다.
	std::begin(c);
	std::end(c);
};
template<typename T> void check(T& c)
{
	// T 가 "container" 요구 조건을 만족하는지 조사하려면
	// 아래 처럼 합니다.
	// 컴파일 시간에 조사하게 됩니다.
	std::cout << container<T> << std::endl;
}
int main()
{
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n);
	check(v);
	check(x);
}