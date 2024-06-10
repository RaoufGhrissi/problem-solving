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
    bool hasCycle(ListNode *h) {
        ListNode* slow = h;
        ListNode* fast = h;
        
        while(slow && fast && fast->next)
        {            
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        
        if (!fast || !fast->next)
            return 0;
        
        return 1;
    }
};