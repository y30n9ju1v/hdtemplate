#include <iostream>
#include <vector>
#include <array>

// ��� ��Ҹ� ���ÿ� �����ϴ� �����̳�
template<typename T, int N>
struct array
{
	T buff[N];

	int size() const { return N; }

	// [] �� ��� ����
	T& operator[](int idx) { return buff[idx]; }
};

int main()
{
	// �ٽ� 1. ����ü �ȿ� �迭�� ������ �Ʒ�ó�� �ʱ�ȭ ����.
	// �ٽ� 2. arr�� ��� ��Ұ� ���ÿ� ���̰� �˴ϴ�. ( �迭�� ����)
	array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };
				// int arr[10] �� �ǹ� ����, ��� �Լ��� �ִ�!!

	// �ٽ� 3. "raw array" �� ��� �Լ��� ������ ������ ���� "array" �� 
	//        ��� �Լ��� �ֽ��ϴ�.
	std::cout << arr.size() << std::endl;
	std::cout << arr[0] << std::endl;

	// �̹� C++ǥ��(C++11) �� ���� ���� array �� �ֽ��ϴ�.
	std::array<int, 5> arr2 = { 1,2,3,4,5 };
}

// ����. ���ø� ���ڷ�
// 1. type
// 2. template => stack ����
// 3. non-type => array ����. �پ��� ��Ұ� �����ѵ�.. "����"�� ���� ����մϴ�.

// �˾� �μ��� 