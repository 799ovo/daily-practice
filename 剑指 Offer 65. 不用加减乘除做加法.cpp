#include<iostream>
using namespace std;
int add(int a, int b)
{
	while (b)
	{
		int c = (unsigned int)(a & b) << 1;//进位,c++不支持负值左移，需要强制转换为无符号数
		a ^= b;//无进位
		b = c;
	}
	return a;
}