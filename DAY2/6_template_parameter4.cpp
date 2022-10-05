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
						// ���� ����. std::allocator<int> �� �ƴ�
						//           std::allocator �� ����ϰ� ������ ������
}

