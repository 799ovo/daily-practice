#include<iostream>
#include<vector>
using namespace std;
int xorOperation(int n, int start)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res ^= (start + i * 2);
	}
	return res;
}