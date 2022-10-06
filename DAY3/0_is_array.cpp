#include <iostream>
#include <type_traits>

template<typename T> 
void fn(T& arg)
{
	// �ٽ� 1. C++ ǥ�ؿ� "std::is_array" �ֽ��ϴ�.
	std::cout << std::is_array<T>::value << std::endl;

	// �ٽ� 2. ���� ������ "is_array<T>::size" �� ũ�� ���߽��ϴ�.
	// => ������, ǥ�ؿ����� �Ʒ�ó�� �迭�� ũ�⸦ ���ؾ� �մϴ�.
	std::cout << std::extent<T, 0>::value << std::endl; // 3	
	std::cout << std::extent<T, 1>::value << std::endl; // 2

	// 1���迭�� ���� �Ʒ� ó�� ���ص� �˴ϴ�.
	std::cout << std::size(arg) << std::endl; // 3
}
// ���� !! �Ʒ� ó�� "value" �� �޴� ���
// �迭�� ������ �����ͷ� �ް� �ǹǷ� "is_array<T>::value" �� �׻� false�Դϴ�.
template<typename T>
void fn2(T arg)
{
	std::cout << std::is_array<T>::value << std::endl;  // 0
	std::cout << std::is_pointer<T>::value << std::endl;// 1
}

int main()
{
	int x[3][2] = { 0 };
	fn(x);
	fn2(x);
}
