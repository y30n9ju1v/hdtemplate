#include <type_traits>
#include <iostream>

template<typename T>
void fn(T value)
{
	if constexpr (std::is_pointer_v<T>) // 내일 배우는 기술
		std::cout << "포인터에 최적화된 알고리즘" << std::endl;
	else
		std::cout << "포인터가 아닌 타입에 최적화된 알고리즘" << std::endl;

}
int main()
{
	int n = 10;
	fn(n);
	fn(&n);
}
