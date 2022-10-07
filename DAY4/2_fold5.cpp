#include <iostream>
#include <vector>

std::vector<int> v;

template<typename ... Types>
void fn(Types ... args)
{
	// pack ���� ��� ��Ҹ� v �� �ְ� �ʹ�.
	(v.push_back(args) , ...);
	// pack            op  ...   �Դϴ�.
	// v.push_back(1), (v.push_back(2), ( v.push_back(3)     
}
int main()
{
	fn(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	for (auto e : v)
		std::cout << e << ", ";
}
// �� �ܿ��� ���ۿ��� "C++ fold expression example"  �˻��ϸ�
// ����ִ� ��� ���� �ֽ��ϴ�.


