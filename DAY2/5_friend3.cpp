#include <iostream>

template<typename T> 
void fn(T a)   { std::cout << "T" << std::endl; }

void fn(int n);// { std::cout << "int" << std::endl; }


int main()
{
	fn(3.3);	// fn(T) ���

	fn(3);		// fn(int) ���
				// fn(int) �� ���ٸ�       : fn(T) ���
				// fn(int) �� ���� �ִٸ� : ��ũ ���� �߻�

	// ��, fn(T) �� �־, int ������ ������ �ִٸ�
	// ��Ŀ�� int ������ ã������ �õ��ϰ�, ������ ��ũ ����.
}