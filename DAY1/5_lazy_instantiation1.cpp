// 32 page, lazy instantiation

class Object
{
	int value;
public:
	void mf()
	{
		*value = 10; // error.
					 // value �� int �ε�. int �� * �Ҽ� �����ϴ�.
	}
};

int main()
{
	Object obj;
}
