#include<iostream>
using namespace std;
class Node
{
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};   
Node* copyRandomList(Node* head)
{
    if (head == nullptr) return nullptr;
    Node* cur = head;
    // 1. ���Ƹ��ڵ㣬������ƴ������
    while (cur != nullptr)
    {
        Node* tmp = new Node(cur->val);
        tmp->next = cur->next;
        cur->next = tmp;
        cur = tmp->next;
    }
    // 2. �������½ڵ�� random ָ��
    cur = head;
    while (cur != nullptr)
    {
        if (cur->random != nullptr)
            cur->next->random = cur->random->next;
        cur = cur->next->next;
    }
    // 3. ���������
    cur = head->next;
    Node* pre = head, * res = head->next;
    while (cur->next != nullptr)
    {
        pre->next = pre->next->next;
        cur->next = cur->next->next;
        pre = pre->next;
        cur = cur->next;
    }
    pre->next = nullptr; // ��������ԭ����β�ڵ�
    return res;      // ����������ͷ�ڵ�
}
