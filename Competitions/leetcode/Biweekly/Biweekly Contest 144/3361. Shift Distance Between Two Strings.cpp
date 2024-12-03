#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

#define ll long long

class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nx, vector<int>& p) {
        ll ans = 0;

        int n = s.size();

        vector<ll> nextCost(nx.begin(), nx.end());
        vector<ll> previousCost(p.begin(), p.end());

        for (int i=1 ; i<26 ; i++) 
            nextCost[i] += nextCost[i-1];

        for (int i=24 ; i>-1 ; i--)
            previousCost[i] += previousCost[i+1];

        for (int i=0 ; i<n ; i++) {
            ll src = s[i]-'a';
            ll dest = t[i]-'a';

            if (src == dest) continue;

            ll res = 1e18;

            // right
            if (dest > src) {
                ll sm = nextCost[dest-1];
                if (src)
                    sm -= nextCost[src-1];

                res = min(res, sm);
            } else {
                ll sm = nextCost[25];
                if (src)
                    sm -= nextCost[src-1];

                if (dest)
                    sm += nextCost[dest-1];
                    
                res = min(res, sm);
            }

            // left
            if (dest < src) {
                ll sm = previousCost[dest+1];
                if (src<25)
                    sm -= previousCost[src+1];

                res = min(res, sm);
            } else {
                ll sm = previousCost[0];
                if (dest<25) 
                    sm += previousCost[dest+1];
                if (src<25)
                    sm -= previousCost[src+1];

                res = min(res, sm);
            }

            ans += res;
        }

        return ans;
    }
};