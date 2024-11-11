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
    vector<int> eulerTour;
    map<int,int> first, last, level;

    void dfs(TreeNode* root, int l) {
        eulerTour.push_back(root->val);
        first[root->val] = eulerTour.size()-1;
        level[root->val] = l;

        for (auto &child:{root->left, root->right}) {
            if (child) {
                dfs(child, l+1);
            }
        }

        eulerTour.push_back(root->val);
        last[root->val] = eulerTour.size()-1;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;

        dfs(root, 0);
        int n = eulerTour.size();

        for (int i=0 ; i<n ; i++) {
            eulerTour[i] = level[eulerTour[i]];
        }

        vector<int> mxTill(n, 0), mxTo(n, 0);
        // najem nesta3mel segment tree
        for (int i=0 ; i<n ; i++) {
            mxTill[i] = eulerTour[i];
            if (i)
                mxTill[i] = max(mxTill[i], mxTill[i-1]);
        }

        for (int i=n-1 ; i>-1 ; i--) {
            mxTo[i] = eulerTour[i];
            if (i<n-1)
                mxTo[i] = max(mxTo[i], mxTo[i+1]);
        }
        
        for (int &i:queries) {
            int l = first[i];
            int r = last[i];

            int res = 0;
            if (l>0) res = mxTill[l-1];
            if (r<n-1) res = max(res, mxTo[r+1]);

            ans.push_back(res);
        }

        return ans;
    }
};