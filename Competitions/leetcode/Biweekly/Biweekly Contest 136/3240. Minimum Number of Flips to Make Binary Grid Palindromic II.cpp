#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<int,int>
#define INF (ll)1e18

using namespace std;

class Solution {
public:
    bool odd(int n) {
        return n&1;
    }

    int minFlips(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans = 0;

        for (int i=0 ; i<n/2 ; i++) {
            for (int j=0 ; j<m/2 ; j++) {
                int ones = v[i][j] + v[n-1-i][j] + v[n-1-i][m-1-j] + v[i][m-1-j];
                ans += min(4-ones, ones);
            }
        }

        int ones = 0;
        int line = n/2;
        int row = m/2;
        int toChange = 0;
        
        if (odd(n)) {
            for (int col=0 ; col<m/2 ; col++) {
                if (v[line][col] == v[line][m-1-col]) {
                    ones += 2*v[line][col];
                    continue;
                }
                toChange++;
            }
        }

        if (odd(m)) {
            for (int l=0 ; l<n/2 ; l++) {
                if (v[l][row] == v[n-1-l][row]) {
                    ones += 2*v[l][row];
                    continue;
                }
                toChange++;
            }
        }
        
        if (odd(n) && odd(m) && v[line][row]) {
            ones++;
        }

        int rest = ones%4;

        if (!rest)
            return ans + toChange;

        if (rest&1) {
            ans++;
            rest--;
        }

        return toChange > 0 ? ans + toChange : ans + rest;
    }
};
