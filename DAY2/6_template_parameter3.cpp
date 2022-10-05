#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

// STL 의 stack 은 실제로 아래 처럼 구현되어 있습니다.

// 핵심 1. STL 의 모든 선형 컨테이너는 template 인자가 2개 입니다.
// std::vector<int, 메모리할당기> v;
// template<typename T, typename Alloc = std::allocator<T>> class vector {};


template<typename T,							 // type 파라미터
	     template<typename, typename > class C > // 인자가 2개인 템플릿
class stack
{
//	C c;	// error. C는 인자가 2개인 template 입니다.	
			// 이 코드는 결국 "std::vector c" 와 동일!
	C<T, std::allocator<T>> c;
			
public:
	void push(const T& value) { c.push_back(value); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
//	std::stack<int, std::vector<int>> s1; // 이 코드가 아니라!!

	stack<int, std::vector> s1; // 이렇게 사용할수 있도록	
									 // 만들어 봅시다.
}

