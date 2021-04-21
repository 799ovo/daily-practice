#include<iostream>
#include<vector>
using namespace std;
vector<int> exchange(vector<int>& nums)
{
	int n = nums.size();
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		while (left < right && nums[left] % 2 == 1)
			left++;
		while (left < right && nums[right] % 2 == 0)
			right--;
		if (left < right)
		{
			int tmp = nums[right];
			nums[right] = nums[left];
			nums[left] = tmp;
		}
	}
	return nums;
}