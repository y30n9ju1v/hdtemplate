// 32 page, lazy instantiation

class Object
{
	int value;
public:
	void mf()
	{
		*value = 10; // error.
					 // value 는 int 인데. int 는 * 할수 없습니다.
	}
};

int main()
{
	Object obj;
}
