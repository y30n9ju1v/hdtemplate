// �Ʒ� �ڵ�� ������ ������� ?
template<typename T> 
void fn(T value)
{
	// if : ����ð� ���ǹ�
	//      ������ �Ҷ� ������ "false"�� �����Ǿ
	//      "*value = 10" �� �ν��Ͻ�ȭ�� ���Ե˴ϴ�.
//	if ( false )
//		*value = 10;

	// if constexpr : ������ �ð� ���ǹ� ( C++17 ���� ����)
	//				  ������ false �� �����Ǹ�
	//				  �ش� ������ "�ν��Ͻ�ȭ�� ���� �ȵ�"
	if constexpr (false)
		*value = 10;
}

int main()
{
	int n = 10;
	fn(n);
}
