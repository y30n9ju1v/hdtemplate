#include <iostream>

// thin templpate(template hoisting) 기술

// => 클래스 템플릿 만들때, 템플릿인자(T)를 사용하지 않은 멤버 함수가 있다면
// => 템플릿이 아닌 기반 클래스를 만들어서 제공하라!!

class BaseWidow
{
public:
	// CRTP 기술과 상관없는 Window 를 관리하는 수많은 멤버 함수들
	// 1. event 처리 함수의 기본 구현
	void Click() { std::cout << "Window Click" << std::endl; }
	void MouseMove() { }

	// 2. window 조작 관련 기본 함수
	void MoveWindow() {}
	void SetTitle() {}
	void SetTitleColor() {}
};
// C++20 의 새로운 STL(range) 가 CRTP로 구현되어 있습니다. 아주 널리 사용

template<typename Derived >
class Window : public BaseWindow
{
public:
	void event_loop()
	{
		static_cast<Derived*>(this)->Click();
	}
};

class MainWindow : public Window< MainWindow >
{
public:
	void Click() { std::cout << "MainWindow Click" << std::endl; }
};

class MainWindow2 : public Window< MainWindow2 >
{
public:
	void Click() { std::cout << "MainWindow2 Click" << std::endl; }
};





int main()
{
	MainWindow w;
	w.event_loop();
}