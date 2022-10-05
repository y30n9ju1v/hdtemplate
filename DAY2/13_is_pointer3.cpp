#include <iostream>
#include <type_traits>

// is_pointer 2개 복사해 오세요. is_array 만들어 보세요.

template<typename T> 
void fn(T& arg)
{
	std::cout << is_array<T>::value << std::endl;
}
int main()
{
	int n = 0;
	int x[3] = {1,2,3};

	fn(n);	// 0(false)
	fn(x);	// 1(true) 나와야 합니다.
	
}