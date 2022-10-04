template<typename T>
class Object
{
	T value;
public:
	void mf()
	{
		*value = 10; 
	}
};

int main()
{
	Object<int> obj;
}
