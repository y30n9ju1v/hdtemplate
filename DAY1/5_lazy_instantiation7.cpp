// ���ø��� Ʋ �Դϴ�.
// ����� ��츸 �ν��Ͻ�ȭ �˴ϴ�.
template<typename T> void fn(T value, int)
{
	*value = 10;
}

template<typename T> void fn(T value, double)
{
}

int main()
{
//	fn(1, 3);	// fn(T, int) ���� ���. �ν��Ͻ�ȭ �Ǹ� ����.

	fn(1, 3.3); // fn(T, double) ���.
				// fn(T, int) ������ �ν��Ͻ�ȭ �ȵǹǷ� ���� �ƴ�.
}