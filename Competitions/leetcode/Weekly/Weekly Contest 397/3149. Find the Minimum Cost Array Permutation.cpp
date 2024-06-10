#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[14][14][16384];
    vector<int> res;

    int rec(int prev, int first, int mask, vector<int>& v, int &n) {
        if (mask==((1<<n)-1))
            return abs(prev-v[first]);

        int &ans = dp[prev][first][mask];

        if (ans != -1)
            return ans;

        ans = 1e9;
        for (int j=0 ; j<n ; j++) {
            int msk = 1<<j;
            if (mask & msk) continue;

            if (!mask)
                ans = min(ans, rec(j, j, mask|msk, v, n));
            else
                ans = min(ans, abs(prev-v[j]) + rec(j, first, mask|msk, v, n));
        }

        return ans;
    }

    void display(int prev, int first, int mask, vector<int>& v, int &n) {
        if (mask==((1<<n)-1)) {
            return;
        }

        int ans = dp[prev][first][mask];
        for (int j=0 ; j<n ; j++) {
            int msk = 1<<j;
            if (mask & msk) continue;

            if (!mask) {
                if (ans == rec(j, j, mask|msk, v, n)) {
                    res.push_back(j);
                    display(j, j, mask|msk, v, n);
                    break;
                }
            }
            else {
                if (ans == (abs(prev-v[j]) + rec(j, first, mask|msk, v, n))) {
                    res.push_back(j);
                    display(j, first, mask|msk, v, n);
                    break;
                }
            }
        }
    }

    vector<int> findPermutation(vector<int>& v) {
        memset(dp, -1, sizeof dp);
        int n = v.size();
        cout<<rec(0, 0, 0, v, n);
        display(0, 0, 0, v, n);
        return res;
    }
};