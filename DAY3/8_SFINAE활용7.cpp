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
// C++20 전까지는 위처럼 만들어서 사용했습니다.
// 그런데 C++20 Concept 을 사용하면 아주 쉬워 집니다.!!