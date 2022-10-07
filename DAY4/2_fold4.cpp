#include <iostream>
template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}
// (args + ...)	    // E1+(E2+(E3+(E4+E5)))		 unary  right fold
// (args + ... + 0) // E1+(E2+(E3+(E4+(E5+0))))  binary right fold

// (... + args)	    // (((E1+E2)+E3)+E4)+E5		 unary  left fold
// (0 + ... + args) // ((((0+E1)+E2)+E3)+E4)+E5  binary left fold


template<typename ... Types>
void show(Types... args)
{
	// 핵심 1. 초기값으로 객체를 사용해도 되고
	//       "<<" 등의 연산자가 "연산자 재정의" 되어 있다면 다양하게 활용가능
// (std::cout << ... << args); // 위 주석을 보고 잘 생각해 보세요
	// 초기값   op ... op pack   
	// ((((std::cout << 1) << 2) << 3) << 4) << 5


	// 핵심 2. pack 이름 자리에는 "pack 을 사용하는 패턴" 을 넣어도 됩니다.
	(printv(args) ,  ...);  // 가변인자템플릿4에서 printv 복사해 오세요
	// pack       op ... 
	// printv(E1), (printv(E2), (printv(E3), (printv(E4), printv(E5))))	

	// fold 가 없었던 시절
//	int dummy[] = { 0, (printv(args), 0)... };
}


int main()
{
	show(1, 2, 3, 4, 5);
}
