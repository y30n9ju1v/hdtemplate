#include <iostream>
#include <type_traits>

// �׷���.. �Ʒ� �ڵ�� ��.. �����ϱ�� ?
template<typename T> 
void printv(const T& value)
{
	if ( std::is_pointer_v<T> )  // �Ǵ� std::is_pointer<T>::value

		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}


int main()
{
	int n = 10;
	printv(&n); // ok
	printv(n);	// error
}