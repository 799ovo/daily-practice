#include<iostream>
#include<vector>
using namespace std;
vector<int> decode(vector<int>& encoded)
{
	int len = encoded.size();
	int n = len + 1;
	vector<int> res(n,0);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum ^= i;
	}
	for (int i = len - 1; i >= 0; i -= 2)
	{
		sum ^= encoded[i];
	}
	res[0] = sum;
	for (int i = 1; i < n; i++)
	{
		res[i] = res[i - 1] ^ encoded[i-1];
	}
	return res;
}