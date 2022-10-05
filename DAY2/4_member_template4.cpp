#include <memory>

class Animal { int age; };

class Dog : public Animal {};

int main()
{
	// Animal* 타입의 변수에 "Dog의 주소"를 담을수 있습니다. - upcasting
	Animal* p = new Dog;

	// C++ 은 raw pointer 대신 "스마트 포인터"를 많이 사용합니다.

	std::shared_ptr<Dog>	p1(new Dog);
	std::shared_ptr<Animal> p2 = p1; // 되야 합니다.!! 됩니다.!!
					// 그런데, p1 과 p2는 다른 타입 입니다.
					// shared_ptr 안에는 "generic copy constructor"가 
					// 있습니다.!!
}
