#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[100000];

    int longestIdealString(string s, int k) {
        vector<vector<int>> pos(26);

        int n = s.size();
        for (int i=0 ; i<n ; i++) {
            pos[s[i]-'a'].push_back(i);
        }

        int ans = 0;

        for (int i=n-1 ; i>-1 ; i--) {
            dp[i] = 1;
            for (char c='a' ; c<='z' ; c++) {
                if (abs(c-s[i]) > k)
                    continue;
                
                int index = lower_bound(pos[c-'a'].begin(), pos[c-'a'].end(), i+1) - pos[c-'a'].begin();
                if (index == pos[c-'a'].size()) continue;
                dp[i] = max(dp[i], 1 + dp[index]);
                ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};

int main() {
    cout<<Solution().longestIdealString("acfgbd", 2);
    return 0;
}