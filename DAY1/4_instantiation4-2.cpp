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

// C++17 �������� "Ŭ���� ���ø��� Ÿ���� �ݵ�� ����"�ؾ� �ϹǷ�
// Ŭ���� ���ø��� ��ü�� ���� ����� �׻� �����մϴ�.

// �� ���, �Լ� ���ø��� �����Լ��� �����ϸ� �����մϴ�.

// => "Object Generator" ��� �Ҹ��� �̸��� ���� ��� �Դϴ�.
// => C++17 ������ ���� �θ� ���Ǵ� ���.
template<typename T> 
ScopedExit<T> makeScopedExit(T handler)
{
	return ScopedExit<T>(handler);
}

int main()
{
	Finalizer f;

//	auto se1 = makeScopedExit<void(*)()>(&cleanup); // �̷��� Ÿ���� ������ �ǰ�
	auto se1 = makeScopedExit(&cleanup); // Ÿ���� �����ص� �˴ϴ�.
	auto se2 = makeScopedExit(f);
	auto se3 = makeScopedExit([]() { std::cout << "lambda" << std::endl; });
	
	// C++17 ���Ĵ� Ŭ���� ���ø��� Ÿ�� �߷� �ǹǷ�.. �Ʒ� ó�� ����ϼ���

	ScopedExit se4(&cleanup);
	ScopedExit se5(f);
	ScopedExit se6([]() { std::cout << "lambda" << std::endl; });

}