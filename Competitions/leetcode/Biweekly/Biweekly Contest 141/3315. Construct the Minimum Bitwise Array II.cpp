#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 2 => -1
    vector<int> minBitwiseArray(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n);

        for (int i=0 ; i<n ; i++) {
            if (v[i] == 2) ans[i] = -1;
            else {
                int id = 0;
                for (int j=0 ; j<31 ; j++) {
                    int mask = 1<<j;
                    if (!(mask&v[i])) break;
                    id = j;
                }

                ans[i] = v[i]^(1<<id);
            }
        }

        return ans;
    }
};