// �̼ҽ� �����ؼ� 3_dependant_name1-1�� ����� �μ���.
// 77 page
struct Object
{
	using type = int;

	static constexpr int value = 10;

	template<typename T> struct rebind
	{
	};
};

template<typename T>
void foo(T obj)
{
	Object::value * 10;
	Object::type* p1;

	Object::rebind<int> a;
}

int main()
{
	Object obj;
	foo(obj);
}