#include <iostream>

// SFINAE �� ����Ǵ� 3���� ���

void fn(...) { std::cout << "..." << std::endl; }

// 1. �Լ��� ���� Ÿ���� �����Ҷ� "SFINAE" ����
// => T=int ��� �Ʒ� �ڵ�� "�Լ� ������ ����", ������ ������ �ƴϰ�, 
//    fn(...) ���
//template<typename T> 
//typename T::type fn(T a) { }


// 2. �Լ��� ���� ���
// template<typename T>
//void fn(T a, typename T::type b) { }
	// (int a, int::type b)

// 3. ���ø� ������ ���
// => �����ڴ� "��ȯ Ÿ��"�� �����ϴ�.
// => �����ڿ� "SFINAE" ����� �����Ҷ� �� ����� �ַ� ���.
template<typename T, typename T2 = typename T::type >
void fn(T a) { }

int main()
{
	fn(3);
}
