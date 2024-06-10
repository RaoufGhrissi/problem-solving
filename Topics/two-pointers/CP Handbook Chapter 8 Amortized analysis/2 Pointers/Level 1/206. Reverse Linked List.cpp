/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* current, ListNode* parent)
    {
        ListNode* old_next = current->next;
        current->next = parent;
        if (old_next)
            return rev(old_next, current);
        
        return current;
    }
    
    ListNode* reverseList(ListNode* h) {
        if (!h)
            return h;
        return rev(h, nullptr);
    }
};