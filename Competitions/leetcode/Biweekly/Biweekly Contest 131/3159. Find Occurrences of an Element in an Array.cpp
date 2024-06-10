#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& v, vector<int>& q, int x) {
        vector<int> pos;
        int n = v.size();
        for (int i=0 ; i<n ; i++) {
            if (v[i] == x) {
                pos.push_back(i);
            }
        }
        
        vector<int> ans;
        for (auto &qq:q) {
            int p = qq-1;
            if (p>=pos.size())
                ans.push_back(-1);
            else
                ans.push_back(pos[p]);
        }
        
        return ans;
    }
};