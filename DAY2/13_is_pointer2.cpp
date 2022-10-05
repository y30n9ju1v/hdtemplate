#include <iostream>

// T�� ������ ���� �����ϴ� ����
// T�� Ư���� �����ϴ� traits ����� ���

// 1. primary template �� ����� false ��ȯ(value = false��� �ǹ�)
// 2. ������ �����ϴ� �κ� Ư��ȭ ������ ����� true ��ȯ(value = true)

// is_pointer ���� ���� "������ �ð��� ����ϴ� ��Ÿ �Լ�" ��� �մϴ�.

template<typename T> struct is_pointer
{
//	bool value = false; // 1. C++�������� �̷��� ���� �ʱ�ȭ �ȵ˴ϴ�.
						// 2. �̷��� �ϸ� value �� ����� �ƴ� "����" �Դϴ�.

//	enum { value = false }; // C++11 ���� ����ϴ� ���
							// C++98 ������ ����ü �ȿ��� �ʱ�ȭ �ǰ�
							// ������ �ð� ����� ����ϴ� �����
							// enum �ۿ� �����ϴ�. 
							// "enum hack" �̶�� �մϴ�.

	static constexpr bool value = false; // C++11 ��Ÿ��!!
							// ���� : value �� bool Ÿ�� �Դϴ�.
							// static constexpr �� �ܺ� ���� �ʿ�����ϴ�.
};


template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true;
};



template<typename T> 
void fn(const T& arg)
{
	// ���� T�� int, int* 
	if (  is_pointer<T>::value  )
		std::cout << "pointer" << std::endl;
	else
		std::cout << "not pointer" << std::endl;
}

int main()
{
	int n = 0;
	fn(n);
	fn(&n);
}