#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int leastBricks(vector<vector<int>>& wall)
{
	unordered_map<int, int> mp;
	for (vector<int>& vec : wall)
	{
		int sum = 0;
		for (int i = 0; i < vec.size() - 1; i++)
		{
			sum += vec[i];
			mp[sum]++;
		}
	}
	int res = 0;
	for (auto& m : mp)
	{
		res = max(res, m.second);
	}
	return wall.size() - res;
}