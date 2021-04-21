#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



//单调栈
bool verifyPostorder(vector<int>& postorder)
{
    if (postorder.size() == 0)
        return true;
    stack<int> st;
    int n = postorder.size();
    int tmp = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (postorder[i] > tmp)
        {
            return false;
        }
        while (!st.empty()&&st.top()>postorder[i])
        {
            tmp = st.top();
            st.pop();
        }
        st.push(postorder[i]);
    }
    return true;
}


//递归
bool verifyPostorder1(vector<int>& postorder) {
    if (postorder.empty()) return true;
    int len = postorder.size();
    return recursion(postorder, 0, len - 1);
}
bool recursion(vector<int>& postorder, int left, int right)
{
    if (left >= right) return true; // 没有左子树（比如[5,4,3,2,1]），true
    int root = postorder[right];
    int pos = left; // 必须要设置一个 pos 变量保存 left，不能直接操作 left！
    for (; pos < right; ++pos)
    {
        // 找到右子树起点
        if (postorder[pos] > root) break;
    }
    for (int j = pos; j < right; ++j)
    {
        // 如果右子树部分有小于 root 的，false
        if (postorder[j] < root) return false;
    }
    // 看左子树是否也是后序遍历。如果前面不设置 pos 的话，这里就会是 (postorder,0,left-1)，会严重超时
    if (!recursion(postorder, left, pos - 1)) return false;
    if (!recursion(postorder, pos, right - 1)) return false;// 看右子树是否也是后序遍历
    return true;
}
