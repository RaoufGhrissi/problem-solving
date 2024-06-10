#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long

using namespace std;


void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m, k;
        cin>>n;

        vector<ll> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
        }

        bool can = 1;
        for (int i=0 ; i<n-2 ; i++) {
            int needed = v[i];
            if (needed < 0) {
                can = 0;
                break;
            }
            
            v[i] = 0;
            v[i+1] -= 2*needed;
            v[i+2] -= needed;
        }

        can &= v[n-2] == 0 && v[n-1] == 0;

        if (can) {
            cout<<"YES";
        } else {
            cout<<"NO";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}