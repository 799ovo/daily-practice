#include<iostream>
#include<vector>
#include<string>
using namespace std;
int translateNum(int num)
{
    string str = "0" + std::to_string(num);
    vector<int> dp(str.size(), 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < str.size(); ++i) {
        dp[i] = dp[i - 1];
        int val = std::stoi(str.substr(i - 1, 2));
        if (10 <= val && val <= 25) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[str.size() - 1];
}