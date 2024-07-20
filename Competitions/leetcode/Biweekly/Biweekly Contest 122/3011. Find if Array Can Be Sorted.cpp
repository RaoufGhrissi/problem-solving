#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    bool canSortArray(vector<int>& v) {
        int n = v.size();
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(v[0]);

        for (int i=1 ; i<n ; i++) {
            if(__builtin_popcount(v[i]) == __builtin_popcount(v[i-1])) {
                pq.push(v[i]);
            } else {
                while(!pq.empty()) {
                    res.push_back(pq.top());
                    pq.pop();
                }
                pq.push(v[i]);
            }
        }

        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        for (int i=0 ; i<n ; i++)
            cout<<res[i]<<" ";

        sort(v.begin(), v.end());
        for (int i=0 ; i<n ; i++)
            if (v[i] != res[i]) return 0;

        return 1;
    }
};