// �̼ҽ� �����ؼ� 3_dependant_name1-1�� ����� �μ���.
// 77 page
struct Object
{
	using type = int;
	static constexpr int value = 10;
};

template<typename T> 
void foo(T obj)
{
	// �Ʒ� 2�ٿ��� "*"�� �ǹ̸� ������ ������.
	// "Ŭ�����̸�::�̸�" ���� ǥ���Ҷ� "�̸�" �� �ǹ̴�
	// 1. ��   : static �������Ÿ, enum �����
	// 2. Ÿ�� : typedef, using ���� ��.

	Object::value * 10;    // ���ϱ��� �ǹ�
	Object::type  * p1;	   // p1 �̶�� ������ ������ ����

	// �ٽ� 1. dependant name
	//      => ���ø� ���� T�� �����ؼ� ������ �̸�
	//      => �����Ϸ��� ������ �̸��� �ǹ̸� "��"���� �ؼ��մϴ�.

	T::value * 10;    
//	T::type  * p2;	// type �� ������ �ؼ��ϹǷ� * �� ���ϱ�� �ؼ�
					// "p2"��� ������ ���ٰ� ����.. 

	typename T::type* p2; // ::type �� "��"�� �ƴ� "Ÿ��" �̸����� 
						  // �ؼ��� �޶�.
}





int main()
{
	Object obj;
	foo(obj);
}