#include <iostream>

struct static_member
{
	static_member() { std::cout << "static_member()" << std::endl; }
	~static_member() { std::cout << "~static_member()" << std::endl; }
};
struct instance_member
{
	instance_member() { std::cout << "instance_member()" << std::endl; }
	~instance_member() { std::cout << "~instance_member()" << std::endl; }
};
//============================================
template<typename T>
struct Object
{
	// non-static ��� ����Ÿ�� ��ü ������ �ϸ� ���Ǵ� �� �Դϴ�.
	// static ��� ����Ÿ�� �����ϴ� �ڵ尡 �־�� ����ϴ� �� �Դϴ�.
	instance_member m1;
	static static_member m2;
};
template<typename T> static_member Object<T>::m2; // <== ���� ����
													// ǥ���

int main()
{
	Object<int>::m2;
	std::cout << "--------" << std::endl;
	Object<int> obj1;
	Object<double> obj2;
	obj2.m2;
	std::cout << "--------" << std::endl;
}



