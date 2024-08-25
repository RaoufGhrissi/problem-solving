#define ll long long

#define pp pair<int,int>

using namespace std;

class Solution {
public:
    map<pp, ll> dp;

    ll rec(int i, int prev, vector<vector<int>>& v) {
        if (i==v.size())
            return 0;

        if (dp.count({i, prev}))
            return dp[{i, prev}];

        ll &ans = dp[{i, prev}];
        ans = 0;

        for (int x=0 ; x<v[0].size() ; x++) {
            ans = max(ans, v[i][x] - (prev == -1 ? 0 : abs(prev-x)) + rec(i+1, x, v));
        }

        return ans;
    }

    long long maxPoints(vector<vector<int>>& v) {
        return rec(0, -1, v);
    }
};