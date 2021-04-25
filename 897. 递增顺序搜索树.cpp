#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* increasingBST(TreeNode* root)
{
    stack<TreeNode*> st;
    TreeNode* last = nullptr;
    TreeNode* res = nullptr;
    while (!st.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (last != nullptr)
        {
            last->right = root;
            last = root;
        }
        else
        {
            last=root;
            res = last;
        }
        root -> left = nullptr;
        root = root->right;
    }
    return res;
}


//µÝ¹éÖØ½¨¶þ²æÊ÷
//void inOrder(TreeNode* root, vector<int>& res)
//{
//    if (root == NULL)  return;
//    inOrder(root->left, res);
//    res.push_back(root->val);
//    inOrder(root->right, res);
//}
//TreeNode* increasingBST(TreeNode* root) {
//    vector<int> res;
//    inOrder(root, res);
//    TreeNode* ans = new TreeNode(0), * cur = ans;
//    for (int v : res)
//    {
//        cur->right = new TreeNode(v);
//        cur = cur->right;
//    }
//
//    return ans->right;
//}