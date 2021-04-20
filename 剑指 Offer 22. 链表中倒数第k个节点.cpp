#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* l = head;
    ListNode* r = head;
    while (r != nullptr && k > 0)
    {
        r = r->next;
        k--;
    }
    while (r != nullptr)
    {
        l = l->next;
        r = r->next;
    }
    return l;
}