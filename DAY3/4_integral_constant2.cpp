#include <iostream>

// �Ʒ� �ڵ尡 �̹� C++ ǥ�ؿ� �ֽ��ϴ�. - <type_traits>
/*
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};
using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// false_type : ���������� "static constexpr bool value = false" ����
// true_type  : ���������� "static constexpr bool value = true" ����
// 
// C++ǥ���� is_pointer �� �����δ� �Ʒ� ó�� �����Ǿ� �ֽ��ϴ�.
template<typename T> struct is_pointer     : false_type {}; // value=false
template<typename T> struct is_pointer<T*> : true_type {};
*/
//==========================================================

#include <type_traits> // �� �ȿ� ���� �ִ� �ڵ尡 ��� �ֽ��ϴ�.

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
					// is_pointer Ÿ���� ��ü ����

}



int main()
{
	int n = 10;
	printv(n);	
}
