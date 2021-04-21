#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> res;
	if (matrix.size() == 0)
		return res;
	int up = 0;//�ϱ߽�
	int down = matrix.size() - 1;//�±߽�
	int left = 0;//��߽�
	int right = matrix[0].size() - 1;//�ұ߽�
	while (1)
	{
		for (int i = left; i <= right; i++)//����
		{
			res.push_back(matrix[up][i]);
		}
		if (++up > down)
			break;
		for (int j = up; j <= down; j++)//����
		{
			res.push_back(matrix[j][right]);
		}
		if (--right < left)
			break;
		for (int k = right; k >= left; k--)//����
		{
			res.push_back(matrix[down][k]);
		}
		if (--down < up)
			break;
		for (int m = down; m >= up; m--)//����
		{
			res.push_back(matrix[m][left]);
		}
		if (++left > right)
			break;
	}
	return res;
}