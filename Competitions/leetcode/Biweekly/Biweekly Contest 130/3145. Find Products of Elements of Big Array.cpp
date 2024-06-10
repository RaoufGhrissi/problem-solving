#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    ll count(ll i, vector<ll> &cnt, bool compute, ll mod) {
        if (!i) return 0;

        if (i == 1) {
            if (compute) cnt[0]++;
            return 1;
        }

        int l = log2l(i);

        ll ones = 1ll<<(l-1); // 2 power of (l-1)
        
        if (compute) {
            for (int i=0 ; i<l ; i++) {
                cnt[i] += ones;
            }
        }

        ll prev = 1ll<<l;
        ll next = i-prev;
        
        if (compute)
            cnt[l] += next+1;

        return l*1ll*ones + next + 1 + count(next, cnt, compute, mod);
    }

    ll FastPower (ll a, ll b, ll M) {
        ll ans = 1;
        while (b) {
            if (b&1) ans = (ans * a) % M;
            a = (a * a) % M;
            b /= 2;
        }
        return ans % M;
    }

    vector<int> findProductsOfElements(vector<vector<long long>>& q) {
        vector<int> ans;
        for (auto &qq:q) {
            ll s = qq[0];
            ll e = qq[1];
            ll mod = qq[2];

            //find start position
            ll i=0;
            ll j=1e15;
            ll nb;

            vector<ll> cum(55, 0);
            while(i<j) {
                ll mid = (i+j+1)/2;
                nb = count(mid, cum, 0, mod);

                if (nb > s) { // example 7 > 6
                    j = mid-1;
                } else { // example 5 < 6 
                    i = mid;
                }
            }
            
            nb = count(i, cum, 1, mod);

            ll next = i+1;

            for (int x=0 ; x<55 ; x++) {
                if (nb == s) break;
                ll mask = 1ll<<x;

                if (mask&next) {
                    nb++;
                    cum[x]++;
                }
            }

            //find end position
            i=0;
            j=1e15;

            e++;
            vector<ll> cum1(55, 0);
            while(i<j) {
                ll mid = (i+j+1)/2;

                if (count(mid, cum1, 0, mod) > e) {
                    j = mid-1;
                } else {
                    i = mid;
                }
            }

            nb = count(i, cum1, 1, mod);
            next = i+1;

            for (int x=0 ; x<55 ; x++) {
                if (nb == e) break;
                ll mask = 1ll<<x;

                if (mask&next) {
                    nb++;
                    cum1[x]++;
                }
            }

            ll res = 0;
            for (int x=0 ; x<55 ; x++) {
                res += x*(cum1[x]-cum[x]);
            }

            int y = FastPower(2, res, mod);
            ans.push_back(y);
        }

        return ans;
    }
};