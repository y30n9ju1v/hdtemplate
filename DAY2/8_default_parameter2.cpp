#include <algorithm>
#include <functional>
#include <vector>


int main()
{
	std::vector<int> v = { 1,2,3,4,5 };


	std::less<int> f;	// C++ 표준에 있는 함수 객체. 템플릿 입니다.
	std::sort(v.begin(), v.end(), f);


	// less 를 사용할때는 보통 아래 처럼 임시객체 형태로 전달합니다.(C++17이전)
	std::sort(v.begin(), v.end(), std::less<int>());

	// C++14 부터 less 의 템플릿 인자에 디폴트 값이 있습니다.
	std::sort(v.begin(), v.end(), std::less<>()); // C++14부터 가능
	std::sort(v.begin(), v.end(), std::less());  // C++17부터 가능
	std::sort(v.begin(), v.end(), std::less{});  // {} 도 가능


}
