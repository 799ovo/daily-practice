#include<iostream>
using namespace std;
int add(int a, int b)
{
	while (b)
	{
		int c = (unsigned int)(a & b) << 1;//��λ,c++��֧�ָ�ֵ���ƣ���Ҫǿ��ת��Ϊ�޷�����
		a ^= b;//�޽�λ
		b = c;
	}
	return a;
}