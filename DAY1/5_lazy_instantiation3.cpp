#include <vector>
#include <queue>

// 핵심 1. vector 는 앞쪽으로 "삽입/삭제" 할수 없습니다.
class queue
{
	std::vector<int> c;
public:
	// 핵심 2. 현재 queue 는템플릿이 아닙니다.
	// 멤버 함수를 사용하지 않아도 "잘못된 코드가 있으면 에러" 입니다.
	void push(int a)  {	c.push_back(a);	} // ok
	void pop() 		  {	c.pop_front();	} // error
};

int main()
{

}