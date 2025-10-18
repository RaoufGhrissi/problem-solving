    #include <bits/stdc++.h>
    #define ll long long
    #define pp pair<ll,ll>

    using namespace std;

    void no() {
        cout<<"NO"<<endl;
    }

    void yes() {
        cout<<"YES"<<endl;
    }


    ll calc(int i, int z, vector<ll> &a, vector<ll> &b) {
        return a[i] + b[z-i];
    }

    void solve() {
    #ifndef ONLINE_JUDGE
        freopen("a.txt", "r", stdin);
    #endif
        int t;
        cin>>t;

        while(t--) {
            int n, m, q;
            cin>>n>>m>>q;

            vector<ll> a(n), b(m);

            for (int i=0 ; i<n ; i++) {
                cin>>a[i];
            }

            for (int i=0 ; i<m ; i++) {
                cin>>b[i];
            }

            sort(a.begin(), a.end(), greater<int>());
            sort(b.begin(), b.end(), greater<int>());

            vector<ll> pa(n+1, 0), pb(m+1, 0);

            for (int i=0 ; i<n ; i++) {
                pa[i+1] = a[i] + pa[i];
            }

            for (int i=0 ; i<m ; i++) {
                pb[i+1] = b[i] + pb[i]; 
            }

            while(q--) {
                int x, y, z;
                cin>>x>>y>>z;

                int i = max(0, z-y);
                int j = min(z, x);

                while (i+2<j) {
                    int m1 = (i + i + j)/3;
                    int m2 = (j + i + j)/3;

                    ll v1 = calc(m1, z, pa, pb);
                    ll v2 = calc(m2, z, pa, pb);

                    if (v1 <= v2) {
                        i = m1;
                    } else {    
                        j = m2;
                    }   
                }

                ll ans = 0;

                for (int x=i ; x<=j ; x++)
                    ans = max(ans, calc(x, z, pa, pb));

                cout<<ans<<endl;
            }
        }
    }

    int main() {
        solve();
        return 0;
    }