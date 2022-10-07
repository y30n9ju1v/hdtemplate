#include <iostream>
template<typename T>
class Singleton
{
	// �� �ȿ� ������, ���� �����ڵ�.. �̱��� ���� �ڵ� ����..
public:
	static T& getInstance()
	{
		static T instance;
		return instance;
	}
};

// Cursor �� �̱��� ������ ����ϰ� �ʹ�.
class Cursor : public Singleton< Cursor  >
{

};



int main()
{
	Cursor& c = Cursor::getInstance();
}