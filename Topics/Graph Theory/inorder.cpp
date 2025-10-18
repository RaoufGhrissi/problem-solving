#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree {
    public:
        vector<int> ans;

        BinaryTree() {}

        void dfs(TreeNode *root) {
            // inorder: left / root / right
            if (root->left)
                dfs(root->left);
            
            ans.push_back(root->val);
            
            if (root->right)
                dfs(root->right);
        }
};




void solve() {
    TreeNode *n4 = new TreeNode(4), *n7 = new TreeNode(7), *n6 = new TreeNode(6);
    TreeNode *n5 = new TreeNode(5, nullptr, n7);
    TreeNode *n2 = new TreeNode(2, n4, n5);
    TreeNode *n3 = new TreeNode(3, nullptr, n6);
    TreeNode *root = new TreeNode(1, n2, n3);

    BinaryTree bt = BinaryTree();
    bt.dfs(root);
}

int main() {
    solve();

    return 0;
}