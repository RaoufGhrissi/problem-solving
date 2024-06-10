#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pp pair<ll,ll>

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& v, vector<int>& freq) {
        vector<ll> ans;
        map<int,ll> val;

        priority_queue<pp> pq;
        int n = v.size();

        for (int i=0 ; i<n ; i++) {
            int x = v[i];
            val[x] += freq[i];
            pq.push({val[x], x});

            while(val[pq.top().second] != pq.top().first)
                pq.pop();

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};