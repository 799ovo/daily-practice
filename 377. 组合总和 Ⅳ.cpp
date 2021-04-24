#include<iostream>
#include<vector>
using namespace std;
int combinationSum4(vector<int>& nums, int target)
{
	vector<int> dp(target + 1);
	dp[0] = 1;
	for (int i = 1; i <= target; i++)
	{
		for (auto m : nums)
		{
			if (m <= i && dp[i - m] < INT_MAX - dp[i])
				dp[i] += dp[i - m];
		}
	}
	return dp[target];
}