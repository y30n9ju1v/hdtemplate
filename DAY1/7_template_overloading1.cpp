#include <iostream>

// ���ø��� Ư�� ����(int) �� �Լ��� �������� �����մϴ�.
// ���ø��� ���ؼ� ������� "square(int)" ��
// ����ڰ� ���� ���� "square(int)" �� ���� �Լ� �̸��� �ٸ��ϴ�.
// ���ڵ� "godbolt.org"�� �־� ������

template<typename T> 
T square(T a)
{
	std::cout << "T" << std::endl;
	return a * a;
}
int square(int a)
{
	std::cout << "int" << std::endl;
	return a * a;
}
int main()
{
	square(3);		// int
	square(3.4);	// T
	square<int>(3);	// T
	square<>(3);	// T

}