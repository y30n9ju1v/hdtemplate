#include <iostream>
#include <type_traits>

template<typename T> 
void fn(const T& arg)
{
	// T �� ������ ������ ���� �ٸ� �˰����� ����ϰ� �ʹٸ�
	// ��� 1. if ������ ����
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