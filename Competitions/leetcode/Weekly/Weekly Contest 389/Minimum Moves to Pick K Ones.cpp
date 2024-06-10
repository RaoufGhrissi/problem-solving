#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pp pair<ll,ll>
#define inf 1e18

class Solution {
public:
    ll check(int &mid, vector<vector<ll>> &l, vector<vector<ll>> &r, int &i, int &j) {
        ll res = l[i][0], cnt = l[i][1], index = l[i][2];
        ll dist = l[mid][2] - index; 
        ll left = l[mid][0] - res - cnt*dist;

        res = r[j][0], cnt = r[j][1], index = r[j][2];
        dist = index - r[mid][2];
        ll right = r[mid][0] - res - cnt*dist;

        return right + left;
    }

    long long minimumMoves(vector<int>& v, int k, int mx) {
        int n = v.size();

        ll ans = inf;
        for (int i=0 ; i<n ; i++) {
            ll res = 0;
            int kk = k;
            int m = mx;
            kk -= v[i];
            if (kk && i && v[i-1]) kk--, res++;
            if (kk && i+1 < n && v[i+1]) kk--, res++;

            int needed = min(kk, m);
            kk -= needed;
            res += 2*needed;

            if (!kk)
                ans = min(ans, res);
        }

        if (ans < inf)
            return ans;

        vector<vector<ll>> l, r;

        for (int i=0 ; i<n ; i++) {
            if (v[i]) {
                ll cnt = l.size();
                ll res = 0;
                if (cnt) {
                    ll d = i-l[cnt-1][2];
                    res = l[cnt-1][0] + d * (l[cnt-1][1]+1);
                }

                l.push_back({res, cnt, i});
            }
        }

        for (int i=n-1 ; i>-1 ; i--) {
            if (v[i]) {
                ll cnt = r.size();
                ll res = 0;
                if (cnt) {
                    ll d = r[cnt-1][2]-i;
                    res = r[cnt-1][0] + d * (r[cnt-1][1]+1);
                }

                r.push_back({res, cnt, i});
            }
        }

        reverse(r.begin(), r.end());

        k -= mx;
        int i = 0;
        int j = k-1;

        while (j<l.size()) {
            int mid = (i+j)/2;
            ans = min(ans, check(mid, l, r, i, j));

            if (!(k&1)) {
                mid++;
                ans = min(ans, check(mid, l, r, i, j));
            }

            i++;
            j++;
        }

        return ans + 2*mx;
    }
};