template<typename T1, typename T2>
struct Object
{
	T1 first;
	T2 second;

	static int cnt;

	Object(const T1& a, const T2& b);
};

// 1. Object �� static ������ cnt �� �ܺ� ������ ������



// 2. Object �� ������ ������ ����� ������ "first(a), second(b)"�� �ʱ�ȭ �ϼ���




int main()
{
	Object<int, double> obj1(1, 3.4);
}