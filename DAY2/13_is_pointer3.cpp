#include <iostream>
#include <type_traits>

// ���� ���𹮿��� �����̸��� �����ϸ� Ÿ�Ը� ���� �˴ϴ�.

int a;		// �����̸� :	a	 Ÿ�� : int
double d;	// �����̸� :	d	 Ÿ�� : double

int x[3];	// �����̸� : x	 Ÿ�� : int[3]
			//						T[N] <= ���� Ÿ���� ���� ũ���� �迭
			//						T[3][N]



template<typename T> struct is_array
{
	static constexpr bool value = false; 
	static constexpr int  size = -1; // �迭�� �ƴ� ���
};

template<typename T, int N> struct is_array< T[N] >
{
	static constexpr bool value = true;
	static constexpr int  size = N; 
};


template<typename T> 
void fn(T& arg)
{	
	// T : int
	//     int[3] �Դϴ�
	std::cout << is_array<T>::value << std::endl;
	std::cout << is_array<T>::size  << std::endl;
}
int main()
{
	int n = 0;
	int x[3] = {1,2,3};

	fn(n);	// 0(false)
	fn(x);	// 1(true) ���;� �մϴ�.
	
}