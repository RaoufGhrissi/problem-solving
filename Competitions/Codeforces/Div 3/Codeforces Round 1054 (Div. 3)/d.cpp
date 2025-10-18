#include <bits/stdc++.h>
#define ll long long
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

ll cnt(int mid, string &s) {
    char c = s[mid];
    ll cnt = 0;
    ll ans = 0;
    int n = s.size();

    for (int i=mid+1 ; i<n ; i++) {
        if (s[i] == c) {
            ans += cnt;
        } else {
            cnt++;
        }
    }

    cnt = 0;
    for (int i=mid-1 ; i>-1 ; i--) {
        if (s[i] == c) {
            ans += cnt;
        } else {
            cnt++;
        }
    }

    return ans;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        string s;
        cin>>s;

        vector<int> bs, as;

        for (int i=0 ; i<n ; i++) {
            if (s[i] == 'a') as.push_back(i);
            else bs.push_back(i);
        }

        int na = as.size();
        int nb = bs.size();
        
        ll ans = 1e15;
        if (na) {
            ans = min(ans, cnt(as[na/2], s));
            if (na%2 == 0) {
                ans = min(ans, cnt(as[na/2 - 1], s));
            }
        }

        if (nb) {
            ans = min(ans, cnt(bs[nb/2], s));
            if (nb%2 == 0) {
                ans = min(ans, cnt(bs[nb/2 - 1], s));
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}