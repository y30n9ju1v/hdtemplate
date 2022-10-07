#include <iostream>

// Step 1. 가변 인자 템플릿 사용
template<typename ... Types>
struct tuple
{
	static constexpr std::size_t N = 0; // 저장하는 요소의 갯수
};

int main()
{
	tuple<> t0;

	tuple<char> t1;
	
	tuple<double, char> t2;
	
	tuple<int, double, char> t3;
}
