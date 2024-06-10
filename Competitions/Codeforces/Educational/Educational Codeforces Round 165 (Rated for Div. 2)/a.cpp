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
        int n;
        cin>>n;
        vector<int> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            v[i]--;
        }

        bool find = 0;
        for (int i=0 ; i<n ; i++) {
            int p = v[i];
            if (v[p] == i) {
                find = 1;
                break;
            }
        }

        if (find) cout<<"2";
        else cout<<"3";

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}