#include <iostream>
#include <type_traits>

template<typename T>
void printv(const T& value)
{
	// C++17. if constexpr
	// ���ǽ��� false ��� �ش� ������ "���ø� �ν��Ͻ�ȭ"�� ���Ծȵ�
	if constexpr (std::is_pointer_v<T>) 

		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}

int main()
{
	int n = 10;
	printv(&n); // ok
	printv(n);	// ok
}
/*
// T=int �϶� �Ʒ� ó�� �����˴ϴ�.
void printv(const int& value)
{
	std::cout << value << std::endl;
}
// T=int* �϶� �Ʒ� ó�� �����˴ϴ�.
void printv(const int*& value)
{
	std::cout << value << " : " << *value << std::endl;
}
*/
/*
// ���� : is_pointer<T>::value �� �ݵ�� ������ �ð��� ���� �˼� �־�� �մϴ�.
template<typename T> struct is_pointer
{
	// constexpr : ������ �ð��� ����ϱ� ���� �ʿ�!
	static constexpr  bool value = false;
};
// static �� ������ �Ʒ� ó�� ��ü�� �����Ŀ� value �����ؾ� �մϴ�.
// �׷���, is_pointer �� �ǵ��� value �� �����ϸ� �ǹǷ� ��ü ������ �ʿ��
// �����ϴ�.
// is_pointer<T> ip;
// ip.value;
*/