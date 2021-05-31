#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>& height) {

    if (height.size() <= 1)
        return -1;
    int res = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j)
    {
        int h = min(height[i], height[j]);
        res = max(res, h * (j - i));
        if (height[i] < height[j])
            ++i;
        else
            --j;
    }
    return res;
}