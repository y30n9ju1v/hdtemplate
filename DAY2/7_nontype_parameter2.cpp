#include <iostream>

template<typename T, int N> 
struct Object
{
	T buff[N];	// ���ø� ���ڴ� �׻� ������ �ð��� ũ�⸦ �˼� �ֱ� ������
				// �迭 ũ��� ��밡��
};
int main()
{
	int n = 10;
	Object<int,  n> obj1;	// error. ���ø� ���ڰ��� �ݵ��
							// ������ �ð��� �˾ƾ� �մϴ�.
	Object<int, 10> obj2;	// ok. 

	const int c1 = 10;	// ������ �ð� ��� ( �����Ϸ��� �ʱⰪ�� �˰� �ִ�)
	const int c2 = n;	// ����ð� ���( �����Ϸ��� �ʱⰪ�� �˼� ����)

	Object<int, c1> obj3; // ok
	Object<int, c2> obj4; // error.

	// �׷��� C++11 ���� "������ �ð� ���"�� �ٷ�� �Ǵٸ� Ű���� ����
	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error. 
	
	// ��� : constexpr ����� �׻� ���ø� ���ڷ� ��밡��.
}


