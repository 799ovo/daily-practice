#include<iostream>
#include<vector>
using namespace std;
//Ħ��ͶƱ��
int majorityElement(vector<int>& nums)
{
	int count = 0;
	int res = 0;
	for (int i = 0;i < nums.size(); i++)
	{
		if (count == 0)
		{
			res = nums[i];
			count++;
		}
		else
		{
			res == nums[i] ? count++ : count--;
		}
	}
	return res;
}