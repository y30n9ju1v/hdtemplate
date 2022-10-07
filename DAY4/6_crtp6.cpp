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


int main()
{
//	LimitObjectCount obj1[4]; // ok
	LimitObjectCount obj1[6]; // exception
}


