#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>

template<typename Iter, typename T>
	requires (!std::predicate<T, std::iter_value_t<Iter>>)
Iter find(Iter first, Iter last, const T& value)
{
	std::cout << "�� �˻� ����" << std::endl;
	return first;
}

// std::predicate<T, Ÿ��> : T��  "Ÿ�԰�ü" �� 1��° ���ڷ� �ؼ� ȣ�Ⱑ���Ѱ�?
//							���(��ȯŸ��)�� bool �� ��ȯ�ɼ� �ִ°� ?
template<typename Iter, typename T> 
			requires std::predicate<T, std::iter_value_t<Iter>>
Iter find(Iter first, Iter last, T func)
{
	std::cout << "�Լ� ����" << std::endl;
	return first;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p1 = find(std::begin(v), std::end(v), 3);
	auto p2 = find(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });


}