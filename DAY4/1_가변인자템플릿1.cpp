// 175 page

// �Ʒ� ó�� �����.. �� ���ø�(Ʋ) ���� 
// => Ÿ�� ���ڸ� �ݵ�� �Ѱ��� �����ؾ� �մϴ�.
//template<typename T> class tuple  {};

// �������� ���ø�, C++11
// => Ÿ�� ���ڸ� ���� ������ ������ �ִ�.
// => ���������� "T" ���ٴ� "Types", "Ts" ��, �������·� ǥ�� �մϴ�.
//    "Ÿ�Ե�" �̶�� �ǹ�
template<typename ... Types> class tuple 
{
};

// ���ڰ� "�Ѱ��� �Լ����� ����"�Ҽ� �ִ� ���ø�
// => "fn(3)" ó�� �ݵ�� ���ڸ� �Ѱ��� ������ �մϴ�.
//template<typename T> void fn(T arg) {}


// �������� �Լ� ���ø�
// => ���� ������ ���ڸ� ������ �Լ��� �����Ҽ� �ֽ��ϴ�.
template<typename ... Types> 
void fn(Types ... args) 
{
}

int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, double> t2;
	tuple<int, double, char> t3; // Types : int, double, char


	fn(1, 3.4);
	fn(1, 3.4, 'A'); // Types : int, double, char
					 // args   : 1,   3.4,    'A'
}

