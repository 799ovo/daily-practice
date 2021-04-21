#include<iostream>
using namespace std;
double myPow(double x, int n)
{
	if (n < 0)
	{
		x = 1 / x;
		n++;
		n = 0 - n;
	} 
	else if (n == 0)
		return 1;
	else
		n -= 1;
	double res = x;
	while (n != 0)
	{
		if (n % 2 == 1)
		{
			res *= x;
			n--;
		}
		x *= x;
		n /= 2;
	}
	return res;
}