#include <iostream>
#include <type_traits>

template<typename T> 
void fn(const T& arg)
{
	// T �� ������ ������ ���� �ٸ� �˰����� ����ϰ� �ʹٸ�
	// ��� 1. if ������ ����
	if ( std::is_pointer_v<T> ) // std::is_pointer<T>::value
	{
		// if ( false), ��, �����Ͱ� �ƴ϶� �� �κ��� �ν��Ͻ�ȭ�� ���Ե�.
		// *arg = 10; // �׷���, �̷� �ڵ�� �ۼ��Ҽ� �����ϴ�.
		// �׷���, �̹���� ���� ���� ����.
	}
	else
	{
	}
	// ��� 2. if constexpr
	// => �� �ڵ忡�� "if" ��� "if constexpr" ���
	// => ���� �ڵ�, ��, C++17 ���� ����

	// ��� 3. true_type, false_type ���� �����ε�
	fn_imp(arg, std::is_pointer<T>());
}
template<typename T> void fn_imp(const T& arg, std::true_type) {} 
														// *arg = 10; ��밡��
template<typename T> void fn_imp(const T& arg, std::false_type) {}


// ��� 4. enable_if -> ����
// ��� 5. concept   -> C++20, ����. 
int main()
{

}