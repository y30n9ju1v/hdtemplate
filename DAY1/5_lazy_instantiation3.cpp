#include <vector>
#include <queue>

// �ٽ� 1. vector �� �������� "����/����" �Ҽ� �����ϴ�.
class queue
{
	std::vector<int> c;
public:
	void push(int a)  {	c.push_back(a);	}
	void pop() 		  {	c.pop_front();	}
};

int main()
{

}