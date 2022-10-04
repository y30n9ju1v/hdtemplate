#include <iostream>

void cleanup() { std::cout << "cleanup" << std::endl; }

struct Finalizer
{
	void operator()() { std::cout << "Finalizer" << std::endl; }
};
// Finalizer f; // 객체지만
// f();		 // 함수 처럼 사용가능.

// 일반 함수 뿐 아니라 모든 종류의 callable object 에 대해 동작하려면
// ScopedExit 을 템플릿으로 설계
template<typename T> 
class ScopedExit
{
	T handler;
public:
	ScopedExit(T f) : handler(f) {}
	~ScopedExit() { handler(); }
};
int main()
{
	// 1. 일반 함수 등록
	ScopedExit<void(*)()> se1(&cleanup);

	// 2. 함수 객체 등록
	Finalizer f;
	ScopedExit<Finalizer> se2(f);

	// 3. 람다표현식 등록.. (C++14로 놓고 ? 채워 보세요)
//	ScopedExit< ? > se3( []() { std::cout << "lambda" << std::endl; } );

	// 해결책 1. 람다표현식을 auto 변수에 담은후 사용하면 됩니다.
	auto f2 = []() { std::cout << "lambda" << std::endl; };

	ScopedExit<decltype(f2)> sec(f2);

}