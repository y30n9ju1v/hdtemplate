#include <iostream>

class Test
{
public:
	int size() { return 10; }
};
//---------------------------------
// �ٽ� : �Ʒ� ? �ڸ��� T(Test) Ŭ������ "size()" �Լ��� ������ �����ϴ� �ڵ带
//       �ۼ��ϸ� �˴ϴ�.

template<typename T> void check(? ) { std::cout << "T" << std::endl; }

template<typename T> void check(...) { std::cout << "..." << std::endl; }

int main()
{
	check<Test>(0);
}