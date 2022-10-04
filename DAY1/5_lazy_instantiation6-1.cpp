#include <type_traits>
#include <iostream>

template<typename T>
void fn(T value)
{
	if constexpr (std::is_pointer_v<T>) // ���� ���� ���
		std::cout << "�����Ϳ� ����ȭ�� �˰���" << std::endl;
	else
		std::cout << "�����Ͱ� �ƴ� Ÿ�Կ� ����ȭ�� �˰���" << std::endl;

}
int main()
{
	int n = 10;
	fn(n);
	fn(&n);
}
