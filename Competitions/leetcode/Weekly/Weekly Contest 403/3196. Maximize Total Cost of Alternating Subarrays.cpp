#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define ll long long
class Solution {
public:
    ll dp[100000];
    ll rec(int i, vector<int>& v) {
        if (i>=v.size())
            return 0;

        ll &ans = dp[i];

        if (ans != -1)
            return ans;

        return ans = max(v[i] + rec(i+1, v), v[i]-(i+1 < v.size() ? v[i+1] : 0) + rec(i+2, v));
    }

    long long maximumTotalCost(vector<int>& v) {
        memset(dp, -1, sizeof dp);
        return rec(0, v);
    }
};