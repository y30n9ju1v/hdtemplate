#include <iostream>
#include <type_traits>

template<int N>
struct int2type
{
	enum { value = N };
};

template<typename T> void printv_imp(const T& value, int2type<1> )
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> void printv_imp(const T& value, int2type<0>  )
{
	std::cout << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	printv_imp(value, int2type< std::is_pointer_v<T> >() );

					// 0,  1 은 같은 타입이지만
					// int2type<0>, int2type<1> 은 다른 타입
					// 
					// "int2type<0>" 은 타입 입니다.
					// "int2type<0>()" 은 임시객체 생성 입니다.
}		



int main()
{
	int n = 10;
	printv(n);	// error.
}