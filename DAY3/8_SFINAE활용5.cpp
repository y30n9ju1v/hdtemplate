#include <iostream>

class Test
{
public:
	Test(int a) {}	// �� �����ڰ� �����Ƿ� 
					// ���� "Test"�� ����Ʈ �����ڴ� �����ϴ�

	int size() { return 10; }
};

// �Ʒ� �ڵ带 �߻����� ������
template<typename T> T declval(); // ������ �����ϴ�. ����!!
								// �򰡵��� ���� ǥ���Ŀ���
								// ������ ��翡 ������� 
								// ��ü�� �����Ѵٰ� �����Ҷ� ����մϴ�.
								// C++11 ���� ǥ�ؿ� �߰�.


//template<typename T> void check(decltype( declval<T>().size())*)
template<typename T> void check(decltype(std::declval<T>().size())*)
{
	std::cout << "T" << std::endl;
}

template<typename T> void check(...)
{
	std::cout << "..." << std::endl;
}

int main()
{
	check<Test>(0);
}