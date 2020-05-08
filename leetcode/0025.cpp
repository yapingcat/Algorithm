////leetcode 25题 K个一组翻转链表

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 0 || k == 1)
            return head;
        
        ListNode Guard;
        Guard.next = head;
        ListNode* preTail = &Guard;
        ListNode* thisHead = head;
        ListNode* thisTail = head;
        ListNode* pre = thisHead;
        auto n = k;
        for(;;)
        {
            if(thisTail == nullptr)
            {
                break;
            }
            if(--n > 0)
            {
                thisTail = thisTail->next;
                continue;
            }
            ListNode* p = thisHead->next;
            while(pre != thisTail)
            {
                auto tmp = p->next;
                p->next = pre;
                pre = p;
                p = tmp;
            }
            preTail->next = thisTail;
            thisHead->next = p;
            preTail = thisHead;
            thisTail = p;
            thisHead = p;
            pre = thisHead;
            n = k;
        }
        return Guard.next;

    }
};