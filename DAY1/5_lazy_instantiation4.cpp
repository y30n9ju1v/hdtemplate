#include <iostream>

struct static_member
{
	static_member()  { std::cout << "static_member()"  << std::endl;}
	~static_member() { std::cout << "~static_member()" << std::endl;}
};
struct instance_member
{
	instance_member()  { std::cout << "instance_member()" << std::endl;}
	~instance_member() { std::cout << "~instance_member()" << std::endl;}
};
//============================================
struct Object
{
	instance_member m1;

	// �ٽ� 1. static ����� ��ü�� �������� �ʾƵ� 
	//        ���α׷� ����� �׻� �޸𸮿� ���̰� �˴ϴ�.
	static static_member m2; 
};
static_member Object::m2;

int main()
{
	std::cout << "--------" << std::endl;
	// �ٽ� 2. non-static ����� ��ü�� ���鶧 �޸𸮿� ���̰�, 
	//        ��� ����Ÿ�� ������ ȣ��
	Object obj1;
	Object obj2;
	std::cout << "--------" << std::endl;
}

// �ᱹ ���ڵ忡�� m2 ������ �� ���� �ѹ��� ȣ��˴ϴ�.
// Object ��� Ŭ������ ���ؼ� "m2 ������"�� �ѹ� ȣ��ǹǷ�
// 
// ��ü�� �ƴ� Ŭ������ �Ѱ��� �ʱ�ȭ �Լ��� ���� �ֽ��ϴ�.
// C#������ "Ŭ���� ������" ��� �������� ���Ǵ� ��� �Դϴ�.


