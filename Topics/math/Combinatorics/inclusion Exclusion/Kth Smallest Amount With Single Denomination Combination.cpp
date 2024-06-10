#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll lcm(ll a, ll b) {
    return (a*b)/__gcd(a, b);
}

class InclusionExclusion {
    public:
        int n;
        vector<int> sets;

    InclusionExclusion(vector<int> &v) {
        n = v.size();
        sets = v;
    }

    ll build(ll value) {
        ll ans = 0;
        for (int i=1 ; i<(1<<n) ; i++) {
            vector<int> st;
            for (int j=0 ; j<n ; j++) {
                int mask = 1<<j;
                if (mask & i) {
                    st.push_back(sets[j]);
                }
            }

            int sz = st.size();
            ll val = st[0];
            for (int x=1 ; x<sz ; x++) val = lcm(val, st[x]);

            if (sz&1) ans += value/val;
            else ans -= value/val;
        }

        return ans;
    }
};

class Solution {
public:
    ll findKthSmallest(vector<int>& v, int k) {
        ll i = 0;
        ll j = 1e11;

        InclusionExclusion ie = InclusionExclusion(v);        
        while(i<j) {
            ll mid = (i+j)/2;
            ll res = ie.build(mid);

            if (res < k) {
                i = mid+1;
            } else {
                j = mid;
            }
        }

        return i;
    }
};


int main() {
    vector<int> v = {3, 6, 9};
    cout<<Solution().findKthSmallest(v, 3);
    return 0;
}