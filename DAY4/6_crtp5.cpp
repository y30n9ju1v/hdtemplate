#include <iostream>
template<typename T>
class Singleton
{
	// 이 안에 생성자, 복사 생성자등.. 싱글톤 관련 코드 제공..
public:
	static T& getInstance()
	{
		static T instance;
		return instance;
	}
};

// Cursor 도 싱글톤 패턴을 사용하고 싶다.
class Cursor : public Singleton< Cursor  >
{

};



int main()
{
	Cursor& c = Cursor::getInstance();
}