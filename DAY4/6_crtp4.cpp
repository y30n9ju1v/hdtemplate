#include <iostream>

// thin templpate(template hoisting) ���

// => Ŭ���� ���ø� ���鶧, ���ø�����(T)�� ������� ���� ��� �Լ��� �ִٸ�
// => ���ø��� �ƴ� ��� Ŭ������ ���� �����϶�!!

class BaseWidow
{
public:
	// CRTP ����� ������� Window �� �����ϴ� ������ ��� �Լ���
	// 1. event ó�� �Լ��� �⺻ ����
	void Click() { std::cout << "Window Click" << std::endl; }
	void MouseMove() { }

	// 2. window ���� ���� �⺻ �Լ�
	void MoveWindow() {}
	void SetTitle() {}
	void SetTitleColor() {}
};
// C++20 �� ���ο� STL(range) �� CRTP�� �����Ǿ� �ֽ��ϴ�. ���� �θ� ���

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