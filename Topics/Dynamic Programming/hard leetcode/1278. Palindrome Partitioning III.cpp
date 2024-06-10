#include <bits/stdc++.h>
#define inf (int)1e9;
using namespace std;

class Solution {
public:
    int dp[100][100][101];
    int rec(int i, int prev, int k, string &s) {
        if (i==s.size()-1 || !k) {
            if (k > 0) return 1e9;
            int cnt = 0;

            int n = s.size()-1-prev+1;
            for (int id=0 ; id<n/2 ; id++)
                if (s[prev+id] != s[s.size()-1-id])
                    cnt++;
            
            return cnt;
        }

        int &ans = dp[i][prev][k];

        if (ans != -1)
            return ans;

        ans = rec(i+1, prev, k, s);
        int needed = 0;

        int n = i-prev+1;
        for (int id=0 ; id<n/2 ; id++)
            if (s[prev+id] != s[i-id])
                needed++;

        return ans = min(ans, needed + rec(i+1, i+1, k-1, s));
    }

    int palindromePartition(string s, int k) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, k-1, s);
    }
};