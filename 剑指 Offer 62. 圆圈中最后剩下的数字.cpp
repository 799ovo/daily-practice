#include<iostream>
using namespace std;
int f(int n, int m)
{
	if (n == 1)
		return 0;
	int x = f(n - 1, m);
	return (m + x) % n;
}
int lastRemaining(int n, int m)
{
	return f(n, m);
}


//int lastRemaining(int n, int m) {
//    int f = 0;
//    for (int i = 2; i != n + 1; ++i) {
//        f = (m + f) % i;
//    }
//    return f;
//}
