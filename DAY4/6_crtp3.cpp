#include <iostream>

// �Ʒ� �ڵ尡 "CRTP" �� ����ؼ�
// �����Լ��� �ƴ� �Լ��� �����Լ� ó�� �����ϰ� ����� ��� �Դϴ�.

// ����ũ�� ����Ʈ�� "WTL(���ǽ����鶧 ����� ���̺귯��)"�� �� ����� �Ǿ� �ֽ��ϴ�.
//				  "Window Template Library"


// ���̺귯�� ����
template<typename Derived > 
class Window
{
public:
	void event_loop()	// void event_loop(Window* this) �� ����˴ϴ�.
	{
//		Click();		// this->Click() �Դϴ�.

		static_cast<Derived*>(this)->Click();
	}
	void Click() { std::cout << "Window Click" << std::endl; }
	void MouseMove() { }
};

// �Ʒ� Ŭ������ ���̺귯�� ����� �ڵ�.
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