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
    TreeNode* s(TreeNode* root, int &val) {
        int x = root->val;
        if (x == val)
            return root;
            
        if (root->left && val < x) {
            TreeNode* l = s(root->left, val);
            if (l)
                return l;
        }

        if (root->right && val > x) {
            TreeNode* r = s(root->right, val);
            if (r)
                return r;
        }
        return nullptr;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return s(root, val);
    }
};