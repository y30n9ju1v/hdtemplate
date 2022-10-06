#include <iostream>

class Test
{
public:
	int size() { return 10; }
};
//---------------------------------
// 핵심 : 아래 ? 자리에 T(Test) 클래스에 "size()" 함수가 없을때 실패하는 코드를
//       작성하면 됩니다.

template<typename T> void check(? ) { std::cout << "T" << std::endl; }

template<typename T> void check(...) { std::cout << "..." << std::endl; }

int main()
{
	check<Test>(0);
}