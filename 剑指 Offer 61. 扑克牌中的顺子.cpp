#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int a = 0;//0¸öÊý
    int dif = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == 0)
        {
            a++;
            continue;
        }
        else
        {
            if (nums[i] == nums[i + 1])
                return false;
            if (nums[i] + 1 != nums[i + 1])
                dif += nums[i + 1] - nums[i] - 1;
        }
    }
    return a >= dif;
}