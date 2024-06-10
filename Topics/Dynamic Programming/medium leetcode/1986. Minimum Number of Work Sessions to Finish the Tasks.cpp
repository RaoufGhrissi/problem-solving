#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[1<<14][16];

    int solve(int mask, int size, vector<int>& v, int &n, int &t) {
        if (mask == ((1<<n)-1))
            return 1;

        if (dp[mask][size] != -1)
            return dp[mask][size];

        int &ans = dp[mask][size];
        ans = 1e9;
        for (int i=0 ; i<n ; i++) {
            int msk = 1<<i;
            if (mask&msk)
                continue;

            ans = min(ans, 1 + solve(msk|mask, t-v[i], v, n, t)); // add to the next session

            if (v[i] <= size)
                ans = min(ans, solve(msk|mask, size-v[i], v, n, t)); // add to the current session
        }

        return ans;
    }

    int minSessions(vector<int>& v, int t) {
        int n = v.size();
        memset(dp, -1, sizeof dp);
        return solve(0, t, v, n, t);
    }
};

int main() {
    vector<int> v = {1,2,3,4,5};
    cout<<Solution().minSessions(v, 15);

    return 0;
}