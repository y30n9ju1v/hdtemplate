#include <iostream>
#include <type_traits>

// 변수 선언문에서 변수이름을 제외하면 타입만 남게 됩니다.

int a;		// 변수이름 :	a	 타입 : int
double d;	// 변수이름 :	d	 타입 : double

int x[3];	// 변수이름 : x	 타입 : int[3]
			//						T[N] <= 임의 타입의 임의 크기의 배열
			//						T[3][N]



template<typename T> struct is_array
{
	static constexpr bool value = false; 
	static constexpr int  size = -1; // 배열이 아닌 경우
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
	//     int[3] 입니다
	std::cout << is_array<T>::value << std::endl;
	std::cout << is_array<T>::size  << std::endl;
}
int main()
{
	int n = 0;
	int x[3] = {1,2,3};

	fn(n);	// 0(false)
	fn(x);	// 1(true) 나와야 합니다.
	
}