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
        int n, k;
        cin>>n>>k;

        int x = n*n - k;

        if (x==1) {
            no();
            continue;
        }

        yes();

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (x == 0) {
                    cout<<"R";
                    continue;
                }

                if (j==n-1) {
                    cout<<"L";
                } else if (x==1) {
                    if (j==0)
                        cout<<"U";
                    else
                        cout<<"L";
                } else {
                    cout<<"R";
                }

                x--;
            }

            cout<<endl;
        }

    }
}

int main() {
    solve();
    return 0;
}