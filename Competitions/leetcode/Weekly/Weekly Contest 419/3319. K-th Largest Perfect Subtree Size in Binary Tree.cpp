#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)

using namespace std;

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
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    vector<int> sz;

    int rec(TreeNode* root, int level) { // traja3 level idha PB else -1
        if (!root)
            return -1;

        if (isLeaf(root)) {
            sz.push_back(1);
            return level;
        }

        int l = rec(root->left, level+1);
        int r = rec(root->right, level+1);

        if (l != -1 && l==r) {
            int diff = l-level+1;
            sz.push_back((1<<diff) - 1);
            return l;
        } else {
            return -1;
        }  
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        rec(root, 0);
        sort(sz.begin(), sz.end(), greater<int>());
        return k-1 < sz.size() ? sz[k-1] : -1;
    }
};