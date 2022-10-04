#include <iostream>

class CarStaticInit
{
public:
	CarStaticInit() { std::cout << "Car 클래스 생성자" << std::endl; }
};
// 아래처럼 Car 를 만들면 위 생성자가 호출되지만
// "template" 으로 변경하면 호출되지 않습니다. "지연된 인스턴스화" 때문에..
class Car
{
public:
	Car() {} // 생성자.. 객체당 한번씩 호출됩니다.

//	static Car() {} // C# 언어가 가지는 static 생성자 개념	
					// Car 클래스에 대해서 최초에 1회 호출됩니다.
					// "클래스 생성자"라고 합니다.
					// C++에 이문법이 없습니다.
	static CarStaticInit init; // init 의 생성자가 결국 Car 클래스에 대해	
								// 한번 호출됩니다.
};
CarStaticInit Car::init;

int main()
{
	Car c1;
	Car c2;

}