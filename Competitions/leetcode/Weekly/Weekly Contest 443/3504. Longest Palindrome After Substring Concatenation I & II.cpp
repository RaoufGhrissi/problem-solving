#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    int dp[1000][1000][2];
    vector<int> ls, lt;
    int n, m;
    string s, t;

    int rec(int i, int j, int started) {
        if (i == n) {
            return j>-1 ? lt[j] : 0;
        }

        if (j == -1) {
            return ls[i];
        }

        int &ans = dp[i][j][started];
        if (ans != -1)
            return ans;

        ans = max(ls[i], lt[j]);
        if (s[i] == t[j]) {
            if (started)
                ans = max(ans, 2 + rec(i+1, j-1, 1));
            else
                ans = max({ans, 2 + rec(i+1, j-1, 1), rec(i+1, j, 0), rec(i, j-1, 0)});
        } else if (!started) {
            ans = max({ans, rec(i+1, j, 0), rec(i, j-1, 0)});
        }

        return ans;
    }

    int longestPalindrome(string _s, string _t) {
        s = _s;
        t = _t;

        n = s.size();
        m = t.size();

        ls.resize(n);
        lt.resize(m);

        for (int i=0 ; i<n ; i++) ls[i] = 1;
        for (int i=0 ; i<m ; i++) lt[i] = 1;

        for (int i=0 ; i<n ; i++) {
            // even
            int a=i;
            int b=i+1;

            while(a>-1 && b<n && s[a] == s[b]) {
                ls[a] = max(ls[a], b-a+1);
                a--;
                b++;
            }

            // odd
            a = i-1;
            b = i+1;

            while(a>-1 && b<n && s[a] == s[b]) {
                ls[a] = max(ls[a], b-a+1);
                a--;
                b++;
            }
        }

        for (int i=0 ; i<m ; i++) {
            // even
            int a=i;
            int b=i+1;

            while(a>-1 && b<m && t[a] == t[b]) {
                lt[b] = max(lt[b], b-a+1);
                a--;
                b++;
            }

            // odd
            a = i-1;
            b = i+1;

            while(a>-1 && b<m && t[a] == t[b]) {
                lt[b] = max(lt[b], b-a+1);
                a--;
                b++;
            }
        }

        memset(dp, -1, sizeof dp);
        return rec(0, m-1, 0);
    }
};