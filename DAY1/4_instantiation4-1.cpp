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



}