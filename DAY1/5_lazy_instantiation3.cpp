#include <vector>
#include <queue>

// 핵심 1. vector 는 앞쪽으로 "삽입/삭제" 할수 없습니다.
class queue
{
	std::vector<int> c;
public:
	void push(int a)  {	c.push_back(a);	}
	void pop() 		  {	c.pop_front();	}
};

int main()
{

}