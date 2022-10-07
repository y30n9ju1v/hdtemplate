#include <iostream>

// Step 2. 요소 한개 보관하기 

template<typename ... Types>
struct tuple
{
	static constexpr std::size_t N = 0; 
};

// tuple 의 타입 인자가 최소 한개 이상 있는 경우의 부분 특수화
template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;
	tuple(const T& v) : value(v) {}

	static constexpr std::size_t N = 1;
};

int main()
{
	tuple<> t0;
	tuple<char> t1;					// char   값 한개 보관
	tuple<double, char> t2;			// double 값 한개 보관

	tuple<int, double, char> t3(5); // int 값 한개 보관
}
