#include <iostream>

void fn(...) 
{ 
	std::cout << "..." << std::endl; 
}

// �Ʒ� �ڵ�� SFINAE �� ����ɱ�� ? �����ϱ�� ?
// => error
// => SFINAE �� �Լ� signature(���� Ÿ�԰� ����, ���ø� ����) ���� ����˴ϴ�.
template<typename T> 
void fn(T a) 
{ 
	typename T::type n;  // int::type n;
}

int main()
{
	fn(3); // T=int
}
