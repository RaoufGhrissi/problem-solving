#include <bits/stdc++.h>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int n;
    cin>>n;

    while(n--) {
        int a,b,c,d;

        cin>>a>>b>>c>>d;

        int mi = min(a, b);
        int mx = max(a, b);

        if (c>mi && c<mx && d>mi && d<mx) {
            cout<<"NO";
        } else if ((c<mi || c>mx) && (d<mi || d>mx)) {
            cout<<"NO";
        } else 
            cout<<"YES";

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}