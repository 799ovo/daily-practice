#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<TreeNode*> q;
    vector<vector<int>> res;
    if (root == nullptr)
        return res;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> tmp;
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            tmp.push_back(node->val);
            q.pop();
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        if (res.size() % 2 == 1)
            reverse(tmp.begin(), tmp.end());
        res.push_back(tmp);
    }
    return res;
}