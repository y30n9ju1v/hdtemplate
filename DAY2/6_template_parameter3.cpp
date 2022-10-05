#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

// STL �� stack �� ������ �Ʒ� ó�� �����Ǿ� �ֽ��ϴ�.

// �ٽ� 1. STL �� ��� ���� �����̳ʴ� template ���ڰ� 2�� �Դϴ�.
// std::vector<int, �޸��Ҵ��> v;
// template<typename T, typename Alloc = std::allocator<T>> class vector {};


template<typename T,							 // type �Ķ����
	     template<typename, typename > class C > // ���ڰ� 2���� ���ø�
class stack
{
//	C c;	// error. C�� ���ڰ� 2���� template �Դϴ�.	
			// �� �ڵ�� �ᱹ "std::vector c" �� ����!
	C<T, std::allocator<T>> c;
			
public:
	void push(const T& value) { c.push_back(value); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
//	std::stack<int, std::vector<int>> s1; // �� �ڵ尡 �ƴ϶�!!

	stack<int, std::vector> s1; // �̷��� ����Ҽ� �ֵ���	
									 // ����� ���ô�.
}

