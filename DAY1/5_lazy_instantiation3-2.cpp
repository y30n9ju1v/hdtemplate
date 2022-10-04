#include <vector>
#include <queue>
#include <list>
#include <deque>
// 실제 STL의 queue는 아래와 같습니다.
template<typename T, typename C = std::deque<T> > class queue
{
	C c;
public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_front(); }
};

int main()
{
	// STL queue 사용시 내부 컨테이너로는 vector를 사용하면 안됩니다.
	std::queue<int> q; // ok.  deque 사용
	std::queue<int, std::list<int>> q1;   // ok
	std::queue<int, std::vector<int>> q2; // 이렇게 하면 안됩니다.

	q2.push(10); // ok
	q2.pop(); // error
}