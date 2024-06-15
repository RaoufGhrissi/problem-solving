#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int maxTotalReward(vector<int>& v) {
        sort(v.begin(), v.end());

        int n = v.size();
        int ans = 0;

        vector<int> dp(n);
        dp[0] = v[0];

        for (int i=1 ; i<n ; i++) {
            dp[i] = v[i];

            for (int j=0 ; j<i ; j++) {
                if (dp[j] < v[i])
                    dp[i] = max(dp[i], v[i]+dp[j]);
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

int main() {
    vector<int> v = {1,6,4,3,2};
    cout<<Solution().maxTotalReward(v);
    return 0;
}