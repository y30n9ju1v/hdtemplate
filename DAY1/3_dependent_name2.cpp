template<typename T> 
struct Object
{
	using type = int;

	template<typename U> 
	static void mf() {	}
};
template<typename T>
void foo()
{
	Object<int>::type t1;	// T�� �������� ����. typename �ʿ� ����
							// ok.
							// 
	// T::type t2;			// �� ǥ�⵵ dependant name
	//Object<T>::type t2;	// �� ǥ�⵵ dependant name
							// typename �־�� �մϴ�.
	typename Object<T>::type t2; // ok
	//==============================================

	Object<int>::mf<double>();	// ok
								// "mf" �� dependant name �ƴմϴ�.

//	Object<T>::mf<double>();	// error
	
	// �� �ڵ� �������� �ʰ� �غ�����.
	Object<T>::template mf<double>();
				// => mf �� Ÿ���� �̸��� �ƴմϴ�. typename �ʿ����
				// => ������ "���ø�" �̾����� �˷��־�� �մϴ�.
	//=================================
	Object<int> o1;	// �̷��� �ϸ� �����Ϸ��� o1 ��ü�� Ÿ���� 
					// ��Ȯ�� �˰� �˴ϴ�.
					// ����, ��� ����� ���� ��Ȯ�� �˰� �ֽ��ϴ�.
					// "mf"�� ���ø� ���� �˰� �ֽ��ϴ�.

	Object<T>   o2;	// T �� ����, "mf"�� ��ü�� �޶����� �ֽ��ϴ�.

	o1.mf<int>();	// ok. �����Ϸ��� �̼���, "mf" �� ���ø� �̶�� ���� 
					// �˰� �ֽ��ϴ�.
//	o2.mf<int>();	// error. �������� �ʰ� �غ�����.

	o2.template mf<int>(); // ".template" �̶�� ǥ���
							// "->template" ǥ����� �ֽ��ϴ�.
							// 
	// �ٽ� 1. dependant name �̶�� ��� �˾� �μ���
	//		=> T�� �����ؼ� ������ �̸�
	// 
	// 2. dependant name ���� 
	//    "typename", "template"�� �����ϰ� ǥ���ؾ� �մϴ�.

	// C++20, C++23 ���ʹ� "������ ����� ���� �����˴ϴ�"
	// "typename", "template"�� ǥ������ �ʾƵ� �Ǵ� ��찡 �ֽ��ϴ�.
	// ������, C++17  ������ �� ǥ���� �ּ���..
}




int main()
{
	foo<int>();
}