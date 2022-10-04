#include <iostream>

class CarStaticInit
{
public:
	CarStaticInit() { std::cout << "Car Ŭ���� ������" << std::endl; }
};

class Car
{
public:
	Car() {} // ������.. ��ü�� �ѹ��� ȣ��˴ϴ�.

//	static Car() {} // C# �� ������ static ������ ����	
					// Car Ŭ������ ���ؼ� ���ʿ� 1ȸ ȣ��˴ϴ�.
					// "Ŭ���� ������"��� �մϴ�.
					// C++�� �̹����� �����ϴ�.
	static CarStaticInit init; // init �� �����ڰ� �ᱹ Car Ŭ������ ����	
								// �ѹ� ȣ��˴ϴ�.
};
CarStaticInit Car::init;

int main()
{
	Car c1;
	Car c2;

}