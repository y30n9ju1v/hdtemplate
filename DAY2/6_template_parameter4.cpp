#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template<typename T,						
	     template<typename, typename > class C = std::deque,
	     typename Alloc = std::allocator<T>> 
class stack
{
	C<T, Alloc> c;

public:
	void push(const T& value) { c.push_back(value); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};
int main()
{
	stack<int, std::vector> s1;
	stack<int> s2;

	stack<int, std::vector, std::allocator<int> > s3;
						// 도전 과제. std::allocator<int> 가 아닌
						//           std::allocator 를 사용하게 변경해 보세요
}

