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
    TreeNode* build(int i, int j, vector<int> &v) {
        if (i>j)
            return nullptr;
        
        int mid = (i+j)/2;

        TreeNode* root = new TreeNode(v[mid]);
        root->left = build(i, mid-1, v);
        root->right = build(mid+1, j, v);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& v) {
        int i = 0;
        int j = v.size() - 1;

        return build(i, j, v);
    }
};