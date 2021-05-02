#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int depth(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}
bool isBalanced(TreeNode* root)
{
    if (root == nullptr)
        return true;
    bool flag = abs(depth(root->left) - depth(root->right)) <= 1;
    return flag && isBalanced(root->left) && isBalanced(root->right);
}