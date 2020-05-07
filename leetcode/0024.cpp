//leetcode 24题 两两交换链表中的节点

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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode guardPair1;
        ListNode guardPair2;
        guardPair1.next = &guardPair2;
        ListNode* trace = &guardPair1;
        ListNode* prev = &guardPair2;
        guardPair2.next = head;
        while(trace && trace->next)
        {
            auto tmp = trace->next->next;
            trace->next->next = trace;
            prev->next = trace->next;
            prev = trace;
            trace->next = tmp;
            trace = trace->next;
        }
        return guardPair1.next;
    }
};