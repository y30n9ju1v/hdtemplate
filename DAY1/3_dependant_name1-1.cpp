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
	// ::value �� �� �Դϴ�. typename �ʿ� �����ϴ�.
	Object::value * 10;
	T::value * 10;			// <= value �� Ÿ���� �ƴϹǷ�
							//    typename ������մϴ�.

	Object::type* p1;	 // "dependant name" �ƴմϴ�. typename�ʿ����
	typename T::type* p2;// "dependant name" �Դϴ�. typename �ʿ�
	//==========================================================
	// rebind �� Object �ȿ� ������ ����ü �Դϴ�.
	Object::rebind<int> r1; // ok. dependant name �ƴ�.

//	T::rebind<int> r2;	// error
						// rebind �� dependant name �̹Ƿ�
						// typename �ʿ�

//	typename T::rebind<int> r2;	// error
								// rebind �� ������ �����Ҽ� �����Ƿ�
								// "rebind<" ǥ�⿡�� "<" �� �ǹ̸�
								// �˼� ���� ������

	typename T::template rebind<int> r2; // ok.. rebind�� 
								// ���ø� ���� �˷��־�� �մϴ�.

	// ��� : �� �ڵ忡�� "typename", "template" �� �ʿ��� ���� �˾Ƶμ���
}




int main()
{
	Object obj;
	foo(obj);
}