#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& v, vector<int>& q) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        sort(v.begin(), v.end());
        int n = q.size();
        int j = 0;
        int m = v.size();

        vector<vector<int>> qs;
        for (int i=0 ; i<n ; i++) {
            qs.push_back({q[i], i});
        }
        
        sort(qs.begin(), qs.end());
        vector<int> ans(n, -1);

        for (int i=0 ; i<n ; i++) {
            while(j<m && v[j][0] <= qs[i][0]) {
                pq.push({v[j][1]-v[j][0]+1, v[j][1]});
                j++;
            }

            while(!pq.empty() && pq.top()[1] < qs[i][0])
                pq.pop();

            if (!pq.empty())
                ans[qs[i][1]] = pq.top()[0];
        }

        return ans;
    }
};