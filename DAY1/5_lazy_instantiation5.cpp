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
	// non-static 멤버 데이타는 객체 생성만 하면 사용되는 것 입니다.
	// static 멤버 데이타는 접근하는 코드가 있어야 사용하는 것 입니다.
	instance_member m1;
	static static_member m2;
};
template<typename T> static_member Object<T>::m2; // <== 내일 배우는
													// 표기법

int main()
{
	Object<int>::m2;
	std::cout << "--------" << std::endl;
	Object<int> obj1;
	Object<double> obj2;
	obj2.m2;
	std::cout << "--------" << std::endl;
}



