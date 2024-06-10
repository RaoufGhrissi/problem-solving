#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Raouf ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

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
    int s(TreeNode* root, int &low, int &high) {
        int x = root->val;

        int sm =  (x >= low && x <= high) ? x : 0;
        if (root->left && x >= low) {
            sm += s(root->left, low, high);
        }

        if (root->right && x <= high)
            sm += s(root->right, low, high);

        return sm;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return s(root, low, high);
    }
};