template<typename T> 
void fn(T arg) 
{
}

int main()
{
	// auto �� Ÿ�� �߷� ����� 
	// template �� ���� �մϴ�

	const int c = 10;
	fn(c);  // "T    arg = c" �̹Ƿ� c�� ���� T �� Ÿ���� �߷�
			// "auto arg = c" �� �����մϴ�. c�� ���� auto �߷�


	auto   a1 = c;	// "T a1 = c" �� �����Ƿ� , ��Ģ 1 ����
					// "c �� ���� const, volatile, reference" ������ ����
					// auto = int,  a1 = int

	auto&  a2 = c;	// "T& a2 = c" �̹Ƿ�, ��Ģ 2.
					// "c �� ���� reference �� �����ϰ� Ÿ�� ����"
					// auto = const int,  a2 = const int&

	int n = 10;
	// auto&& �� T&& �� ���� ��Ģ
	auto&& a3 = 3;	// 3�� rvalue
					// auto = int,  a3 = int&&
				   
	auto&& a4 = n;	// n�� lvalue
					// auto = int&	a4 = int& && => int&

	// �迭�� auto
	const int v[3] = { 1,2,3 };

	auto a5 = v;	// "T a5 = v", �迭�� �� Ÿ������ �޴� ���
					// "const int* a5 = v"
					// auto : const int*    a5 : const int*

	auto& a6 = v;  // "T& a6 = v"
				   // T(auto) : const int[3], a6 : const int (&a6)[3]

	int x[3];
	int(&r)[3] = x;  // �迭�� ����Ű�� ���� ��� �����Դϴ�.
	int(*p)[3] = &x; // �迭�� ����Ű�� ������(C���) �Դϴ�.
}

// template Ÿ�� �߷� ��Ģ�� auto �� �Ϻ��� �����մϴ�.
// => �׷���, auto �� ������ �н��� �ϸ�, Ȯ���� ����� �����ϴ�.
//    "auto �� � Ÿ���� �Ǿ�����???"
// => template �� Ȯ�� �����մϴ�.

const int c = 1;
auto a = c;  // a�� Ÿ���� �����Ϸ���

template<typename T> void fn(T a) {}  // �̷��� ����� ���⼭ �Լ� �̸����
fn(c); 