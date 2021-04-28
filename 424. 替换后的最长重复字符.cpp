#include<iostream>
#include<vector>
using namespace std;
int characterReplacement(string s, int k)
{
	vector<int> vec(26, 0);
	int a = 0;
	int left = 0;
	int right = 0;
	for (right = 0; right < s.size(); right++)
	{
		a = max(a, ++vec[s[right] - 'A']);
		if (right - left + 1 - a > k)
			--vec[s[left++] - 'A'];
	}
	return s.size() - left;
}