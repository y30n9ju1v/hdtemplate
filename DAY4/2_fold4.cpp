#include <iostream>
template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}
// (args + ...)	    // E1+(E2+(E3+(E4+E5)))		 unary  right fold
// (args + ... + 0) // E1+(E2+(E3+(E4+(E5+0))))  binary right fold

// (... + args)	    // (((E1+E2)+E3)+E4)+E5		 unary  left fold
// (0 + ... + args) // ((((0+E1)+E2)+E3)+E4)+E5  binary left fold


template<typename ... Types>
void show(Types... args)
{
	// �ٽ� 1. �ʱⰪ���� ��ü�� ����ص� �ǰ�
	//       "<<" ���� �����ڰ� "������ ������" �Ǿ� �ִٸ� �پ��ϰ� Ȱ�밡��
// (std::cout << ... << args); // �� �ּ��� ���� �� ������ ������
	// �ʱⰪ   op ... op pack   
	// ((((std::cout << 1) << 2) << 3) << 4) << 5


	// �ٽ� 2. pack �̸� �ڸ����� "pack �� ����ϴ� ����" �� �־ �˴ϴ�.
	(printv(args) ,  ...);  // �����������ø�4���� printv ������ ������
	// pack       op ... 
	// printv(E1), (printv(E2), (printv(E3), (printv(E4), printv(E5))))	

	// fold �� ������ ����
//	int dummy[] = { 0, (printv(args), 0)... };
}


int main()
{
	show(1, 2, 3, 4, 5);
}
