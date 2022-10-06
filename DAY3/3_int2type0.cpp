// 3_int2type0.cpp

template<typename T>
void printv(const T& value)
{
	if (std::is_pointer_v<T>)
		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}
// �� �ڵ�� ���� �Դϴ�.
// �� �ڵ��� ������ �ذ��ϴ� �ذ�å�� 4������ �ֽ��ϴ�. => ��� �߿�!!!
// 
// 1. int2type, integral_constant - C++11 ���
// 
// 2. enable_if - C++11 ���
// 
// 3. if constexpr - C++17 ���
// 
// 4. concept - C++20 ���
 