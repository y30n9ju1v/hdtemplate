#include <iostream>

void cleanup() { std::cout << "cleanup" << std::endl; }

struct Finalizer
{
	void operator()() { std::cout << "Finalizer" << std::endl; }
};

//----------------------------------------
// 29 page Object Generator
class ScopedExit
{
	void(*handler)();
public:
	ScopedExit( void(*f)() ) : handler(f) {}
	~ScopedExit() { handler(); }
};

int main()
{	
	// �Լ� �������� �ݵ�� �����ؾ� �ϴ� �Լ��� �ִٸ�
	// �Լ��� ó�������Ҷ� ����ϼ���
	ScopedExit se1(&cleanup);

	//....

//	cleanup();	// main �Լ��� ����Ǳ����� �ݵ�� ���Լ��� ȣ���ؾ� �Ѵٰ�
				// ������ ���ô�.
				// => �̷��� ���� ȣ���ϴ� ���� �������� �ʽ��ϴ�.
				// => main �Լ� ������, "����" ���� ��Ȳ�� �߻��ϸ� 
				//    cleanup �� ������� �ʽ��ϴ�.
}