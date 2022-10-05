// 2�� �����ؿ�����
#include <iostream>
#include "fname.h"

// �ٽ� : template �� �迭 ����

template<typename T>
void f1(T a, T b)
{
	std::cout << _FNAME_ << std::endl;
}
template<typename T> 
void f2(T& a, T& b)
{
	std::cout << _FNAME_ << std::endl;
}
int main()
{
	// "orange" : const char[7]
	// "apple"  : const char[6]
	f1("orange", "apple");	// ok
							// 1, 2 ��° ���ڴ� �迭 �ε�.. ������ �����Ƿ�
							// const char*, const char* �� �ް� �˴ϴ�.

	f2("orange", "apple"); // error. �� �����ϱ�� ??
							// �迭�� ������ ������ "�迭"�� �ް� �˴ϴ�.
							// 1, 2��° ���ڴ� ũ�Ⱑ �ٸ� �迭 �̹Ƿ�
							// �ٸ� Ÿ���Դϴ�.

	f3("orange", "banana"); // ok.. ���ڿ� ���̰� �����Ƿ� ���� Ÿ��

}
