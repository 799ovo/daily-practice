#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices)
{
	if (prices.size() == 0)
		return 0;
	int min = prices[0];
	int res = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		res = max(res,prices[i] - min);
		if (min > prices[i])
			min = prices[i];
	}
	return res;
}