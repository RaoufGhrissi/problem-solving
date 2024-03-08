/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    void build(TreeNode* root, vector<int> &v) {
        if (root->left)
            build(root->left, v);

        v.push_back(root->val);

        if (root->right)
            build(root->right, v);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        build(root, v);

        TreeNode* fake = new TreeNode(-1);
        TreeNode* curr = fake;
        for (auto &a:v) {
            curr->right = new TreeNode(a);
            curr = curr->right;
        }
    
        return fake->right;
    }
};