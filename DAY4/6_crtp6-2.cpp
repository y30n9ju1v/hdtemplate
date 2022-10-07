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


// CRTP �� ����ؼ� ���� �ٸ� ��� Ŭ���� �����!!
// => �� ���, ��� Ŭ������ �Ļ� Ŭ���� �̸��� �˰� ���� ���� �ƴ϶�.!!
// => ����, �ٸ� ��� Ŭ������ ����� ���� ���.!
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


