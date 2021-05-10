#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void dfs(TreeNode* root, vector<int>& vec)
{
    if (root->left == nullptr && root->right == nullptr)
        vec.push_back(root->val);
    else
    {
        if (root->left != nullptr)
            dfs(root->left, vec);
        if (root->right != nullptr)
            dfs(root->right, vec);
    }
}
bool leafSimilar(TreeNode* root1, TreeNode* root2)
{
    vector<int> vec1;
    vector<int> vec2;
    if (root1 != nullptr)
        dfs(root1, vec1);
    if (root2 != nullptr)
        dfs(root2, vec2);
    return vec1 == vec2;
}