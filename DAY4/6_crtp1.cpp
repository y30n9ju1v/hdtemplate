#include <iostream>

template<typename T> 
class Base
{
public:
	void fn()
	{
		// 기반 클래스 만들때
		// 기반 클래스 멤버 함수 에서 파생 클래스 이름(Derived)을 사용할수 없을까 ?
		// => CRTP 기술
		// 1. 기반 클래스를 템플릿으로 설계합니다.
		// 2. 파생 클래스 만들때 자신의 이름을 기반 클래스템플릿 인자로 전달.

		T obj; // Derived obj;  결국, 이코드는 파생 클래스 객체를 생성한다.

		// 의미 : 오늘 만드는 클래스에서, 미래에 만들어질 파생 클래스 이름을 사용할수 있다.
		// "Curiously Recurring Template Pattern"

		std::cout << typeid(T).name() << std::endl;
	}
};

class Derived : public Base< Derived >
{

};

int main()
{
	Derived  d;
	d.fn();
}





