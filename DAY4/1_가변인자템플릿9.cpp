// 1_�����������ø�9
#include <iostream>
#include <mutex>

void f1(int n) {}


template<typename MUTEX, typename F, typename ARG>
void lockAndCall(MUTEX& mtx, F f, ARG arg)
{
	std::lock_guard<MUTEX> g(mtx);
	f(arg);
}

int main()
{
	f1(10); // ����ȭ �ȵǴ� �Լ�.

	std::mutex mtx;

	lockAndCall(mtx, f1, 10); // f1(10) ȣ���� mtx �� ����ȭ �ش޶�
}