#include <iostream>
#include <vector>

class Test
{
public:
	Test(int a) {}

	int size() { return 10; }
};
//-------------------------------
template<typename T> int check(decltype(std::declval<T>().size())*);
template<typename T> char check(...);


template<typename T> struct has_size_function
{
	static constexpr bool value = (sizeof(check<T>(0)) == sizeof(int));
};

int main()
{
	std::cout << has_size_function<Test>::value << std::endl;
	std::cout << has_size_function<std::vector<int>>::value << std::endl;
}
// C++20 �������� ��ó�� ���� ����߽��ϴ�.
// �׷��� C++20 Concept �� ����ϸ� ���� ���� ���ϴ�.!!