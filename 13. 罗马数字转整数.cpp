#include<iostream>
using namespace std;
int romanToInt(char* s) {
    int n = 0;
    while (*s) {
        switch (*s) {
        case 'I':
            ((*(s + 1) == 'V') || (*(s + 1) == 'X')) ? (n -= 1) : (n += 1);
            break;
        case 'V':
            n += 5;
            break;
        case 'X':
            ((*(s + 1) == 'L') || (*(s + 1) == 'C')) ? (n -= 10) : (n += 10);
            break;
        case 'L':
            n += 50;
            break;
        case 'C':
            ((*(s + 1) == 'D') || (*(s + 1) == 'M')) ? (n -= 100) : (n += 100);
            break;
        case 'D':
            n += 500;
            break;
        case 'M':
            n += 1000;
            break;
        default:
            break;
        }
        s++;
    }
    return n;
}