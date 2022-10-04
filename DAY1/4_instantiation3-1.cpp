#include <vector>

template<typename T>
class List
{
public:
	List(int sz, const T& value) {}
	List() {}

	// STL �����̳ʸ� ���ڷ� ������ ������
	template<typename C>
	List(const C& c) {}  

	template<typename IT>
	List(IT first, IT last) {} // �ݺ��ڴ� "call by value"�� �޾Ƶ� �˴ϴ�.

};
// C++17 "class template type deduction guide" ����
// �����ڸ�� -> List<Ÿ��>
List()->List<int>;

template<typename C>
List(const C& c)->List<typename C::value_type>;   // ���� C�� vector<int>

template<typename IT>
List(IT first, IT last)->List< typename IT::value_type >;

int main()
{
	List<int> s1(10, 3);
	List      s2(10, 3);
	List      s3; // "deduction guide" �� �����Ƿ� List<int> �Դϴ�.
				  // �׷���, �� ���� "����"���� �ϴ°� �����ϴ�.

	std::vector v = { 1,2,3 };
	List s4(v); // ?

	List s5(v.begin(), v.end()); // �������� �ʰ� 
						// �����ڿ� "deduction guide" ������ ������
}

