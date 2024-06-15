//https://leetcode.com/problems/maximum-elegance-of-a-k-length-subsequence/description/

#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
#define inf 1e18

using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& v, int k) {
        sort(v.begin(), v.end());

        int n = v.size();
        vector<bool> used(n+1, 0);
        int cat = 0;
        ll val = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i=n-1 ; i>=n-k ; i--) {
            val += v[i][0];
            if (!used[v[i][1]]) {
                cat++;
                used[v[i][1]] = 1;
            } else
                pq.push(v[i][0]);
        }

        ll valAns = val;
        int catAns = cat;

        for (int i=n-1 ; i>-1 ; i--) {
            if (used[v[i][1]]) continue;
            
            if (!pq.empty()) {
                ll oldMx = val + cat*1ll*cat;

                val -= pq.top();
                val += v[i][0];
                cat++;

                ll newMx = val + cat*1ll*cat;

                if (newMx > oldMx) {
                    valAns = val;
                    catAns = cat;
                }

                pq.pop();
                used[v[i][1]] = 1;
            }
        }

        return valAns + catAns*1ll*catAns;
    }
};