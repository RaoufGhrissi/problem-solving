#include <bits/stdc++.h>

using namespace std;
// kahn

class Solution {
public:
    int maximumLength(vector<int>& v, int k) { // k = 2 for the first version of the problem
        int n = v.size();
        int ans = 2;
        vector<int> dp(k, 0);
        
        for (int ref=0 ; ref<k ; ref++) {
            for (int i=0 ; i<k ; i++)
                dp[i] = 0;
            
            for (int i=0 ; i<n ; i++) {
                int rest = v[i]%k;
                
                if (rest > ref)
                    continue;
                
                dp[rest] = max(dp[rest], 1 + dp[ref-rest]);
                ans = max(ans, dp[rest]);
            }
        }
        
        return ans;
    }
};

int main() {
    vector<int> v = {8, 2, 8};
    cout<<Solution().maximumLength(v, 5);
}