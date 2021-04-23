#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> findContinuousSequence(int target)
{
	int i = 1;
	int j = 1;
	int sum = 0;
	vector<vector<int>> res;
	while (i <= target / 2)
	{
		if (sum < target)
		{
			sum += j;
			j++;
		}
		else if (sum > target)
		{
			sum -= i;
			i++;
		}
		else
		{
			vector<int> tmp;
			for (int k = i; k < j; k++)
			{
				tmp.push_back(k);
			}
			res.push_back(tmp);
			sum -= i;
			i++;
		}
	}
	return res;
}