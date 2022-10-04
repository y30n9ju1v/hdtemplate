#include <iostream>

void cleanup() { std::cout << "cleanup" << std::endl; }

struct Finalizer
{
	void operator()() { std::cout << "Finalizer" << std::endl; }
};
// Finalizer f; // ��ü����
// f();		 // �Լ� ó�� ��밡��.

// �Ϲ� �Լ� �� �ƴ϶� ��� ������ callable object �� ���� �����Ϸ���
// ScopedExit �� ���ø����� ����
template<typename T> 
class ScopedExit
{
	T handler;
public:
	ScopedExit(T f) : handler(f) {}
	~ScopedExit() { handler(); }
};
int main()
{
	// 1. �Ϲ� �Լ� ���
	ScopedExit<void(*)()> se1(&cleanup);

	// 2. �Լ� ��ü ���
	Finalizer f;
	ScopedExit<Finalizer> se2(f);

	// 3. ����ǥ���� ���.. (C++14�� ���� ? ä�� ������)
//	ScopedExit< ? > se3( []() { std::cout << "lambda" << std::endl; } );

	// �ذ�å 1. ����ǥ������ auto ������ ������ ����ϸ� �˴ϴ�.
	auto f2 = []() { std::cout << "lambda" << std::endl; };

	ScopedExit<decltype(f2)> sec(f2);

}