#include <iostream>

// 아래 코드가 "CRTP" 를 사용해서
// 가상함수가 아닌 함수를 가상함수 처럼 동작하게 만드는 기술 입니다.

// 마이크로 소프트의 "WTL(오피스만들때 사용한 라이브러리)"가 이 기술로 되어 있습니다.
//				  "Window Template Library"


// 라이브러리 내부
template<typename Derived > 
class Window
{
public:
	void event_loop()	// void event_loop(Window* this) 로 변경됩니다.
	{
//		Click();		// this->Click() 입니다.

		static_cast<Derived*>(this)->Click();
	}
	void Click() { std::cout << "Window Click" << std::endl; }
	void MouseMove() { }
};

// 아래 클래스가 라이브러리 사용자 코드.
class MainWindow : public Window< MainWindow >
{
public:
	void Click() { std::cout << "MainWindow Click" << std::endl; }
};

int main()
{
	MainWindow w;
	w.event_loop();
}