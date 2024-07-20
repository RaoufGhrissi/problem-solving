#include <bits/stdc++.h>

using namespace std;

#define ll long long    


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    string p1 = "", p2 = "";
    void getPath(TreeNode* root, int &s, int &d, string &ans) {
        if (root->val == s) {
            p1 = ans;
        } else if (root->val == d) {
            p2 = ans;
        }

        unordered_map<TreeNode*, char> next = {{root->left, 'L'}, {root->right, 'R'}};
        for (auto &child:next) {
            if (child.first) {
                ans += child.second;
                getPath(child.first, s, d, ans);
                ans.pop_back();
            }
        }
    }

    string getDirections(TreeNode* root, int s, int d) {
        string ans = "";
        getPath(root, s, d, ans);

        int n = p1.size(), m = p2.size();

        int i = 0;
        for (i=0 ; i<min(n, m) ; i++) {
            if (p1[i] != p2[i])
                break;
        }

        ans = "";
        int j = i;
        while(j<n) {
            ans += 'U';
            j++;
        }

        ans += p2.substr(i);
        return ans;
    }
};