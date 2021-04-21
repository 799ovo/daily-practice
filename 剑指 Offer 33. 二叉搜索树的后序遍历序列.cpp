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



//����ջ
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


//�ݹ�
bool verifyPostorder1(vector<int>& postorder) {
    if (postorder.empty()) return true;
    int len = postorder.size();
    return recursion(postorder, 0, len - 1);
}
bool recursion(vector<int>& postorder, int left, int right)
{
    if (left >= right) return true; // û��������������[5,4,3,2,1]����true
    int root = postorder[right];
    int pos = left; // ����Ҫ����һ�� pos �������� left������ֱ�Ӳ��� left��
    for (; pos < right; ++pos)
    {
        // �ҵ����������
        if (postorder[pos] > root) break;
    }
    for (int j = pos; j < right; ++j)
    {
        // ���������������С�� root �ģ�false
        if (postorder[j] < root) return false;
    }
    // ���������Ƿ�Ҳ�Ǻ�����������ǰ�治���� pos �Ļ�������ͻ��� (postorder,0,left-1)�������س�ʱ
    if (!recursion(postorder, left, pos - 1)) return false;
    if (!recursion(postorder, pos, right - 1)) return false;// ���������Ƿ�Ҳ�Ǻ������
    return true;
}
