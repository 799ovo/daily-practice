#include<iostream>
using namespace std;
int sumNums(int n)
{
    n && (n+=sumNums(n - 1));//and的短路特性
    return n;
}