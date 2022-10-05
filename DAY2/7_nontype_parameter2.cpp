#include <iostream>

template<typename T, int N> 
struct Object
{
};

int main()
{
	int n = 10;
	Object<int,  n> obj1;
	Object<int, 10> obj2;
}