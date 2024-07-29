#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    ll dp[100][101][101];
    ll rec(int i, int prev, int prevPrev, vector<vector<ll>> &cum, int &n) {
        if (i==n)
            return 0;

        ll &ans = dp[i][prev][prevPrev];

        if (ans != -1) {
            return ans;
        }

        ans = 0;

        for (int x=0 ; x<=n ; x++) {
            if (!i) {
                ans = max(ans, rec(i+1, x, prev, cum, n));
            } else {
                if (x == prev) {
                    ans = max(ans, rec(i+1, x, prev, cum, n));
                } else if (x < prev) {
                    int res = cum[prev-1][i];
                    
                    if (x) {
                        res -= cum[x-1][i];
                    }

                    ans = max(ans, res + rec(i+1, x, prev, cum, n));
                } else {
                    int res = 0;
                    int mx = i==1 ? prev : max(prev, prevPrev);
                    if (mx < x) {
                        res += cum[x-1][i-1];
                        if (mx)
                            res -= cum[mx-1][i-1];
                    }

                    ans = max(ans, res + rec(i+1, x, prev, cum, n));
                }
            }
        }

        return ans;
    }

    long long maximumScore(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<ll>> cum(n, vector<ll>(n));

        for (int j=0 ; j<n ; j++) {
            for (int i=0 ; i<n ; i++) {
                cum[i][j] = v[i][j];
                if (i)
                    cum[i][j] += cum[i-1][j];
            }
        }

        memset(dp, -1, sizeof dp);
        return rec(0, 0, 0, cum, n);
    }
};

int main() {
    vector<vector<int>> v = {{0,0,0,0,0},{0,0,3,0,0},{0,1,0,0,0},{5,0,0,3,0},{0,0,0,0,2}};
    cout<<Solution().maximumScore(v);
}