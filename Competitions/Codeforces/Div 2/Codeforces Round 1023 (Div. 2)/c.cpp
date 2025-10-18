#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
#define eol cout<<endl;
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

void debug(vector<ll> &v) {
    int n = v.size();
    for (int i=0 ; i<n ; i++)
        cout<<v[i]<<" ";

    eol;
}

ll max_subarray(vector<ll> &v) {
    ll prev = 0;
    int n = v.size();
    ll mx = -1e18;

    for (int i=0 ; i<n ; i++) {
        ll val = max(v[i], prev + v[i]);
        mx = max(val, mx);
        prev = val;
    }

    return mx;
}


void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        ll n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        vector<ll> v(n);

        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        int idGap = -1;

        for (int i=0 ; i<n ; i++) {
            if (s[i] == '0') {
                v[i] = -1e18;
                idGap = i;
            }
        }

        ll res = max_subarray(v); 
        if (res > k) {
            no();
        } else if (res == k) {
            yes();
            debug(v);
        } else if (idGap == -1) {
            no();
        } else {
            ll start = -1e18;
            ll end = 1e18;
            while(start<end) {
                ll mid = (start+end+1)/2;
                v[idGap] = mid;
                if (max_subarray(v) > k) {
                    end = mid-1;
                } else {
                    start = mid;
                }
            }

            yes();
            v[idGap] = start;
            debug(v);
        }
    }
}

int main() {
    solve();
    return 0;
}