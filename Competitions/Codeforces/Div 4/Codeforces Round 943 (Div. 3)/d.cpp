#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        string p, s;
        cin>>p>>s;

        int n = p.size();
        int m = s.size();

        vector<pair<char,int>> vp, vs;

        int cnt = 1;
        for (int i=1 ; i<n ; i++) {
            if (p[i] == p[i-1]) {
                cnt++;
            } else {
                vp.push_back({p[i], cnt});
                cnt = 1;
            }
        }

        vp.push_back({p[n-1], cnt});

        
        cnt = 1;
        for (int i=1 ; i<m ; i++) {
            if (s[i] == s[i-1]) {
                cnt++;
            } else {
                vs.push_back({s[i], cnt});
                cnt = 1;
            }
        }

        vs.push_back({s[m-1], cnt});

        n = vp.size();
        m = vs.size();

        if (n != m) {
            cout<<"NO"<<endl;
            continue;
        }
        

        bool ok = 1;

        for (int i=0 ; i<n ; i++) {
            if (vp[i].first != vs[i].first) {
                ok = 0;
                break;
            }

            if (vp[i].second > vs[i].second) {
                ok = 0;
                break;
            }

            if (vs[i].second > 2*vp[i].second) {
                ok = 0;
                break;
            }
        }


        if (ok) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        
        
    }
}

int main() {
    solve();
    return 0;
}