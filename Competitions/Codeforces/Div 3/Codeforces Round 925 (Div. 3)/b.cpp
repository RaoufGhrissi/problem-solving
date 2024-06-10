#include <bits/stdc++.h>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> v(n);
        int sm = 0;
        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            sm += v[i];
        }

        int amount = sm/n;
        bool yes = 1;
        for (int i=0 ; i<n-1 ; i++) {
            if (v[i] < amount) {
                yes = 0;
                break;
            }

            v[i+1] += v[i]-amount;
            v[i] = amount;
        }

        if (yes) {
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