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

bool check(vector<int> &v) {
    return v[0] >= v[1]/2 && v[0] >= v[2]/2 &&
        v[1] >= v[0]/2 && v[1] >= v[2]/2 &&
        v[2] >= v[0]/2 && v[2] >= v[1]/2;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int x;
        cin>>x;

        int ops = 1;
        vector<int> v = {1, 0, 0};

        while(!(v[0] == v[1] && v[1] == v[2] && v[2] == x)) {
            sort(v.begin(), v.end());

            int s = 0;
            int e = x;

            int old = v[0];

            while(s<e) {
                int mid = (s+e+1)/2;
                v[0] += mid;
                if (check(v)) {
                    s = mid;
                } else {
                    e = mid-1;
                }

                v[0] = old;
            }

            v[0] = min(x, v[0] + s);
            ops++;
        }

        cout<<ops<<endl;
    }
}

int main() {
    solve();
    return 0;
}