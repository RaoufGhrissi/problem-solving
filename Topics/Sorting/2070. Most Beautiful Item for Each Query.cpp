#include<bits/stdc++.h>
#define pp pair<long double, long double>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& v, vector<int>& q) {
        vector<vector<int>> qq;

        int n = q.size();
        for (int i=0 ; i<n ; i++) {
            qq.push_back({q[i], i});
        }   

        sort(qq.begin(), qq.end());
        sort(v.begin(), v.end());

        vector<int> ans(n, 0);
        int j = 0;
        int mx=0;

        for (auto &x:qq) {
            while(j<v.size() && v[j][0] <= x[0]) {
                mx = max(mx, v[j][1]);
                j++;
            }

            ans[x[1]] = mx;
        }

        return ans; 
    }
};