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

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> v(n);
        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        // +
        v[0] = abs(v[0]);
        int less = 0;
        vector<int> ids;
        for (int i=1 ; i<n ; i++) {
            if (v[i] < v[0]) ids.push_back(i);
            else if (-v[i] < v[0]) ids.push_back(i);
        }

        int mid = n/2;
        less = ids.size();

        if (less > mid) {
            for (int &id:ids) {
                if (less == mid) break;
                if (v[id] > v[0]) {
                    less--;
                } else if (-v[id] > v[0]) {
                    less--;
                }
            }
        }

        if (less == mid) {
            yes();
            continue;
        }

        // -
        v[0] = -abs(v[0]);

        ids.clear();
        for (int i=1 ; i<n ; i++) {
            if (v[i] < v[0]) ids.push_back(i);
            else if (-v[i] < v[0]) ids.push_back(i);
        }

        less = ids.size();

        if (less > mid) {
            for (int &id:ids) {
                if (less == mid) break;
                if (v[id] > v[0]) {
                    less--;
                } else if (-v[id] > v[0]) {
                    less--;
                }
            }
        }

        if (less == mid) {
            yes();
        } else {
            no();
        }

    }
}

int main() {
    solve();
    return 0;
}