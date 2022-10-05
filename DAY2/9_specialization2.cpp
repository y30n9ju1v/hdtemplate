#include <iostream>

// �ٽ� : ���� ����

template<typename T, typename U> struct Object
{
	static void fn() { std::cout << "T, U" << std::endl; }
};

// T*, U*
template<typename T, typename U> struct Object<T*, U*>
{
	static void fn() { std::cout << "T*, U*" << std::endl; }
};

// T*, U
template<typename T, typename U> struct Object<T*, U>
{
	static void fn() { std::cout << "T*, U" << std::endl; }
};

// �ٽ� : T, T , ��, 2��Ÿ���� ���� Ÿ���϶�

// primary template �� Ÿ�����ڰ� 2�� ���

// 1. ����ڴ� �ݵ�� Ÿ�����ڸ� 2�� ǥ���ؾ� �մϴ�. : Object<int, double>

// 2. �κ� Ư��ȭ�� ������ ��(A�κ�)�� �� 2�� ǥ���ؾ� �մϴ�.

// 3. ������, �κ� Ư��ȭ ������ ���ø� ���� ������ 2���� �ƴҼ��� �ֽ��ϴ�.

template<typename T> struct Object<T, T>   // <=== "A"
{
	static void fn() { std::cout << "T, T" << std::endl; }
};

// int, U ����� ������
template<typename U> struct Object<int, U>
{
	static void fn() { std::cout << "int, U" << std::endl; }
};

// int, short
// => �� ���� "�κ� Ư��ȭ�� �ƴմϴ�."
// => Ư��ȭ(specialization) �Դϴ�. ��� Ÿ���� Ȯ���� ���.
template<> struct Object<int, short>
{
	static void fn() { std::cout << "int, short" << std::endl; }
};

template<typename A, typename B, typename C> struct Object<A, Object<B,C>>
{
	static void fn() { std::cout << "A, Object<B, C>" << std::endl; }
};

int main()
{
	Object<char, double>::fn();	  // T, U
	Object<char*, double*>::fn(); // T*, U*	
	Object<short*, double>::fn(); // T*, U
	Object<float,  float>::fn();  // T, T
	Object<int,    float>::fn();  // int, U
	Object<int, short>::fn();	  // int, short

	Object<short, Object<char, int>>::fn();
					// A, Object<B, C> �� ����� ������

}