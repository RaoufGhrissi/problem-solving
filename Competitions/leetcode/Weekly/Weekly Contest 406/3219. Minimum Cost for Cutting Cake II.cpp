#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        vector<vector<int>> t;

        for (auto &a:h)
            t.push_back({a, 1}); // 1 = hori

        for (auto &a:v)
            t.push_back({a, 0}); // 0 = vertical

        int hh = 1, vv = 1;
        ll ans = 0;

        sort(t.begin(), t.end(), greater<vector<int>>());
        for (int i=0 ; i<t.size() ; i++) {
            if(t[i][1]) {
                ans += vv*t[i][0];
                hh++;
            } else {
                ans += hh*t[i][0];
                vv++;
            }
        }

        return ans;
    }
};