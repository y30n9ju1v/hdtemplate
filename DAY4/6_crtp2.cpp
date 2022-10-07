#include <iostream>

// 라이브러리 내부
class Window
{
public:
	void event_loop() // void event_loop(Window* this) 로 변경됩니다.
	{
		// 발생된 이벤트의 종류에 따라 약속된 함수 호출
		Click();	// this->Click() 입니다.
					// Click() 이 가상함수라면 "this 가 가리키는 실제 객체" 조사후 호출
					// Click() 이 가상함수아니면 "this" 의 타입으로 호출
	}
	virtual void Click()     { std::cout << "Window Click" << std::endl; }
	virtual void MouseMove() { }
};

// 아래 클래스가 라이브러리 사용자 코드.
class MainWindow : public Window 
{
public:
	void Click() { std::cout << "MainWindow Click" << std::endl; }
};

int main()
{
	MainWindow w;
	w.event_loop();
}