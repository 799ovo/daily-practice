#include<iostream>
#include<vector>
using namespace std;
vector<int> constructArr(vector<int>& a)
{
    int n = a.size();
    // ���ؽ���ļ���
    vector<int> b(n, 1);
    // ���ϵ��£����½ǵı���
    for (int i = 1; i < n; ++i)
    {
        b[i] *= b[i - 1] * a[i - 1];
    }


    int accu = 1; // �ۼƳ˻��Ľ�������ں�b[i] ������
    // ���µ��ϣ����Ͻǵı���
    for (int i = n - 2; i >= 0; --i)
    {
        accu *= a[i + 1];
        b[i] *= accu;
    }

    return b;
}