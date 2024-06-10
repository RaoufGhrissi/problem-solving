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
class Solution {
public:  
    void inOrder(TreeNode* r, vector<int> &v)
    {
        if (!r)
            return;
        
        inOrder(r->left, v);
        v.push_back(r->val);
        inOrder(r->right, v);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inOrder(root, v);
        int i=0;
        int j=v.size()-1;
        while(i<j)
        {
            if (v[i]+v[j]==k)
                return 1;
            else if (v[i]+v[j]<k)
                i++;
            else
                j--;
        }
        
        return 0;
    }
};