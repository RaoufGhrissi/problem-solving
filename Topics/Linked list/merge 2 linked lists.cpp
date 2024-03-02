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
    ListNode* mergeTwoLists(ListNode* i, ListNode* j) {
        ListNode* fake = new ListNode();
        ListNode* curr = fake;

        while(i != nullptr && j != nullptr) {
            if (i->val <= j->val) {
                curr->next = i;
                curr = curr->next;
                i = i->next;
            } else {
                curr->next = j;
                curr = curr->next;
                j = j->next;
            }
        }

        if (i == nullptr) {
            curr->next = j;
        }

        if (j == nullptr) {
            curr->next = i;
        }

        return fake->next;
    }
};

int main() {
    ListNode* n4 = new ListNode(4);
    ListNode* n2 = new ListNode(2, n4);
    ListNode* n1 = new ListNode(1, n2);

    ListNode* v4 = new ListNode(4);
    ListNode* v2 = new ListNode(3, v4);
    ListNode* v1 = new ListNode(1, v2);

    auto res = Solution().mergeTwoLists(n1, v1);

    return 0;
}
