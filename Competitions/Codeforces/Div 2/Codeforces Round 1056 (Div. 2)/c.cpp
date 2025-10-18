#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

bool compute(int prev, vector<int> &a) {
    int n = a.size();
    vector<int> v(n);
    v[0] = prev;
    for (int i=1 ; i<n ; i++) {
        int diff = a[i] - a[i-1];
        if (abs(diff) > 1) return 0;
        if (diff == 0) {
            if (v[i-1] == 0) {
                v[i] = 1;
            } else {
                v[i] = 0;
            }
        } else if (diff == 1) {
            if (v[i-1] == 1)
                return 0;
            
            v[i] = 0;
        } else if (diff == -1) {
            if (v[i-1] == 0)
                return 0;
            
            v[i] = 1;
        }
    }

    int x = 0;
    for (int i=0 ; i<n ; i++) {
        x += v[i];
    }

    int y = 0;
    for (int i=0 ; i<n ; i++) {
        x -= v[i];
        if ((x+y+1) != a[i])
            return 0;

        y += v[i] == 0;
    }

    return 1;
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

        vector<int> a(n);

        for (int i=0 ; i<n ; i++)
            cin>>a[i];

        cout<<compute(0, a) + compute(1, a)<<endl;

    }
}

int main() {
    solve();
    return 0;
}