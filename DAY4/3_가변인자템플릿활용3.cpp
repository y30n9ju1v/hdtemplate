#include <iostream>

int f(int, double, char) { return 0; }


// argument 를 사용하는 코드를 보고 primary template 을 만듭니다.
template<int N, typename T> struct argument
{
	using type = T;
};
// 원하는 것(인자의 타입)을 얻을수 있도록 부분 특수화 합니다.
// =>> 핵심!!! 어떻게 부분 특수화 해야 하는가 ?? 를 생각해야 합니다.
// => N=0 인 경우를 먼저 생각해야 합니다
/*
template<typename T> struct argument<0, T>
{
	// T에서 0번째 인자의 타입을 구할수 있을까요 ?
	// => 구할수 없습니다. 잘못된 부분 특수화!!
	using type = ?;
};
*/

/*
template<typename R, typename ... Types> 
struct argument<0, R(Types...)>
{
	// 현재 코드는 리턴 타입 "R"은 구할수 있습니다
	// 0번째 인자의 타입을 구할수 있을까요 ?
	// => 안됩니다. 잘못된 부분 특수화
	using type = ? ;
};
*/
// N = 0 인 경우를 구하기 위한 부분 특수화 
template<typename R, typename T, typename ... Types>
struct argument<0, R(T, Types...)>
{
	using type = T ;
};

// N != 0 인 경우..
template<int N, typename R, typename T, typename ... Types>
struct argument<N, R(T, Types...)>
{
	// int(int, double, char) 의 2번째 인자는
	// int(     double, char) 의 1번째 인자와 같고
	// int(             char) 의 0번째 인자와 같습니다.

	// 0번째 인자 "T" 를 제거한 함수에서 N-1 번째 인자 타입 구하기
	using type = typename argument<N - 1, R(Types...)>::type;
};

template<typename T> void foo(T& t)
{
	// T : int(int, double, char)
	typename argument<1, T>::type n;

	std::cout << typeid(n).name() << std::endl; // double
}

int main()
{
	foo(f);
}