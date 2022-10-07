#include <iostream>
#include <vector>
#include <type_traits>

// Concept : C++20 �� Big4 �� �Ѱ�.  1~2 ��° ����� ������ �ٽ����� �ٽ�
// 
// C++20 Big4 : Concept, Module(#include ��� import), coroutine, range


template<typename T> void check(T& c)
{
	// T �� ������ Ÿ�� ���� �˰� �ʹ�.

	bool b = std::is_pointer_v<T>;
	// => type traits ���
	// => ��κ� ���ø� Ư��ȭ, �κ� Ư��ȭ�� ����
	// => C++11 ���


	// T �� �����̳� ���� �˰� �ʹ�. ??
	// => ��� �����ؾ� �ұ� ? �� �߿��Ѱ� �ƴ϶�!!
	// => "�����̳�"�� ���Ǹ� ��� �ؾ� �ұ�? �� �߿� �մϴ�.

	// C++20 ����, "named requirement" 
	// => ����ȭ�� ����
	// => cppreference.com ���� "���ʿ��� named requirement"

	// C++20 Concept
	// => Ÿ���� ������ �ϴ� �䱸������ "����ȭ"�� �ƴ� �ڵ�� ǥ���ϴ� ����
}



int main()
{
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n);	
	check(v);	
	check(x);   
}