#include <iostream>

class Test
{
public:
	int size() { return 10; }
};
int main()
{
	// ��ǥ : Test Ŭ���� �ȿ� "size()" ��� �Լ��� �ִ��� ������ ���ô�.
	bool b = has_size_function<Test>::value; // true ���;� �մϴ�.
}



// cppreference.com  �����ؼ�
// 1��° ȭ�鿡�� ���� "named requirement" ������
// Allocator ã�� ������.
