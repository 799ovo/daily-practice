#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool compare(string s1, string s2)
{
	return s1 + s2 < s2 + s1;
}
string minNumber(vector<int>& nums)
{
	vector<string> vec;
	string str;
	for (auto num : nums)
	{
		vec.push_back(to_string(num));
	}
	sort(vec.begin(), vec.end(), compare);
	for (auto s : vec)
		str += s;
	return str;
}