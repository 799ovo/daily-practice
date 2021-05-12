#include<iostream>
#include<vector>
using namespace std;
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
{
	int n = arr.size();
	vector<int> xors(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		xors[i + 1] = xors[i] ^ arr[i];
	}
	int size = queries.size();
	vector<int> res(size, 0);
	for (int i = 0; i < size; i++)
	{
		res[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
	}
	return res;
}