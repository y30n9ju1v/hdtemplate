
// �Ʒ� �ڵ尡 "modern c++ design(2002)" å�� ���ڰ� 2002��濡 ���� �ڵ��Դϴ�.

template<int N> 
struct int2type
{
	enum { value = N };
};

int main()
{
	fn(0);
	fn(1); // 0, 1 �� ��� ���� Ÿ��(int) �Դϴ�. 
			// ����, fn(0), fn(1) �� ���� �Լ��� ȣ���մϴ�.

	int2type<0> t0;
	int2type<1> t1;

	fn(t0);
	fn(t1); // t0, t1�� �ٸ� Ÿ���Դϴ�.
			// fn(t0), fn(t1)�� �ٸ� �Լ��� ȣ���մϴ�.
			// 77, 78 �� ���� Ÿ���Դϴ�.
			// int2type<77>, int2type<78> �� �ٸ� Ÿ���Դϴ�.
}