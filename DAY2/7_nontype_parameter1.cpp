enum       Color1 {red, blue, green};
enum class Color2 {red, blue, green};

void foo(int a) {}

// ���ø� �Ķ���ͷ� "Ÿ��", "���ø�" �ܿ��� �Ʒ��� ���� �͵��� ��밡���մϴ�.
// => "����� ���� ����" ������ �θ� ����ϰ� �ֽ��ϴ�.
template<int N, 	// ����
		 double d,	// �Ǽ��� "C++20" ���͸� �����մϴ�.
		 Color1 C1, // enum
		 Color2 C2, // C++11 �� ���ο� enum
		 int* P, 	// ������,  ��, �������� �ּҴ� �ȵǰ�, �����Ǵ�  static ������
		 void(*FP)(int)> // �Լ� ������ ����. 
class NTTP
{
};

int main()
{
	int n = 10;
	static int s = 0;

	NTTP<10, 3.4, Color1::red, Color2::red, &s, &foo > t1; // ok
//	NTTP<10, 3.4, Color1::red, Color2::red, &n, &foo > t2; // error
													// &n ���� n�� ��������
}