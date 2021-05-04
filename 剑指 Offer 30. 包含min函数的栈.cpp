#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st1;
    stack<int> st2;
    MinStack() {

    }

    void push(int x) {
        st1.push(x);
        if (st2.empty() || x < st2.top())
        {
            st2.push(x);
        }
        else
            st2.push(st2.top());
    }

    void pop() {
        st1.pop();
        st2.pop();
    }

    int top() {
        return st1.top();
    }

    int min() {
        return st2.top();
    }
};