#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    ll dp[13][14][14];
    ll findMax(int i, int minus, int taken, vector<int> &v) {
        if (i==v.size()) {
            if (!taken) return -1e9;
            return (minus&1) ? -1 : 1;
        }            

        if (dp[i][minus][taken] != -1)
            return dp[i][minus][taken];

        int additional = (v[i] < 0) ? 1 : 0;
        return dp[i][minus][taken] = max(abs(v[i])*findMax(i+1, minus + additional, taken+1, v), findMax(i+1, minus, taken, v));
    }

    long long maxStrength(vector<int>& v) {
        memset(dp, -1, sizeof dp);
        return findMax(0, 0, 0, v);
    }
};

int main() {
    vector<int> v = {0, -1};
    cout<<Solution().maxStrength(v);
    return 0;
}