#include<iostream>
#include<unordered_map>
using namespace std;
char firstUniqChar(string s) {
    unordered_map<char, int> mp;
    for (auto a : s)
    {
        mp[a]++;
    }
    for (auto b : s)
    {
        if (mp[b] == 1)
            return b;
    }
    return ' ';
}