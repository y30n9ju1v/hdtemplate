// 1_가변인자템플릿9
#include <iostream>
#include <mutex>

void f1(int n) {}
void f2(int n, double d) {}

/*
// 아래 처럼 만들면 인자가 한개인 함수만 사용할수 있습니다.
template<typename MUTEX, typename F, typename ARG>
void lockAndCall(MUTEX& mtx, F f, ARG arg)
{
	std::lock_guard<MUTEX> g(mtx);
	f(arg);
}
*/

/*
// 아래 처럼 만들면 인자 갯수에 제한이 없이 사용가능합니다.
// => 가변인자 함수 템플릿은 이런 경우에 가장 많이 사용합니다.
template<typename MUTEX, typename F, typename ... ARGS>
void lockAndCall(MUTEX& mtx, F f, ARGS ... args)
{
	std::lock_guard<MUTEX> g(mtx);
	
	f(args...);
}
*/

// 정확히는 아래 처럼 "완벽한 전달(modern C++ 참고)" 을 사용해야 합니다.
template<typename MUTEX, typename F, typename ... ARGS>
inline void lockAndCall(MUTEX& mtx, F f, ARGS&& ... args)
{
	std::lock_guard<MUTEX> g(mtx);

	f( std::forward<ARGS>(args) ... );
}

int main()
{
	f1(10); // 동기화 안되는 함수.
	std::mutex mtx;
	lockAndCall(mtx, f1, 10); // f1(10) 호출을 mtx 로 동기화 해달라
	lockAndCall(mtx, f2, 10, 3.4);
}
// 위 예제는 "effective modern C++" 에 있는 예제 입니다.