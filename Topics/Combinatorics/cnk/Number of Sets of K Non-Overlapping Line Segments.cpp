//https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int m = 1e9 + 7;

class Cnk {
    public:
        ll dp[1001][1001];

        Cnk() {
            memset(dp, -1, sizeof dp);
        }

        ll compute(int n, int k) {
            if (!k)
                return 1;

            if (!n)
                return 0;

            if (dp[n][k] != -1)
                return dp[n][k];

            return dp[n][k] = (compute(n-1, k)%m + compute(n-1, k-1)%m)%m;
        }
};

class Solution {
public:
    int numberOfSets(int n, int k) {
        Cnk cnk = Cnk();
        return cnk.compute(n+k-1, 2*k);
    }
};