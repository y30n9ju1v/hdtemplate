#include <iostream>
#include <type_traits>

// ��� 3. 2���� ���ø� ����

// ��ȯ Ÿ�� ǥ�� 2. decltype Ű���� ���

// decltype(ǥ����) : �����Ϸ����� ǥ������ Ÿ���� ���� �޶�� �ǹ�.
// => �̰��, C++11 ���� ���� ���� "���� ��ȯ Ÿ��" ǥ����� ����ؾ� �մϴ�.
// => ���� Ÿ���� () ���ʿ� ǥ���ϴ� ǥ���
template<typename T1, typename T2>
//decltype(a+b) add(const T1& a, const T2& b)	// error.

auto add(const T1& a, const T2& b) -> decltype(a + b) 
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;  
	std::cout << add(3, 4.3) << std::endl;


//	a = 10; // error. ������ �������� ���
//	int a = 0;
//	a = 20; // ok.. ������ �����Ŀ� ���.
}



