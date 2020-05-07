////leetcode 第21题 合并两个有序链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode guard;
        ListNode* p = &guard;

        for(;;)
        {
            if(l1 == nullptr || l2 == nullptr)
            {
                p->next = l1 == nullptr ? l2 : l1;
                break;
            }
            
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        return guard.next;
    }
};