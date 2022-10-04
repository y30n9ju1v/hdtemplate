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

	// 핵심 1. static 멤버는 객체를 생성하지 않아도 
	//        프로그램 실행시 항상 메모리에 놓이게 됩니다.
	static static_member m2; 
};
static_member Object::m2;

int main()
{
	std::cout << "--------" << std::endl;
	// 핵심 2. non-static 멤버는 객체를 만들때 메모리에 놓이고, 
	//        멤버 데이타의 생성자 호출
	Object obj1;
	Object obj2;
	std::cout << "--------" << std::endl;
}

// 결국 위코드에서 m2 생성자 는 오직 한번만 호출됩니다.
// Object 라는 클래스에 대해서 "m2 생성자"가 한번 호출되므로
// 
// 객체가 아닌 클래스당 한개의 초기화 함수로 볼수 있습니다.
// C#에서는 "클래스 생성자" 라는 개념으로 사용되는 기술 입니다.


