#include<iostream>
#include<string>
#include<vector>
using namespace std;
int findNthDigit(int n) {
    // ����������ɼ�λ������ɣ���1λ��digits = 1��2λ��digits = 2...
    long base = 9, digits = 1;
    while (n - base * digits > 0) {
        n -= base * digits;
        base *= 10;
        digits++;
    }
    // ������ʵ����������Ƕ���
    int idx = n % digits;  // ע����������ļ��㣬n���ڱ�ʾdigitsλ���ĵ�n������
    if (idx == 0)idx = digits;
    long number = 1;
    for (int i = 1; i < digits; i++)
        number *= 10;
    number += (idx == digits) ? n / digits - 1 : n / digits;

    // ����ʵ���������ҵ�������Ҫ���Ǹ�����
    for (int i = idx; i < digits; i++) number /= 10;
    return number % 10;
}