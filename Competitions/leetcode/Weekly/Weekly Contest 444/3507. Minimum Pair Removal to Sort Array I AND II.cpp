#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll, vector<int>>

using namespace std;



class Solution {
public:
    ll get_value(int l, int r, vector<ll> &cum) {
        ll ans = cum[r];
        if (l)
            ans -= cum[l-1];

        return ans;
    }

    int minimumPairRemoval(vector<int>& v) {
        int n = v.size();

        vector<ll> cum(n);

        for (int i=0 ; i<n ; i++) {
            cum[i] = v[i];
            if (i)
                cum[i] += cum[i-1];
        }

        vector<int> next(n), prev(n);
        priority_queue<pp, vector<pp>, greater<pp>> pq;

        int desc = 0;
        for (int i=1 ; i<n ; i++) 
            desc += v[i] < v[i-1];

        for (int i=0 ; i<n ; i++) {
            next[i] = i;
            prev[i] = i;
            
            if (i < n-1)
                pq.push({v[i]+v[i+1], {i, i, i+1}}); 
        }

        int ops = 0;
        vector<int> ids;
        int ls, le, rs, re;

        while(desc > 0 && !pq.empty()) {
            pp t = pq.top();
            pq.pop();

            ll sm = t.first;
            ids = t.second; 

            ls = ids[0];
            le = ids[1];
            rs = le+1;
            re = ids[2];

            if (next[ls] != le)
                continue;

            if (next[rs] != re)
                continue;

            ops++;
            next[ls] = re;
            prev[le] = -1;

            next[rs] = -1;
            prev[re] = ls;

            if (get_value(ls, le, cum) > get_value(rs, re, cum))
                desc--;
            
            if (ls > 0) {
                int pe = ls-1;
                int ps = prev[pe];

                if (get_value(ps, pe, cum) > get_value(ls, le, cum))
                    desc--;
                
                if (get_value(ps, pe, cum) > get_value(ls, re, cum))
                    desc++;
                
                pq.push({get_value(ps, re, cum), {ps, pe, re}});
            }

            if (re+1<n) {
                int ns = re+1;
                int ne = next[ns];

                if (get_value(ns, ne, cum) < get_value(rs, re, cum))
                    desc--;
                
                if (get_value(ns, ne, cum) < get_value(ls, re, cum))
                    desc++;
                
                pq.push({get_value(ls, ne, cum), {ls, re, ne}});
            }
        }

        return ops;
    }
};



int main() {
    vector<int> v = {2,2,-1,3,-2,2,1,1,1,0,-1}; // {-2,1,2,-1,-1,-2,-2,-1,-1,1,1}; //{5, 2, 3, 1};
    cout<<Solution().minimumPairRemoval(v);

    return 0;
}