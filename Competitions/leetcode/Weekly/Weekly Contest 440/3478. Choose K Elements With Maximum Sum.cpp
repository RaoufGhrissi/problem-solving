#define ll long long
#include <bits/stdc++.h>
#define inf 2*1e9
using namespace std;


class Solution {
public:
    vector<ll> findMaxSum(vector<int>& v1, vector<int>& v2, int k) {
        map<int, vector<int>> ids;
        int n = v1.size();

        for (int i=0 ; i<n ; i++) {
            ids[v1[i]].push_back(i);
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        ll sm = 0;
        vector<ll> ans(n, 0);

        for (auto &a:ids) {
            for (int &id:a.second)
                ans[id] = sm;
            
            for (int &id:a.second) {
                int val = v2[id];
                if (pq.size() < k) {
                    pq.push(val);
                    sm += val;
                } else if (pq.top() < val) {
                    sm -= pq.top();
                    pq.pop();
                    pq.push(val);
                    sm += val;
                }
            }
        }

        return ans;
    }
};