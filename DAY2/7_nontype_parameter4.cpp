#include <iostream>
#include <vector>
#include <array>

// 모든 요소를 스택에 보관하는 컨테이너
template<typename T, int N>
struct array
{
	T buff[N];

	int size() const { return N; }

	// [] 로 요소 접근
	T& operator[](int idx) { return buff[idx]; }
};

int main()
{
	// 핵심 1. 구조체 안에 배열이 있으면 아래처럼 초기화 가능.
	// 핵심 2. arr는 모든 요소가 스택에 놓이게 됩니다. ( 배열과 동일)
	array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };
				// int arr[10] 의 의미 지만, 멤버 함수가 있다!!

	// 핵심 3. "raw array" 는 멤버 함수가 없지만 위에서 만든 "array" 는 
	//        멤버 함수가 있습니다.
	std::cout << arr.size() << std::endl;
	std::cout << arr[0] << std::endl;

	// 이미 C++표준(C++11) 에 위와 같은 array 가 있습니다.
	std::array<int, 5> arr2 = { 1,2,3,4,5 };
}

// 정리. 템플릿 인자로
// 1. type
// 2. template => stack 예제
// 3. non-type => array 예제. 다양한 요소가 가능한데.. "정수"를 많이 사용합니다.

// 알아 두세요 