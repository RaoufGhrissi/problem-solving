//https://leetcode.com/problems/binary-tree-cameras/

#include <bits/stdc++.h>

#define ll long long

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
    int ans = 0;
    TreeNode* realRoot;
    // 1: hasCamera
    // 2: isCovered
    // 0: no camera and not covered

    int getState(TreeNode* root) {
        if (!root->left && !root->right)
            return 0;

        bool shouldInstallCamera = 0;
        bool isCovered = 0;
        for (auto &child:{root->right, root->left}) {
            if (!child) continue;

            int state = getState(child);
            if (!state) {
                shouldInstallCamera = 1;
            } else if (state == 1) {
                isCovered = 1;
            }
        }

        if (shouldInstallCamera) {
            ans++;
            return 1;
        } else if (isCovered) {
            return 2;
        } else {
            if (root == realRoot)
                ans++;
            return 0;
        }
    }

    int minCameraCover(TreeNode* root) {
        realRoot = root;
        getState(root);
        return max(1, ans);
    }
};

int main() {
    TreeNode* rr = new TreeNode();    
    TreeNode* l = new TreeNode();
    TreeNode* r = new TreeNode(0, nullptr, rr);

    TreeNode* root = new TreeNode(0, l, r);

    Solution().minCameraCover(root);

    return 0;
}