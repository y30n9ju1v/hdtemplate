// 1_�����������ø�9
#include <iostream>
#include <mutex>

void f1(int n) {}

int main()
{
	f1(10); // ����ȭ �ȵǴ� �Լ�.

	std::mutex mtx;
	lockAndCall(mtx, f1, 10); // f1(10) ȣ���� mtx �� ����ȭ �ش޶�
}