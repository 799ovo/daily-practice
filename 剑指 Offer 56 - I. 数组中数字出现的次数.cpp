#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> singleNumbers(vector<int>& nums)
{
	vector<int> res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1;)
	{
		if (nums[i] == nums[i + 1])
			i += 2;
		else
			res.push_back(nums[i++]);
	}
	if (nums.back() != nums[nums.size() - 2])
		res.push_back(nums.back());
	return res;
}