#include <iostream>
#include <exception>

class too_many_object : std::exception {};

// 객체를 5개 이상 생성할수 없게 하고 싶다.
class LimitObjectCount
{
	static int maxcnt;
public:
	LimitObjectCount()
	{
		if (++maxcnt > 5)
			throw too_many_object();
	}
	~LimitObjectCount() { --maxcnt; }
};
int LimitObjectCount::maxcnt = 0;

// Mouse 클래스와 Keyboard 클래스도 객체의 갯수를 5개로 제한 하고 싶다.
// => 아래 처럼 만들면 "LimitObjectCount::maxcnt" 변수를
// => Mouse, Keyboard 가 모두 공유 하게 됩니다.
// => 각각 5개 가 아닌, 합해서 5개가 됩니다.
class Mouse : public LimitObjectCount
{
};
class Keyboard : public LimitObjectCount
{
};

int main()
{
	Mouse  m[3];
	Keyboard k[3]; // exception!!!

}


