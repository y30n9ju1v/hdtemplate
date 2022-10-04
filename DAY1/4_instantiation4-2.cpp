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

// C++17 이전에는 "클래스 템플릿에 타입을 반드시 전달"해야 하므로
// 클래스 템플릿의 객체를 직접 만들면 항상 복잡합니다.

// 이 경우, 함수 템플릿을 도움함수로 제공하면 편리합니다.
template<typename T> 
ScopedExit<T> makeScopedExit(T handler)
{
	return ScopedExit<T>(handler);
}

int main()
{
	Finalizer f;

//	auto se1 = makeScopedExit<void(*)()>(&cleanup); // 이렇게 타입을 보내도 되고
	auto se1 = makeScopedExit(&cleanup); // 타입을 생략해도 됩니다.
	auto se2 = makeScopedExit(f);
	auto se3 = makeScopedExit([]() { std::cout << "lambda" << std::endl; });
}