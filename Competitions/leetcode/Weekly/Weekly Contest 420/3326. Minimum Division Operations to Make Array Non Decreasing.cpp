#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& v) {
        int n = v.size();

        int ans = 0;

        for (int i=n-2 ; i>=0 ; i--) {
            if (v[i] <= v[i+1]) continue;

            int mx = -1;
            for (int j=2 ; j<=sqrt(v[i]) ; j++) {
                if (v[i]%j == 0) {
                    mx = max({mx, j, v[i]/j});
                }
            }

            if (mx != -1) {
                v[i] /= mx;
                ans++;
            }

            if (v[i] > v[i+1])
                return -1;
        }

        return ans;
    }
};