#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> res;
	if (matrix.size() == 0)
		return res;
	int up = 0;//上边界
	int down = matrix.size() - 1;//下边界
	int left = 0;//左边界
	int right = matrix[0].size() - 1;//右边界
	while (1)
	{
		for (int i = left; i <= right; i++)//向右
		{
			res.push_back(matrix[up][i]);
		}
		if (++up > down)
			break;
		for (int j = up; j <= down; j++)//向下
		{
			res.push_back(matrix[j][right]);
		}
		if (--right < left)
			break;
		for (int k = right; k >= left; k--)//向左
		{
			res.push_back(matrix[down][k]);
		}
		if (--down < up)
			break;
		for (int m = down; m >= up; m--)//向上
		{
			res.push_back(matrix[m][left]);
		}
		if (++left > right)
			break;
	}
	return res;
}