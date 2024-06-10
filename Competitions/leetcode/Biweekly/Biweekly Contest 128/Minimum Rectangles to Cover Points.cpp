#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pp pair<ll, ll>

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& p, int w) {
        int x1 = p[0][0];
        int x2 = p[0][0];

        set<int> xx; // container elements eli fih unique (mayet3awdouch, mrateb) sorted

        for (auto &a:p)
            xx.insert(a[0]);

        int ans = 0;
        int end = -1;
        for (auto &x:xx) {
            if (x <= end) continue;
            ans++;
            end = x+w;
        }

        return ans;
    }
};