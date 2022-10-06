#include <iostream>

// fn�� ������ ������ � �Լ��� ������� �����ϴ� ����
// "��ȯ Ÿ��" �� �ƴ� "������ ����"�� ���� ����. 

// SFINAE : Substitution Failure Is Not An Error. 

// 1. �Լ� ���ø��� ����ϱ�� �����ߴµ�..
// 2. T �� Ÿ���� �����ϰ�, �ν��Ͻ�ȭ(�Լ� ����)�ϴٰ� ���� �ߴٸ�..
// 3. ������ �ƴϰ� �ĺ������� ���� �ȴٴ� �ǹ�
// 4. ���� �̸��� �ٸ� �Լ��� �ִٸ� ���ɼ� �ִ�.

template<typename T> 
typename T::type fn(T  a) { std::cout << " T "; return 0; }
// int::type fn(int a) {....}  ��� �Լ��� ����(�ν��Ͻ�ȭ)


int fn(... ) { std::cout << "..."; return 0; }


int main()
{
	fn(3);
}
