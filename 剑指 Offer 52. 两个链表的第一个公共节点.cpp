#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//¼¯ºÏ
//ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
//{
//    ListNode* cura = headA;
//    ListNode* curb = headB;
//    set<ListNode*> set;
//    while (cura)
//    {
//        set.insert(cura);
//        cura = cura->next;
//    }
//    while (curb)
//    {
//        if (set.find(curb) != set.end())
//        {
//            return curb;
//        }
//        curb = curb->next;
//    }
//    return nullptr;
//}

//Ë«Ö¸Õë
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    ListNode* node1 = headA;
    ListNode* node2 = headB;
    while (node1 != node2)
    {
        node1 = node1 != NULL ? node1->next : headB;
        node2 = node2 != NULL ? node2->next : headA;
    }
    return node1;
}
