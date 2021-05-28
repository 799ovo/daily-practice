#include<iostream>
#include<vector>
using namespace std;
string convert(string s, int numRows) {
    string res;
    int step = 2 * (numRows - 1);//��0�к����һ�еļ��
    int gap = 0;//�м��еļ�ࣨ������
    int index = 0;//��ǰ�±�
    int length = s.size();
    if (numRows < 1)
        return res;
    if (numRows == 1)
        return s;
    else
    {
        for (int i = 0; i < numRows; ++i)
        {
            index = i;
            gap = 2 * i;
            while (index < length)
            {
                res += s[index];
                gap = step - gap;
                index += (i == 0 || i == numRows - 1) ? step : gap;
            }
        }
    }
    return res;
}