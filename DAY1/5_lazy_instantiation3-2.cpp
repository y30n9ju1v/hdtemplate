#include <vector>
#include <queue>
#include <list>
#include <deque>
// ���� STL�� queue�� �Ʒ��� �����ϴ�.
template<typename T, typename C = std::deque<T> > class queue
{
	C c;
public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_front(); }
};

int main()
{
	// STL queue ���� ���� �����̳ʷδ� vector�� ����ϸ� �ȵ˴ϴ�.
	std::queue<int> q; // ok.  deque ���
	std::queue<int, std::list<int>> q1;   // ok
	std::queue<int, std::vector<int>> q2; // �̷��� �ϸ� �ȵ˴ϴ�.

	q2.push(10); // ok
	q2.pop(); // error
}