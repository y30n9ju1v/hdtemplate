#include <iostream>

class Test
{
public:
	Test(int a) {}	// 이 생성자가 있으므로 
					// 이제 "Test"의 디폴트 생성자는 없습니다

	int size() { return 10; }
};

// 아래 코드를 잘생각해 보세요
template<typename T> T declval(); // 구현은 없습니다. 선언만!!
								// 평가되지 않은 표현식에서
								// 생성자 모양에 상관없이 
								// 객체를 생성한다고 가정할때 사용합니다.
								// C++11 에서 표준에 추가.


//template<typename T> void check(decltype( declval<T>().size())*)
template<typename T> void check(decltype(std::declval<T>().size())*)
{
	std::cout << "T" << std::endl;
}

template<typename T> void check(...)
{
	std::cout << "..." << std::endl;
}

int main()
{
	check<Test>(0);
}