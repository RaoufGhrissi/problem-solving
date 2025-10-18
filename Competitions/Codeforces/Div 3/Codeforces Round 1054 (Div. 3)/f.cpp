#include <bits/stdc++.h>

using namespace std;

#define ll long long

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

ll cnt(int n) {
    return n*1ll*(n+1)/2;
}

bool check(int &x, int &d, int &h) {
    int y = x-d;
    int groups = y+1;
    int _size = d/groups;
    int rest = d%groups;
    int full = groups - rest;

    return - cnt(_size) * full - cnt(_size+1) * rest + h + y > 0;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int h, d;
        cin>>h>>d;

        int i=d;
        int j=2*d;

        while (i<j) {
            int mid = i + (j - i) / 2;

            if (check(mid, d, h)) {
                j = mid;
            } else {
                i = mid+1;
            }
        }

        cout<<i<<endl;
    }
}

int main() {
    solve();
    return 0;
}