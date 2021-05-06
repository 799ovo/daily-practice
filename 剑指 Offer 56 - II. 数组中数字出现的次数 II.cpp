#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//int singleNumber(vector<int>& nums) {
//    unordered_map<int, int> mp;
//    int res;
//    for (auto num : nums)
//    {
//        mp[num]++;
//    }
//    for (auto m : mp)
//    {
//        if (m.second == 1)
//            res = m.first;
//    }
//    return res;
//}


int singleNumber(vector<int>& nums) 
{
	vector<int> bit(32, 0);
	for (auto num : nums)
	{
		for (int i = 0; i < 32; i++)
		{
			bit[i] += num & 1;
			num >>= 1;
		}
	}
	int res = 0;
	for (int i = 31; i >= 0; i--)
	{
		res <<= 1;
		res += bit[i] % 3;
	}
	return res;
}