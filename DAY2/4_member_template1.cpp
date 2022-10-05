
// 53page
template<typename T>
class Object
{
public:
	void mf1(int n) {}	// �Լ� ���ø� �ƴմϴ�.
						// ���ڴ� "int" �Դϴ�.
	
	void mf2(T   n) {}	// �Լ� ���ø� �ƴմϴ�.
						// Ŭ���� ���ø���  "�Ϲ� ��� �Լ�" �Դϴ�.
						// "Object<double> obj" �� ��ü ������
						// "mf2(double)" �� �Լ��� ���� �˴ϴ�.

	// �Ʒ� �ڵ尡 "�Լ� ���ø�" �Դϴ�.
	// "Ŭ���� ���ø�"�� "��� �Լ� ���ø�"
	template<typename U>
	void mf3(U n) {}
};

int main()
{
	Object<int>    obj1;

	obj1.mf1(3);	// mf1�� ���ڴ� �׻� "int"
	obj1.mf2(3);	// mf2�� ���ڴ� ��ü�� ���鶧 ������ Ÿ�� "int"
	obj1.mf2(3.4);	// ������ �ƴ����� ���ڰ� int �� �Լ��� 
					// double ���޵���Ÿ �ս� �߻�

	obj1.mf3(3);	// mf3(int) �Լ� ����
	obj1.mf3(3.4);	// mf3(double) �Լ� ����

	// �ᱹ "mf2" �� ���ø� �� �ƴϹǷ� "��� �Լ��� �Ѱ�" �ε�..
	// "mf3" �� �Լ� ���ø� �̹Ƿ� "�������� mf3" �� �����ɼ� �ֽ��ϴ�.
}