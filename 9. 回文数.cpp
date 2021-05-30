#include<iostream>
using namespace std;
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    else
    {
        long tmp = x;
        long y = 0;
        while (tmp)
        {
            y = y * 10 + tmp % 10;
            tmp /= 10;
        }
        return (x == y);
    }

}