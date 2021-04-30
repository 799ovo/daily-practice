#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int singleNumber(vector<int>& nums)
{
	unordered_map<int, int> mp;
	for (auto a : nums)
	{
		mp[a]++;
	}
	int res = 0;
	for (auto &a : mp)
	{
		if (a.second == 1)
			res = a.first;
	}
	return res;
}