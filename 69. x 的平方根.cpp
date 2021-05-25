#include<iostream>
using namespace std;
int mySqrt(int x)
{
	int left = 1, right = x / 2;
	int mid = (left + right) / 2;
	if (x == 1)
		return 1;
	while (left < right) {

		if (mid == x / mid)
			return mid;
		else if (mid > x / mid)
			right = mid - 1;
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (left > x / left)
		return left - 1;
	return left;
}