#include <iostream>

void cleanup() { std::cout << "cleanup" << std::endl; }

struct Finalizer
{
	void operator()() { std::cout << "Finalizer" << std::endl; }
};

//----------------------------------------
// 29 page Object Generator
class ScopedExit
{
	void(*handler)();
public:
	ScopedExit( void(*f)() ) : handler(f) {}
	~ScopedExit() { handler(); }
};

int main()
{	
	// 함수 마지막에 반드시 실행해야 하는 함수가 있다면
	// 함수가 처음시작할때 등록하세요
	ScopedExit se1(&cleanup);

	//....

//	cleanup();	// main 함수가 종료되기전에 반드시 이함수를 호출해야 한다고
				// 가정해 봅시다.
				// => 이렇게 직접 호출하는 것은 안전하지 않습니다.
				// => main 함수 실행중, "예외" 등의 상황이 발생하면 
				//    cleanup 이 실행되지 않습니다.
}