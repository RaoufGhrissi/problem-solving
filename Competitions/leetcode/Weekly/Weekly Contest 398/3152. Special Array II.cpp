#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size();

        vector<int> trans(n-1, 0);

        for (int i=0 ; i<n-1 ; i++) {
            trans[i] = ((v[i]&1) && (v[i+1]&1)) || (!(v[i]&1) && !(v[i+1]&1));
            if (i)
                trans[i] += trans[i-1];
        }

        vector<bool> ans;

        for (auto &qq:q) {
            int s = qq[0];
            int e = qq[1];

            if (s==e) {
                ans.push_back(1);
                continue;
            }

            e--;
            
            int cnt = trans[e];
            if (s) cnt -= trans[s-1];

            ans.push_back(!cnt);
        }

        return ans;
    }
};