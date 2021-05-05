#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//int deleteAndEarn(vector<int>& nums)
//{
//	vector<int> vec(10001, 0);
//	for (int i = 0; i < nums.size(); i++)
//	{
//		vec[nums[i]] += nums[i];
//	}
//	vector<int> dp(10001, 0);
//	dp[0] = 0;
//	dp[1] = vec[1];
//	for (int j = 2; j < vec.size(); j++)
//	{
//		dp[j] = max(dp[j - 1], dp[j - 2] + vec[j]);
//	}
//	return dp[dp.size() - 1];
//}


int deleteAndEarn(vector<int>& nums)
{
	unordered_map<int, int> mp;
	int maxnum = 0;
	for (auto m : nums)
	{
		mp[m]+=m;
		maxnum = max(maxnum, m);
	}
	unordered_map<int, int> dp;
	dp[0] = 0;
	dp[1] = mp.count(1) ? mp[1] : 0;
	for (int i = 2; i <= maxnum; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + mp[i]);
	}
	return dp[maxnum];
}