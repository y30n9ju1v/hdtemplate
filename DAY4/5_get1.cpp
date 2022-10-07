#include <iostream>
using namespace std;

struct Base
{
	int value = 10;
};
struct Derived : public Base
{
	// ��� Ŭ������ �����̸��� ��� ����Ÿ�� �߰��ص� �˴ϴ�.
	int value = 20;
};
int main()
{
	Derived d;

	cout << d.value << endl; // 20

	// ��� Ŭ����(Base)�� ���� ���� ���� value �� �����Ϸ���
	// d �� Base& Ÿ������ ĳ�����ϸ� �˴ϴ�.
	cout << (static_cast<Base&>(d)).value << endl; // 10


}