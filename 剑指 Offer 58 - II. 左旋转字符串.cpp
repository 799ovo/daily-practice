#include<iostream>
using namespace std;
string reverseLeftWords(string s, int n)
{
    return s.substr(n) + s.substr(0, n);
}