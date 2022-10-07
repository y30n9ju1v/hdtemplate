#include <iostream>
using namespace std;

struct Base
{
	int value = 10;
};
struct Derived : public Base
{
	// 기반 클래스와 동일이름의 멤버 데이타를 추가해도 됩니다.
	int value = 20;
};
int main()
{
	Derived d;

	cout << d.value << endl; // 20

	// 기반 클래스(Base)로 부터 물려 받은 value 에 접근하려면
	// d 를 Base& 타입으로 캐스팅하면 됩니다.
	cout << (static_cast<Base&>(d)).value << endl; // 10


}