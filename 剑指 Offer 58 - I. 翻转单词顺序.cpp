#include<iostream>
#include<stack>
#include<string>
using namespace std;
string reverseWords(string s)
{
	stack<string> st;
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		string s1;
		while (i < size && !isblank(s[i]))
		{
			s1 += s[i];
			i++;
		}
		if (!s1.empty())
		{
			st.push(s1);
		}
	}
	string s2 = "";
	while (!st.empty())
	{
		s2 += st.top();
		st.pop();
		if (!st.empty())
			s2 += " ";
	}
	return s2;
}