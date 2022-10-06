#include <iostream>

// traits ��� ����
// �ٽ� 1. ��� ������ "<type_traits>", C++11
#include <type_traits>


// C++14 ���� �Ʒ� ������ ǥ�ؿ� �߰� �˴ϴ�.
// => using template ���.

template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type ;

// C++17 ���� �Ʒ� ������ ǥ�ؿ� �߰� �˴ϴ�.
// => variable template �� ����ϴ� ���

template<typename T>
constexpr bool is_pointer_v = std::is_pointer<T>::value;


template<typename T>
void fn(const T& arg)
{
	// �ٽ� 2. Ÿ���� Ư�� ����
	bool b1 = std::is_pointer<T>::value;
	bool b2 = std::is_pointer_v<T>;	// C++17 ���� ����
									// VC�� C++14 �ɼǿ����� �����ϵ˴ϴ�.


	// �ٽ� 3. ���� Ÿ�Ծ��
	typename std::remove_pointer<T>::type n1;

	std::remove_pointer_t<T> n2;	// �� �ڵ尡 ���� �����մϴ�.
}




int main()
{
	int n = 0;
	fn(&n);
}