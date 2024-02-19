#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string s) {
        map<char, int> occ;

        for (auto &c:s)
            occ[c]++;

        int ans = 0;

        vector<int> v;
        for (auto &a:occ) {
            v.push_back(a.second);
        }

        int pos = 0;
        sort(v.begin(), v.end(), greater<int>());

        int n = v.size();
        for (int i=0 ; i<n ; i++) {
            if (i < 8) {
                ans += v[i];
            } else if (i < 16) {
                ans += 2*v[i];
            } else if (i < 24) {
                ans += 3*v[i];
            } else 
                ans += 4*v[i];
        }

        return ans;
    }
};