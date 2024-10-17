#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)

using namespace std;

class Solution {
public:
    /*
        F = 0
        E = 1
        W = 2
    */

    unordered_map<char, vector<int>> mp = {
        {
            'F', {0, -1, 1}
        }, {//     0  1  2
            'W', {-1, 1, 0},
        }, {
            'E', {1, 0, -1},
        }
    };

    // score in [-1000, +1000] => transaltion [0, 2000]

    int dp[1000][3][2001];
    int m = 1e9 + 7;

    int rec(int i, int prev, int score, string &s) {
        if (i==s.size()) {
            return score > 1000;
        }
        
        int &ans = dp[i][prev][score];

        if (ans != -1)
            return ans;

        ans = 0;
        for (int id=0 ; id<3 ; id++) { // chnowa najem nhot
            if (!i || id != prev) // idha ena fil pos = 0 mayhmch l prev sinon lezem nthabet fih
                ans += rec(i+1, id, score + mp[s[i]][id], s)%m;
            ans %= m;
        }

        return ans;
    }

    int countWinningSequences(string s) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, 1000, s);
    }
};