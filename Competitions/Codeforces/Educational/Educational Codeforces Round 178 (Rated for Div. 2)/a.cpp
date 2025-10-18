#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int a, b, c;
        cin>>a>>b>>c;

        int diff = b-a;
        // make a and b equal
        if (c-diff >= b) {
            a = b;
            c -= diff;

            int rest = c-b;

            if (rest % 3 == 0)
                cout<<"YES";
            else
                cout<<"NO";
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