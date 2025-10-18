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

            vector<ll> v(n);

            for (int i=0 ; i<n ; i++)
                cin>>v[i];

            bool zl = !v[0] && !v[1];
            bool zr = 0;

            for (int i=2 ; i<n ; i++) {
                zr &= !v[i];
            }

            int cnt = 0;
            if (!zl && !zr) {
                cout<<1<<endl;
                cout<<1<<" "<<n<<endl;
            } else if (!zl) {
                cout<<2<<endl;
                cout<<1<<" "<<2<<endl;
                cout<<1<<" "<<n-1<<endl;
            } else if (zr) {
                cout<<2<<endl;
                cout<<3<<" "<<n<<endl;
                cout<<1<<" "<<3<<endl;
            } else {
                cout<<3<<endl;
                cout<<1<<" "<<2<<endl;
                cout<<2<<" "<<n-1<<endl;
                cout<<1<<" "<<2<<endl;
            }
        }
    }

    int main() {
        solve();
        return 0;
    }