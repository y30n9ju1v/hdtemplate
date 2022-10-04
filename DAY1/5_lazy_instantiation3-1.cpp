#include <vector>
#include <queue>


template<typename T> class queue
{
	std::vector<T> c;
public:
	void push(const T&  a)  { c.push_back(a); } 
	void pop()				{ c.pop_front(); } 
};

int main()
{
	queue<int> q;
	q.push(10);
//	q.pop();  // 이 코드가 있으면 에러
}