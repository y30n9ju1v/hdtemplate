#include <iostream>
#include <type_traits>

template<typename T> 
void fn(const T& arg)
{
	// T 가 포인터 인지에 따라 다른 알고리즘을 사용하고 싶다면
	// 방법 1. if 문으로 조사
	if (std::is_pointer_v<T>) // std::is_pointer<T>::value
	{

	}
	else
	{

	}
}



int main()
{

}