/////leetcode 第19题 删除链表的倒数第N个节点

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            auto p1 = head;
            auto p2 = head;
            auto p3 = head;
            while(--n > 0) {
                if(!p1)
                    break;
                p1 = p1->next;
            }
            while(p1 && p1->next) 
            {
                p1 = p1->next;
                p3 = p2;
                p2 = p2->next;
            }
            p3->next = p2->next ;
            if(p2 == head) head = head->next;
            delete p2;
            return head;
    }
};