#include <bits/stdc++.h>

using namespace std;

#define inf 1e9

#define inf 1e9

class Solution {
public:
    int dp[50][51][51][2];
    int mod = 1e9 + 7;
    int count(int i, int k, int prev, int eq, int &diff, vector<int> &v) {
        if (!k)
            return eq ? diff : 0;

        if (i==v.size())
            return 0;

        if (dp[i][k][prev][eq] != -1)
            return dp[i][k][prev][eq];

        int &ans = dp[i][k][prev][eq];
        ans = count(i+1, k, prev, eq, diff, v)%mod;
        if (prev == v.size()) {
            ans += count(i+1, k-1, i, eq, diff, v)%mod;
        } else if ((v[i]-v[prev]) >= diff) {
            ans += count(i+1, k-1, i, eq | ((v[i]-v[prev]) == diff), diff, v)%mod;
        }

        ans %= mod;
        return ans;
    }

    int sumOfPowers(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int n = v.size();
        int ans = 0;

        set<int> used;
        for (int i=0 ; i<n ; i++) {
            for (int j=i+1 ; j<n ; j++) {
                memset(dp, -1, sizeof dp);
                int diff = v[j]-v[i];
                if (used.count(diff)) continue;
                ans += count(0, k, n, 0, diff, v)%mod;
                ans %= mod;
                used.insert(diff);
            }
        }
        return ans;
    }
};



int main() {
    vector<int> v = {1, 2, 3, 4};
    int k = 3;
    cout<<Solution().sumOfPowers(v, k);
    return 0;
}