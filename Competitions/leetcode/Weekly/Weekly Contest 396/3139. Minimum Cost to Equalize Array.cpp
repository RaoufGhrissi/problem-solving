#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define ll long long

class Solution {
public:
    ll mod = 1e9 + 7;

    int minCostToEqualizeArray(vector<int>& v, int cost1, int cost2) {
        ll mx = *max_element(v.begin(), v.end());
        ll mi = *min_element(v.begin(), v.end());
        ll n = v.size();

        ll c1 = cost1;
        ll c2 = cost2;

        ll sm = 0;

        for (int &e:v) {
            sm += e;
        }

        ll ans = 1e18;
        for (ll i=mx ; i<=2*mx ; i++) {
            ll cnt;
            ll totDiff = i*n - sm; 
            if (c1*2 <= c2) cnt = totDiff*c1;
            else {
                ll mxDiff = i-mi; // i = 12, mi = 7 , maxDiff = 5
                ll rest = totDiff - mxDiff; // 14 - 5 = 9
                if (mxDiff > rest) {
                    cnt = rest*c2 + (mxDiff - rest)*c1;
                } else {
                    cnt = (totDiff/2ll)*c2;
                    if (totDiff&1ll) cnt += c1;
                }
            }
            ans = min(ans, cnt);
        }

        return ans%mod;
    }
};