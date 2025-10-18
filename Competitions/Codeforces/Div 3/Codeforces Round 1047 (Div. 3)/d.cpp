#include <bits/stdc++.h>
#define ll long long
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
        int n;
        cin>>n;

        vector<int> v(n), ans(n);
        map<int,vector<int>> occ;

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            occ[v[i]].push_back(i);
        }
        
        int nb = 1;
        bool ok = 1;
        for (auto &a:occ) {
            if (a.second.size()%a.first > 0) {
                ok = 0;
                break;
            }

            int cap = 0;
            for (int &id:a.second) {
                ans[id] = nb;
                cap++;
                if (cap == a.first) {
                    cap = 0;
                    nb++;
                }
            }
        }

        if (!ok) {
            cout<<-1<<endl;
        } else {
            for (int i=0 ; i<n ; i++)
                cout<<ans[i]<<" ";

            cout<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}