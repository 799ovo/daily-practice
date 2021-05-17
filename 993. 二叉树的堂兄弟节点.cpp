#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};
bool isCousins(TreeNode* root, int x, int y) {
    queue<pair<TreeNode*, TreeNode*>> que;
    TreeNode* fa = nullptr;
    que.push({ nullptr,root });
    while (!que.empty())
    {
        for (int i = que.size(); i > 0; i--)
        {
            auto [p,q] = que.front();
            que.pop();
            if (q->val == x || q->val == y)
            {
                if (fa != nullptr && fa != p)
                    return true;
                fa = p;
            }
            if (q->left != nullptr)
                que.push({ q,q->left });
            if (q->right != nullptr)
                que.push({ q,q->right });
        }
        if (fa != nullptr)
            return false;
    }
    return false;
}