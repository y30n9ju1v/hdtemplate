#include <iostream>
#include <vector>

// ��� ��Ҹ� ���ÿ� �����ϴ� �����̳�
struct array
{
	int buff[10];

	int size() const { return 10; }
};
int main()
{
	array arr = { 1,2,3,4,5,6,7,8,9,10 };


	std::cout << arr.size() << std::endl;


}