#include <iostream>
#include <vector>
#include <type_traits>

// Container ��� ����(Concept)�� ������ ���ô�.

template<typename T>
concept container = requires(T& c)
{
	// �ǹ� : �����̳ʴ� begin(), end() ��� �Լ��� �־�� �Ѵ�.
	// c.begin();
	// c.end();
	
	// �ǹ� : �����̳ʴ� std::begin()/std::end() �� ���ڰ� �ɼ� �ִ� ���̴�.
	std::begin(c);
	std::end(c);
};
template<typename T> void check(T& c)
{
	// T �� "container" �䱸 ������ �����ϴ��� �����Ϸ���
	// �Ʒ� ó�� �մϴ�.
	// ������ �ð��� �����ϰ� �˴ϴ�.
	std::cout << container<T> << std::endl;
}
int main()
{
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n);
	check(v);
	check(x);
}