#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll, ll>

using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n, m;
        cin>>n>>m;

        set<int> pos;

        string s;
        cin>>s;

        for (int i=0 ; i<m ; i++) {
            int in;
            cin>>in;

            pos.insert(in);
        }

        int x = 1;

        for (int i=0 ; i<n ; i++) {
            if (s[i] == 'A') {
                x++;
                pos.insert(x);
            } else {
                x++;
                while(pos.count(x)) {
                    x++;    
                }
                pos.insert(x);
                while(pos.count(x)) {
                    x++;
                }
            }
        }

        cout<<pos.size()<<endl;


        for (auto &p:pos)
            cout<<p<<" ";

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}