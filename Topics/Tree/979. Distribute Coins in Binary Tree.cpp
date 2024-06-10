//https://leetcode.com/problems/distribute-coins-in-binary-tree/?envType=daily-question&envId=2024-05-18

#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};

class Solution {
public:
    int dfs(TreeNode* root, int &ans) {
        if (!root) return 0;

        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);

        ans += abs(l) + abs(r);

        return (root->val - 1) + l + r;
    }

    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};