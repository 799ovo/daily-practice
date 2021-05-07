#include<iostream>
#include<vector>
using namespace  std;
vector<double> dicesProbability(int n)
{
    double sumCount = pow(6, n);   //���ֵ��ܵ���
    vector<double> ret;
    vector<vector<int>>dp(n + 1, vector<int>(6 * n + 1, 0)); //dp[i][j]��ʾ��i������Ͷ��j�Ĵ���
    dp[1] = { 0,1,1,1,1,1,1 };  //��ʼ�� dp[1]����ֻ��һ��������Ͷ�ĵ�����������Ͷ������Ϊ0
    for (int i = 2; i <= n; ++i)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j <= 6 * i; ++j)
        {
            for (int k = 1; k <= min(6, j); ++k)
            {
                //���ǵ���i������Ͷ����kʱ��ǰi-1������ҪͶ���Ĵ�����Ϊj-k
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
