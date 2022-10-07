#include <iostream>

// ���̺귯�� ����
class Window
{
public:
	void event_loop() // void event_loop(Window* this) �� ����˴ϴ�.
	{
		// �߻��� �̺�Ʈ�� ������ ���� ��ӵ� �Լ� ȣ��
		Click();	// this->Click() �Դϴ�.
					// Click() �� �����Լ���� "this �� ����Ű�� ���� ��ü" ������ ȣ��
					// Click() �� �����Լ��ƴϸ� "this" �� Ÿ������ ȣ��
	}
	virtual void Click()     { std::cout << "Window Click" << std::endl; }
	virtual void MouseMove() { }
};

// �Ʒ� Ŭ������ ���̺귯�� ����� �ڵ�.
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