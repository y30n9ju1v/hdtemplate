#include <iostream>
#include <type_traits>

// ���� C++�� "Ư�� Ÿ��" �� ���� �Լ� �����ε���
// ���� �մϴ�.
void foo(int)    {}
void foo(double) {}


// "Ÿ��"�� �ƴ� "Ư�� ������ �����ϴ� Ÿ�Ե�"�� ���� �����ε��� ������
// ���� ������� ?
// void goo(�����Լ����ִ�Ŭ������) {}
// void goo(�����Լ�������Ŭ������) {}


// enable_if �� "���� Ÿ��"�� ����ϴ� ��찡 ���� �����ϴ�.
// 
// �Լ� ���ø��� ������ �����Ҷ��� ����Ϸ��� "����Ÿ��"�� �Ʒ�ó���ϼ���
// 
// => std::enable_if_t<����, ����Ÿ��>
// => std::enable_if_t<����>   // ����Ÿ���� void ��� Ÿ�Ի����ص� �˴ϴ�.


template<typename T> 
std::enable_if_t< std::is_polymorphic_v<T> >
goo(T arg)
{
	std::cout << "�����Լ��� �ִ� Ÿ�Կ� ���� �˰���" << std::endl;
}
template<typename T>
std::enable_if_t< !std::is_polymorphic_v<T> >
goo(T arg)
{
	std::cout << "�����Լ��� ���� Ÿ�Կ� ���� �˰���" << std::endl;
}
struct AAA
{
	virtual void foo() {}
};

int main()
{
	AAA a;
	int n = 0;
	goo(a);
	goo(n);
}