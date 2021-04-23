#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums)
{
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<int> dp(n, 1);
	int maxsize = 1;
	int maxval = dp[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] % nums[j] == 0)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] > maxsize)
		{
			maxsize = dp[i];
			maxval = nums[i];
		}
	}
	vector<int> res;
	if (maxsize == 1)
	{
		res.push_back(nums[0]);
		return res;
	}
	for (int i = n - 1; i >= 0 && maxsize > 0; i--)
	{
		if (dp[i] == maxsize && maxval % nums[i] == 0)
		{
			res.push_back(nums[i]);
			maxval = nums[i];
			maxsize--;
		}
	}
	return res;
}