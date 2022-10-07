#include <iostream>
#include <exception>

class too_many_object : std::exception {};

// ��ü�� 5�� �̻� �����Ҽ� ���� �ϰ� �ʹ�.
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


