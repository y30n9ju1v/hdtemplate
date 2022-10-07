// 1_�����������ø�9
#include <iostream>
#include <mutex>

void f1(int n) {}
void f2(int n, double d) {}

/*
// �Ʒ� ó�� ����� ���ڰ� �Ѱ��� �Լ��� ����Ҽ� �ֽ��ϴ�.
template<typename MUTEX, typename F, typename ARG>
void lockAndCall(MUTEX& mtx, F f, ARG arg)
{
	std::lock_guard<MUTEX> g(mtx);
	f(arg);
}
*/

/*
// �Ʒ� ó�� ����� ���� ������ ������ ���� ��밡���մϴ�.
// => �������� �Լ� ���ø��� �̷� ��쿡 ���� ���� ����մϴ�.
template<typename MUTEX, typename F, typename ... ARGS>
void lockAndCall(MUTEX& mtx, F f, ARGS ... args)
{
	std::lock_guard<MUTEX> g(mtx);
	
	f(args...);
}
*/

// ��Ȯ���� �Ʒ� ó�� "�Ϻ��� ����(modern C++ ����)" �� ����ؾ� �մϴ�.
template<typename MUTEX, typename F, typename ... ARGS>
inline void lockAndCall(MUTEX& mtx, F f, ARGS&& ... args)
{
	std::lock_guard<MUTEX> g(mtx);

	f( std::forward<ARGS>(args) ... );
}

int main()
{
	f1(10); // ����ȭ �ȵǴ� �Լ�.
	std::mutex mtx;
	lockAndCall(mtx, f1, 10); // f1(10) ȣ���� mtx �� ����ȭ �ش޶�
	lockAndCall(mtx, f2, 10, 3.4);
}
// �� ������ "effective modern C++" �� �ִ� ���� �Դϴ�.