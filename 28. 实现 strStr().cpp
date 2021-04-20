#include<iostream>
using namespace std;
int strStr(string haystack, string needle)
{
	int len1 = haystack.size();
	int len2 = needle.size();
	if (len2 == 0)
		return -1;
	for (int i = 0; i < len1; i++)
	{
		int j = 0;
		if (len2 > len1 - i)
			return {};
		while (haystack[i + j] == needle[j++])
		{
			if (j == len2)
				return i;
		}
	}
	return -1;
}