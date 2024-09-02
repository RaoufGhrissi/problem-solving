#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define ll long long

class Solution {
public:
    long long minDamage(int p, vector<int>& d, vector<int>& h) {
        vector<pair<double, int>> v;
        int n = d.size();

        for (int i=0 ; i<n ; i++) {
            double t = h[i]%p ? h[i]/p + 1 : h[i]/p;
            v.push_back({d[i] / t, i});
        }

        sort(v.begin(), v.end(), greater());

        ll ans = 0;
        int s = 0;

        for (int i=0 ; i<n ; i++) {
            int id = v[i].second;

            int needed = h[id] % p ? h[id]/p + 1 : h[id]/p;
            s += needed;

            ans += s*d[id];
        }


        return ans;
    }
};