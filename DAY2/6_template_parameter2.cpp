#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

// STL �� stack �� ������ �Ʒ� ó�� �����Ǿ� �ֽ��ϴ�.

// �ᱹ STL stack �� ���� �����̳�(std::list, std::vector, std::deque)�� 
// �Լ��̸��� stack ó�� ���̰� ������ �� �Դϴ�.
// "adapter ����"

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

	s1.push(10); // �ᱹ "std::list<int>" �� push_back ���� �����Ѱ�!!!

	stack<int, std::vector<int> > s2;
	stack<int> s3;
	
	// ���� STL stack �� ���� ���� ���� �մϴ�.

	// ����.!!
	std::stack<int, std::vector<int>> s4; // !! int �� 2�� ����� �Ѵ�.!!
}

