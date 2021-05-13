#include<iostream>
#include<vector>
using namespace std;
int myAtoi(char* s) {
	int res = 0;
	int sign = 1;
	while (*s == ' ')
	{
		s++;
	}
	if (*s < '0' || *s>'9')
	{
		if (*s == '-')
			sign = -1;
		else if (*s == '+')
			sign = 1;
		else
			return 0;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		if ((res > INT_MAX / 10 || res == INT_MAX / 10 && *s >= '7') && sign == 1)
			return INT_MAX;
		if ((res > INT_MAX / 10 || res == INT_MAX / 10 && *s >= '8') && sign == -1)
			return INT_MIN;
		res = res * 10 + (*s - '0');
		s++;
	}
	res *= sign;
	return res;
}