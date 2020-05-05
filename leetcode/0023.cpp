/////leetcode 23题 合并K个排序链表

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;

        ListNode*  result = nullptr;
        ListNode*  pre = nullptr;
        std::vector<ListNode*> heap(lists.begin(),lists.end());
        for(auto it = heap.begin();it != heap.end();)
        {
            if(*it == nullptr)
                it = heap.erase(it);
            else
                it++;
        }
        std::make_heap(heap.begin(),heap.end(),[](decltype(heap)::value_type l1, decltype(heap)::value_type l2){ return (l1->val) >= (l2->val);});
        while(!heap.empty())
        {
            ListNode* p = new ListNode(heap.front()->val);
            if(!result) 
            {
                result = p;
                pre = p;
            }
            else 
            {
                pre->next = p;
                pre = p;
            }
            if(heap.front()->next == nullptr)
            {
                std::pop_heap(heap.begin(), heap.end(),[](const ListNode* l1, const ListNode* l2){ return l1->val >= l2->val;});
                heap.pop_back();
            }
            else
            {
                std::pop_heap(heap.begin(), heap.end(),[](const ListNode* l1, const ListNode* l2){ return l1->val >= l2->val;});
                heap.back() = heap.back()->next;
                std::push_heap(heap.begin(), heap.end(),[](const ListNode* l1, const ListNode* l2){ return l1->val >= l2->val;});
            }
        }
        
        return result;
    }
};