#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;


class Solution {
public:
    vector<pp> graph[100000];
    ll dp[100000][2];
    int k;

    static bool compare(pp &p1, pp &p2) {
        return p1.first - p1.second < p2.first - p2.second;
    }

    ll rec(int i, int parentRemoved, int p = -1) {
        ll &ans = dp[i][parentRemoved];

        if (ans != -1)
            return ans;

        ans = 0;
        int del = max(0, (int)graph[i].size() - k - parentRemoved); // fama tafsikha saret, bech mayfasakhch b zeyed
        vector<pp> v;

        for (auto &[child, w]:graph[i]) {
            if (child == p) continue;

            ll take = rec(child, 0, i) + w;
            ll dont = rec(child, 1, i);
            v.push_back({take, dont});
        }

        sort(v.begin(), v.end(), compare);

        for (int x=0 ; x<v.size() ; x++) {
            if (x<del) ans += v[x].second;
            else ans += max(v[x].first, v[x].second);
        }

        return ans;
    }

    ll maximizeSumOfWeights(vector<vector<int>>& e, int p) {
        int n = e.size()+1;
        k = p;

        for (auto &ee:e) {
            graph[ee[0]].push_back({ee[1], ee[2]});
            graph[ee[1]].push_back({ee[0], ee[2]});
        }

        memset(dp, -1, sizeof dp);

        return rec(0, 0);
    }
};