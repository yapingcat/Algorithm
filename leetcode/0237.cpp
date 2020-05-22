////leetcode 237. 删除链表中的节点
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
    void deleteNode(ListNode* node) {
        
        if(!node) 
            return;
        auto pre = node;
        while(node->next)
        {
            node->val = node->next->val;
            pre = node;
            node = node->next;
        }
        pre->next = nullptr;
        delete node;
        node = nullptr;
    }
};

