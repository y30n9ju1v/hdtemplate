#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

// STL 의 stack 은 실제로 아래 처럼 구현되어 있습니다.

// 결국 STL stack 은 선형 컨테이너(std::list, std::vector, std::deque)의 
// 함수이름을 stack 처럼 보이게 변경한 것 입니다.
// "adapter 패턴"

template<typename T, typename C = std::deque<T> > 
class stack
{
	C c;
public:
	void push(const T& value) 	{ c.push_back(value); }
	void pop()            		{ c.pop_back(); }
	T&   top()            		{ return c.back(); }
};

int main()
{
	std::stack<int, std::list<int> > s1;

	s1.push(10); // 결국 "std::list<int>" 의 push_back 으로 보관한것!!!

	stack<int, std::vector<int> > s2;
	stack<int> s3;
	
	// 현재 STL stack 의 위와 거의 동일 합니다.

	// 단점.!!
	std::stack<int, std::vector<int>> s4; // !! int 를 2번 적어야 한다.!!
}

