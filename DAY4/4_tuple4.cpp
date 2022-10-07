#include <iostream>

// 완성된 코드 정리

template<typename ... Types>
struct tuple
{
	static constexpr std::size_t N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;
	T value;
	tuple() = default;
	tuple(const T& v, const Types& ... args)
		: value(v), base(args...) {}
	static constexpr std::size_t N = base::N + 1;
};
int main()
{
	tuple<> t0;									// 3번째 기반
	tuple<             char> t1;				// 2번째 기반, char   값 한개 보관
	tuple<     double, char> t2;				// 1번째 기반, double 값 한개 보관
	tuple<int, double, char> t3(5, 3.4, 'A');	// int 값 한개 보관
}

// tuple.h 만드세요.. 위 tuple 2개 복사 해 놓으세요