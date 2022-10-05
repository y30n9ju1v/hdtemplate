// 5_friend6.cpp

// "1��" Ŭ������ "1��" �Լ��� friend ����

struct Object1
{
	friend void f1();
};
void f1() {}

//=================================================
// "N��" Ŭ������ "1��" �Լ��� friend ����
template<typename T>
struct Object2
{
	friend void f2();
};
void f2() {}

//===========================================
// "1��" Ŭ������ "N��" �Լ�(f3(int), f3(double) ��) �� friend ���� 
struct Object3
{
	template<typename T> friend void f3(T arg);
};
template<typename T> void f3(T arg) {}

//======================================
// �ٽ�!!
// "N��" Ŭ������ "M��" �Լ��� friend ���� 
template<typename U> struct Object4
{
	template<typename T> friend void f4(T arg);
};
template<typename T> void f4(T arg) {}

//=====================================
// �ٽ� : Object5<int>    <=> f5(int)
//       Object5<double> <=> f5(double) 
// 
// ��ó�� �Ѱ� Ÿ���� �Ѱ� �Լ��� friend �ǰ� �Ҽ� ������ ?

template<typename U> struct Object5
{
	// �Ʒ� ó�� friend �Լ��� ���� ��ü�� class �ȿ� ����� �˴ϴ�.
	friend void f5(T arg)
	{
	}
};

// �� 5��  ��찡 ��� ���� �ǽź���
// friend7�� ���弼��.  5�� ��������, �ּ� ����� �ڵ� ������ ������..
// 