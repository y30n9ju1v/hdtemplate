#include <iostream>
#include <exception>

class too_many_object : std::exception {};

template<typename T, int N>
class LimitObjectCount
{
	static int maxcnt;
public:
	LimitObjectCount()
	{
		if (++maxcnt > N)
			throw too_many_object();
	}
	~LimitObjectCount() { --maxcnt; }
};

template<typename T, int N>
int LimitObjectCount<T, N>::maxcnt = 0;


// CRTP 를 사용해서 서로 다른 기반 클래스 만들기!!
// => 이 경우, 기반 클래스가 파생 클래스 이름을 알고 싶은 것은 아니라.!!
// => 단지, 다른 기반 클래스를 만들기 위해 사용.!
class Mouse : public LimitObjectCount<Mouse, 5>
{
};
class Keyboard : public LimitObjectCount<Keyboard, 10>
{
};

int main()
{
	Mouse  m[3];
	Keyboard k[3]; // exception!!!

}


