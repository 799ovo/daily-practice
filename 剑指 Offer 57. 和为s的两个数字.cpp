#include<iostream>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> res;
	int len = nums.size();
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		int tmp = nums[left] + nums[right];
		if (tmp < target)
			left++;
		else if (tmp > target)
			right--;
		else
		{
			res.push_back(nums[left]);
			res.push_back(nums[right]);
			break;
		}
	}
	return res;
}
