// link: https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/submissions/1151556036/
// tags: recursion, bitmask, bs
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Raouf ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

class Solution {
    public:
        ll compute(ll mid, ll &x) {
            if (!mid) return 0;
            if (mid == 1) return x == 1;
            if (mid == 2) {
                if (x==1) return 2;
                if (x==2) return 1;
            }

            ll l = log2l(mid);
            ll before = (1ll<<l)-1;
            ll multiples = 0;
            ll cx = x;

            while(cx <= l) {
                multiples++;
                cx += x;
            }

            ll calcul = multiples*(1ll<<(l-1));
            ll ones = mid-before;
            if (!((l+1)%x)) {
                calcul += ones;
            }
            
            calcul += compute(ones-1, x);
            return calcul;
        }

        ll solve(ll k, ll x) {
            ll i = 1;
            ll j = 1e15;
            
            while(i<j) {
                ll mid = (i+j+1)/2;

                ll calcul = compute(mid, x);

                if (calcul > k) {
                    j = mid - 1;
                } else {
                    i = mid;
                }
            }

            return i;           
        }

        long long findMaximumNumber(long long k, int x) {
            return solve(k, x);
        }
    
};