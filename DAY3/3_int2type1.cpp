// if constexpr1.cpp ���� �ؼ� �ּ� ���� ������
#include <iostream>
#include <type_traits>

// �Ʒ� "pointer template" ��
// 1. ���ø� ��ü�� ������ ����.
// 2. T=int �϶� �ν��Ͻ�ȭ�� �Ǹ� ���� �̴�.(T=int* �϶��� �����ƴ�)
// 3. T=int �϶� �ν��Ͻ�ȭ�� ���� ������ ���� �ƴϴ�.

template<typename T> void pointer(const T& value)
{
	std::cout << value << " : " << *value << std::endl;
}
template<typename T> void not_pointer(const T& value)
{
	std::cout << value << std::endl;
}

template<typename T>
void printv(const T& value)
{
	// �ǵ� : T = int ��� if ( false ) �̰�,  pointer(v) �� ������ �ʴ´�.
	//      ����, �ν��Ͻ�ȭ ���� �������̴� !!
	if (std::is_pointer_v<T>)
		pointer(v);
	else
		not_pointer(v);

	// ����!!
	// if �� ����ð� ���ǹ��̹Ƿ� ���ǽ��� ����� �������
	// pointer(v), not_pointer(v) ��� �ν��Ͻ�ȭ�� �ȴ�.!!!
	// T=int �϶� pointer(v)�� �ν��Ͻ�ȭ �ǹǷ� ����!!

	// �ǵ���� �Ϸ��� "if" ��� "if constexpr(C++17)" �ʿ�
}



int main()
{
	int n = 10;
	printv(n);	// error.
}