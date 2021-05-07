#include<iostream>
#include<vector>
using namespace  std;
vector<double> dicesProbability(int n)
{
    double sumCount = pow(6, n);   //出现的总点数
    vector<double> ret;
    vector<vector<int>>dp(n + 1, vector<int>(6 * n + 1, 0)); //dp[i][j]表示用i个骰子投出j的次数
    dp[1] = { 0,1,1,1,1,1,1 };  //初始化 dp[1]代表只有一个骰子能投的点数，不可能投出点数为0
    for (int i = 2; i <= n; ++i)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j <= 6 * i; ++j)
        {
            for (int k = 1; k <= min(6, j); ++k)
            {
                //就是当第i个骰子投出了k时，前i-1个骰子要投出的次数即为j-k
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    for (int i = n; i <= 6 * n; ++i)
    {
        ret.push_back(dp[n][i] / sumCount);
    }
    return ret;
}
