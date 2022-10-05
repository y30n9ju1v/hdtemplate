#include <iostream>

// T�� ������ ���� �����ϴ� ����
// T�� Ư���� �����ϴ� traits ����� ���

// 1. primary template �� ����� false ��ȯ(value = false��� �ǹ�)

// 2. ������ �����ϴ� �κ� Ư��ȭ ������ ����� true ��ȯ(value = true)

template<typename T> struct is_pointer
{
	enum { value = false };
};

template<typename T> struct is_pointer<T*>
{
	enum { value = true };
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