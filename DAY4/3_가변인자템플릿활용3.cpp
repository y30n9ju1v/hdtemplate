#include <iostream>

int f(int, double, char) { return 0; }


// argument �� ����ϴ� �ڵ带 ���� primary template �� ����ϴ�.
template<int N, typename T> struct argument
{
	using type = T;
};
// ���ϴ� ��(������ Ÿ��)�� ������ �ֵ��� �κ� Ư��ȭ �մϴ�.
// =>> �ٽ�!!! ��� �κ� Ư��ȭ �ؾ� �ϴ°� ?? �� �����ؾ� �մϴ�.
// => N=0 �� ��츦 ���� �����ؾ� �մϴ�
/*
template<typename T> struct argument<0, T>
{
	// T���� 0��° ������ Ÿ���� ���Ҽ� ������� ?
	// => ���Ҽ� �����ϴ�. �߸��� �κ� Ư��ȭ!!
	using type = ?;
};
*/

/*
template<typename R, typename ... Types> 
struct argument<0, R(Types...)>
{
	// ���� �ڵ�� ���� Ÿ�� "R"�� ���Ҽ� �ֽ��ϴ�
	// 0��° ������ Ÿ���� ���Ҽ� ������� ?
	// => �ȵ˴ϴ�. �߸��� �κ� Ư��ȭ
	using type = ? ;
};
*/
// N = 0 �� ��츦 ���ϱ� ���� �κ� Ư��ȭ 
template<typename R, typename T, typename ... Types>
struct argument<0, R(T, Types...)>
{
	using type = T ;
};

// N != 0 �� ���..
template<int N, typename R, typename T, typename ... Types>
struct argument<N, R(T, Types...)>
{
	// int(int, double, char) �� 2��° ���ڴ�
	// int(     double, char) �� 1��° ���ڿ� ����
	// int(             char) �� 0��° ���ڿ� �����ϴ�.

	// 0��° ���� "T" �� ������ �Լ����� N-1 ��° ���� Ÿ�� ���ϱ�
	using type = typename argument<N - 1, R(Types...)>::type;
};

template<typename T> void foo(T& t)
{
	// T : int(int, double, char)
	typename argument<1, T>::type n;

	std::cout << typeid(n).name() << std::endl; // double
}

int main()
{
	foo(f);
}