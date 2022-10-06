// 6_enable_if1.cpp

// �Ʒ� enable_if �� "C++11 ǥ��" �� �̹� �ִ� �ڵ� �Դϴ�.

template<bool, typename T = void > struct enable_if
{
//	typedef  T type; // C++11 ���� ��Ÿ��
	using type = T;  // C++11 ���� ��Ÿ��
};

template<typename T> struct enable_if<false, T> 
{
	// �ٽ� : �� �������� "type" �� ���ٴ� ��. 
};
// enable_if ���� : enable_if<bool���, Ÿ��>

int main()
{
	// �Ʒ� �ڵ忡�� �� ������ Ÿ���� ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2 �ε�. 
									// void ������ ����� ���� ������ error
	enable_if<false, int>::type n3; // error
									// "::type" �� ����.

	// �Ʒ� ���� �ܿ켼��
//	enable_if<true, Ÿ��>::type => "Ÿ��" �Դϴ�.
//	enable_if<true>::type      => "void" �Դϴ�.
//	enable_if<false, Ÿ��>::type  => error. "::type" �����ϴ�.
}