#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//µ›πÈ
//int maxDepth(TreeNode* root)
//{
//    if (root == nullptr)
//        return 0;
//    int ln = maxDepth(root->left);
//    int rn = maxDepth(root->right);
//    return ln >= rn ? ln + 1 : rn + 1;
//}


//∑«µ›πÈ£®∂”¡–£©
int maxDepth(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    if (root == nullptr)
        return 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        depth++;
    }
    return depth;
}