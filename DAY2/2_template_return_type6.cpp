#include <iostream>
#include <type_traits>

// ��� 3. 2���� ���ø� ����

// ��ȯ Ÿ�� ǥ�� 3. auto �� ǥ��
// => "return ǥ����" ���� "ǥ����"�� ���� Ÿ���� ������ �޶�� �ǹ�
// => "return" ������ ������ �ִٸ� �߷��Ҽ� ����.
//    �̶��� -> decltype() ���� ��ȯ Ÿ���� ǥ���ϸ� �ȴ�.
template<typename T1, typename T2>
auto add(const T1& a, const T2& b)
{
	return a + b;

	//�Ʒ� ó�� return ������ ������ ��� "auto" �� �߷��Ҽ� �����ϴ�.
//	if (a == 3) return a;
//	return b;
}

int main()
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3, 4.3) << std::endl;


}



