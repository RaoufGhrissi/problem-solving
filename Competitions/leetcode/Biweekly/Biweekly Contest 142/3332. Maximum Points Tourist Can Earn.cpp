#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int dp[200][200];

    int mx(int city, int day, int &n, int &k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        if (day == k) return 0;

        int &ans = dp[city][day];

        if (ans != -1)
            return ans;

        ans = stayScore[day][city] + mx(city, day+1, n, k, stayScore, travelScore);
        for (int i=0 ; i<n ; i++) {
            if (i == city) continue;
            ans = max(ans, travelScore[city][i] + mx(i, day+1, n, k, stayScore, travelScore));
        }

        return ans;
    }

    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int ans = 0;
        memset(dp, -1, sizeof dp);
        for (int i=0 ; i<n ; i++)
            ans = max(ans, mx(i, 0, n, k, stayScore, travelScore));

        return ans;
    }
};