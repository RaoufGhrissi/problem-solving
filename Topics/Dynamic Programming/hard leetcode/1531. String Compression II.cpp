#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Raouf ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

class Solution {
public:
    int dp[100][101][27][101];

    int getLength(int tot) {
        return tot > 1 ? to_string(tot).size() + 1 : 1;
    }

    int findMinLength(int i, int k, int prev, int cnt, string &s) {
        if (i==s.size())
            return getLength(cnt);

        if (dp[i][k][prev][cnt] != -1) {
            return dp[i][k][prev][cnt];
        }

        int &ans = dp[i][k][prev][cnt];
        ans = 1e9;
        
        if (k) {
            ans = min(ans, findMinLength(i+1, k-1, prev, cnt, s));
        }

        int ord = s[i]-'a';
        if (prev < 26 && ord != prev) {
            ans = min(ans, getLength(cnt) + findMinLength(i+1, k, ord, 1, s));
        } else {
            ans = min(ans, findMinLength(i+1, k, ord, cnt+1, s));
        }
        
        return ans;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof dp);
        return findMinLength(0, k, 26, 0, s);
    }
};

int main() {
    Solution* obj = new Solution();
    cout<<"res = "<<obj->getLengthOfOptimalCompression("aaabcccd", 2)<<endl;

    return 0;
}