///leetcode 第2题 两数相加

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1 && !l2)
            return nullptr;
        ListNode* head = new ListNode();
        ListNode* iter = head;
        int sum = 0;
        int carry = 0;
        while(l1 || l2)
        {
            int lv1 = 0,lv2 = 0;
            if(l1)
                lv1 = l1->val;
            if(l2)
                lv2 = l2->val;
            sum = lv1 + lv2 + carry;
            ListNode* p = new ListNode();
            p->val = sum % 10;
            carry = sum / 10;
            iter->next = p;
            iter = p;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry)
        {
            iter->next = new ListNode();
            iter->next->val = carry;
        }
        ListNode* ret = head->next;
        delete head;
        return ret;
    }
};
























