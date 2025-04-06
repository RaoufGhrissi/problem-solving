#include <bits/stdc++.h>

#define pp pair<int,int>
#define ll long long
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int decomp(int n) {
        set<int> st;
        int d=2;
        while(n>1) {
            if (n%d == 0) st.insert(d);
            while(n%d == 0) {
                n /= d;
            }
            d++;
        }

        return st.size();
    }

    ll FastPower (ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b&1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return ans % mod;
    }

    ll k;
    int n;

    int maximumScore(vector<int>& v, int _k) {
        n = v.size();
        k = _k;

        vector<pp> a(n);
        vector<pp> t(n);
        for (int i=0 ; i<n ; i++) {
            a[i] = {decomp(v[i]), i};
            t[i] = {-v[i], i};
        }

        sort(t.begin(), t.end());

        stack<int> st;
        vector<int> right(n, n);
        vector<int> left(n, -1);

        for (int i=0 ; i<n ; i++) {
            while(!st.empty() && a[st.top()].first < a[i].first) {
                right[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for (int i=n-1 ; i>-1 ; i--) {
            while(!st.empty() && a[st.top()].first <= a[i].first) {
                left[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        ll ans = 1;

        for (int i=0 ; i<n ; i++) {
            int val = -t[i].first;
            int index = t[i].second;

            ll l = index-1-left[index];
            ll r = right[index]-1-index;
    
            ll cnt = l+r+1+l*r;
            cnt %= mod;

            ans = (ans * FastPower(val, min(k, cnt))) % mod;
            k = max(0*1ll, k-cnt);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = {8,3,9,3,8};
    cout<<s.maximumScore(v, 2);
    return 0;
}