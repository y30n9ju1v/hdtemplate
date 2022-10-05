#include <algorithm>
#include <functional>
#include <vector>


int main()
{
	std::vector<int> v = { 1,2,3,4,5 };


	std::less<int> f;	// C++ ǥ�ؿ� �ִ� �Լ� ��ü. ���ø� �Դϴ�.
	std::sort(v.begin(), v.end(), f);


	// less �� ����Ҷ��� ���� �Ʒ� ó�� �ӽð�ü ���·� �����մϴ�.(C++17����)
	std::sort(v.begin(), v.end(), std::less<int>());

	// C++14 ���� less �� ���ø� ���ڿ� ����Ʈ ���� �ֽ��ϴ�.
	std::sort(v.begin(), v.end(), std::less<>()); // C++14���� ����
	std::sort(v.begin(), v.end(), std::less());  // C++17���� ����
	std::sort(v.begin(), v.end(), std::less{});  // {} �� ����


}
