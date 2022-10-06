#include <iostream>

// 231 page

//template<typename T> 
//void fn(T   a) { std::cout << " T " << std::endl; }

//void fn(int a) { std::cout << "int" << std::endl; }

//void fn( ... ) { std::cout << "..." << std::endl; }


int main()
{
	fn(3);	// 1. fn(int) 버전 사용. 
			// 2. fn(int) 버전이 없다면, fn(T) 사용
			// 3. fn(T)   버전도 없다면, fn(...) 사용
			// 4. fn(...) 버전도 없다면, error
}
