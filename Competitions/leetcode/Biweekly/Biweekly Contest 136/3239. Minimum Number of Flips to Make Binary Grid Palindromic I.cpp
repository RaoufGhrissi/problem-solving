#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<int,int>
#define INF (ll)1e18

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans = 0, res;

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m/2 ; j++) {
                ans += v[i][j] != v[i][m-1-j];
            }
        }

        res = ans;
        ans = 0;
        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<n/2 ; j++) {
                ans += v[j][i] != v[n-1-j][i];
            }
        }

        return min(ans, res);
    }
};
