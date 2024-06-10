//https://leetcode.com/problems/largest-divisible-subset/submissions/1170886975/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int index = 0;
        int n = v.size();

        sort(v.begin(), v.end());
        vector<int> dp(n, 1); // dp[i] = maximum subset length ending by i
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<i ; j++) {
                if (v[i] % v[j]) continue;

                dp[i] = max(dp[i], dp[j]+1);
                if(dp[i] > dp[index])
                    index = i;
            }
        }

        //backtrack to result
        vector<int> ans = {};
        int target = dp[index];
        for (int i=index ; i>-1 ; i--) {
            if (dp[i] == target && !(v[index] % v[i])) {
                ans.push_back(v[i]);
                index = i;
                target--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;        
    }
};

int main() {
    vector<int> x = {1, 2, 3};
    vector<int> a = Solution().largestDivisibleSubset(x);
    return 0;
}