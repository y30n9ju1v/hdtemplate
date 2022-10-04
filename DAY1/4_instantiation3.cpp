#include <vector>

template<typename T>
T square(T a)
{
	return a * a;
}

template<typename T>
class List
{
public:
	List(int sz, const T& value) {}
};

int main()
{
	// �Լ� ���ø��� "Ÿ�� ����"�� ���� �Ҽ� �ֽ��ϴ�. - C++98 ����.
	square<int>(3);	// ok
	square(3);		// ok 

	// Ŭ���� ���ø��� "C++17" ���� Ÿ�� ���� ���������մϴ�.
	List<int> s1(10, 3);
	List      s2(10, 3);// error. until C++14
						// ok     since c++17

	std::vector<int> v1 = { 1,2,3 };
	std::vector      v2 = { 1,2,3 };  // C++17 ���ʹ� Ÿ�� ���� �����ص�		
										// �˴ϴ�.
}

