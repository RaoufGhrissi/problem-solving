//problem link: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    ll dp[100][100][2];
    int m = 1e9 + 7;
    ll rec(int n, int k, int s) {
        if (!n)
            return !k;

        ll &ans = dp[n][k][s];
        if (ans != -1)
            return dp[n][k][s];

        ans = k ?  + rec(n-1, k-1, 0)%m : 0;

        if (s) {// not started
            ans += rec(n-1, k, 1)%m;
        } else { // already started
            ans += (rec(n-1, k, 0)%m + rec(n-1, k, 1)%m)%m;
        }
        
        ans %= m;
        return ans;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof dp);
        return rec(n-1, k, 1);       
    }
};

int main() {
    cout<<Solution().numberOfSets(3, 1);
    return 0;
}