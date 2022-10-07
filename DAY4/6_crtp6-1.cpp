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

// Mouse Ŭ������ Keyboard Ŭ������ ��ü�� ������ 5���� ���� �ϰ� �ʹ�.
// => �Ʒ� ó�� ����� "LimitObjectCount::maxcnt" ������
// => Mouse, Keyboard �� ��� ���� �ϰ� �˴ϴ�.
// => ���� 5�� �� �ƴ�, ���ؼ� 5���� �˴ϴ�.
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


