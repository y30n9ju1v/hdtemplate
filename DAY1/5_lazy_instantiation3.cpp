#include <vector>
#include <queue>

// �ٽ� 1. vector �� �������� "����/����" �Ҽ� �����ϴ�.
class queue
{
	std::vector<int> c;
public:
	// �ٽ� 2. ���� queue �����ø��� �ƴմϴ�.
	// ��� �Լ��� ������� �ʾƵ� "�߸��� �ڵ尡 ������ ����" �Դϴ�.
	void push(int a)  {	c.push_back(a);	} // ok
	void pop() 		  {	c.pop_front();	} // error
};

int main()
{

}