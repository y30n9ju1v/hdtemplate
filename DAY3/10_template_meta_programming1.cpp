#include <iostream>

template<std::size_t N> struct Factorial
{
	enum { value = N * Factorial<N-1>::value };
};

// 재귀를 종료하기 위해 N=1 인 경우의 특수화
template<> struct Factorial<1>
{
	enum { value = 1 };
};

int main()
{
	// 아래 한줄의 결과 생각해 보세요.
	// => 5! 를 "컴파일 시간"에 연산한것입니다.
	int ret = Factorial<5>::value;
				// 5 * F<4>::value
				//     4 * F<3>::value
				//		   3 * F<2>::value
				//		       2 * F<1>::value
				//                 1
	
	std::cout << ret << std::endl;

	// template meta programming
	// => 템플릿 기술을 사용해서 "임의의 연산을 컴파일 시간"에 수행하는 것

	// 단, 템플릿 인자는 변수를 사용할수 없습니다.
	int n = 5;
//	int ret2 = Factorial<n>::value; // error
	int ret3 = Factorial<5>::value; // ok


	int n1 = 0b1010; // C++11 부터는 이진수 가능합니다.
					 // C++11 이전에는 이진수 안됩니다.
	int n2 = binary<1010>::value; // C++11 이전에 이 템플릿 만들어서
									// 사용하곤 했습니다.

	std::cout << n2 << std::endl; // 9..  binary  도전해 보세요
									// 구글검색하면 나옵니다.
									
}