#include <iostream>

// 231 page

//template<typename T> 
//void fn(T   a) { std::cout << " T " << std::endl; }

//void fn(int a) { std::cout << "int" << std::endl; }

//void fn( ... ) { std::cout << "..." << std::endl; }


int main()
{
	fn(3);	// 1. fn(int) ���� ���. 
			// 2. fn(int) ������ ���ٸ�, fn(T) ���
			// 3. fn(T)   ������ ���ٸ�, fn(...) ���
			// 4. fn(...) ������ ���ٸ�, error
}
