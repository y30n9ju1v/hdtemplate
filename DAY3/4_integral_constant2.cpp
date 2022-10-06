#include <iostream>

// 아래 코드가 이미 C++ 표준에 있습니다. - <type_traits>
/*
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};
using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// false_type : 내부적으로 "static constexpr bool value = false" 제공
// true_type  : 내부적으로 "static constexpr bool value = true" 제공
// 
// C++표준의 is_pointer 는 실제로는 아래 처럼 구현되어 있습니다.
template<typename T> struct is_pointer     : false_type {}; // value=false
template<typename T> struct is_pointer<T*> : true_type {};
*/
//==========================================================

#include <type_traits> // 이 안에 위에 있는 코드가 모두 있습니다.

template<typename T> void printv_imp(const T& value, std::true_type )
{
	std::cout << value << " : " << *value << std::endl;
}

template<typename T> void printv_imp(const T& value, std::false_type )
{
	std::cout << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	printv_imp(value, std::is_pointer<T>() );
					// is_pointer 타입의 객체 생성

}



int main()
{
	int n = 10;
	printv(n);	
}
