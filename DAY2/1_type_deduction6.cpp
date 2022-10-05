// 2�� �����ؿ�����
#include <iostream>
#include "fname.h"

// �ٽ� : template �� �迭 ����

template<typename T> void f1(T arg)
{
	std::cout << _FNAME_ << std::endl;
}

template<typename T> void f2(T& arg)
{
	std::cout << _FNAME_ << std::endl;
}

int main()
{
	int x[3] = { 1,2,3 };

	f1(x);	// 1. f1( int arg[3]) �� ������ٸ� ����, �迭�� ���� �ɼ� ����
			// 2. f1( int* arg ) <== �׷��� �� ����� �Լ� ����

	f2(x);	// f2( int(&arg)[3] ). �� �迭�� ����Ű�� ����
			// ���� �ƴ�
			// T=int[3],  arg = int(&)[3] ���� ������.

	// ����. �迭�� ���ø��� �����ϴ� ���
	f1(x);  // T=int*   arg=int*
	f2(x);	// T=int[3] arg=int(&)[3]

	// f1 ó��. �迭�� �����Ҷ� �����ͷ� ��ȯ �Ǿ �޴� ����
	// "decay" ��� �մϴ�

}
