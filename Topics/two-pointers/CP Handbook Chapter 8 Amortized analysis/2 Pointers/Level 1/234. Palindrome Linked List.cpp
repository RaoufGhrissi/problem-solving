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
    ListNode* rev(ListNode* h, ListNode* prev)
    {
        ListNode* p = h->next;
        h->next = prev;
        
        if (p)
            return rev(p, h);
        
        return h;
    }
    
    bool isPalindrome(ListNode* h) {
        ListNode* slow = h;
        ListNode* fast = h;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* h1 = rev(slow, nullptr);

        while(h && h1)
        {
            if (h1->val != h->val)
                return 0;
            
            h1=h1->next;
            h=h->next;
        }
        
        return 1;
    }
};