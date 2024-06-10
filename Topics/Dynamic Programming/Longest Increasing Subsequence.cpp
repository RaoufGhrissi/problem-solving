int dp[2500+1];
class Solution {
public:
    int lis(int n, vector<int>& a)
    {
        if (dp[n] != -1)
            return dp[n];

        // base case
        if (n == 1)
            dp[n] = 1;

        dp[n] = 0;
        for (int i=1; i<n ; i++)
        {
            if (a[n-1]>a[i-1])
                dp[n] = max(lis(i, a) + 1, dp[n]);
        }
        if (dp[n] == 0)
            dp[n] = 1;

        return dp[n];

    }

    int lengthOfLIS(vector<int>& a) {
            memset(dp, -1, sizeof(dp));
            int n = a.size();
            int m = 0;
            for (int i=1 ; i<=n ; i++)
            {
                int res = lis(i, a);
                if (res>m)
                    m = res;
            }
            return m;
    }
};
