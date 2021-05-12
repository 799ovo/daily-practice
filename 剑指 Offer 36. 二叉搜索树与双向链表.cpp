#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return NULL;
        }
        traversal(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node* pre, * head;
    void traversal(Node* cur) {
        if (!cur) {
            return;
        }
        traversal(cur->left);
        if (pre) {
            pre->right = cur;
        }
        else {
            head = cur;
        }
        cur->left = pre;
        pre = cur;
        traversal(cur->right);
    }
};