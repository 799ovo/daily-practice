#include<iostream>
#include<vector>
using namespace std;
int strToInt(char* str)
{
	int res = 0;
	int sign = 1;
	while (*str == ' ')
	{
		str++;
	}
	if (*str < '0' || *str>'9')
	{
		if (*str == '-')
			sign = -1;
		else if (*str == '+')
			sign = 1;
		else
			return 0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((res > INT_MAX / 10 || res == INT_MAX / 10 && *str >= '7') && sign == 1)
			return INT_MAX;
		if ((res > INT_MAX / 10 || res == INT_MAX / 10 && *str >= '8') && sign == -1)
			return INT_MIN;
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= sign;
	return res;
}