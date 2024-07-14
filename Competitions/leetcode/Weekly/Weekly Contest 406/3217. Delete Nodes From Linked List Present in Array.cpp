#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> exist;
        for (auto &a:nums)
            exist.insert(a);

        ListNode* ans = new ListNode(-1, head);
        ListNode* prev = ans;

        while(head) {
            if (!exist.count(head->val)) {
                prev->next = head;
                prev = head;
            }
            head = head->next;
        }

        prev->next = nullptr;

        return ans->next;
    }
};