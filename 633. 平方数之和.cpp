#include<iostream>
using namespace std;
bool judgeSquareSum(int c)
{
	long a = 0;
	long b = (long)sqrt((double)c);
	while (a <= b)
	{
		if (a * a + b * b < c)
			a++;
		else if (a * a + b * b > c)
			b--;
		else
			return true;
	}
	return false;
}
