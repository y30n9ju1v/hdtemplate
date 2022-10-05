#include <iostream>

template<typename T> 
void fn(T a)   { std::cout << "T" << std::endl; }

void fn(int n);// { std::cout << "int" << std::endl; }


int main()
{
	fn(3.3);	// fn(T) 사용

	fn(3);		// fn(int) 사용
				// fn(int) 가 없다면       : fn(T) 사용
				// fn(int) 가 선언만 있다면 : 링크 에러 발생

	// 즉, fn(T) 가 있어도, int 버전의 선언이 있다면
	// 링커가 int 버전을 찾으려고 시도하고, 없으면 링크 에러.
}