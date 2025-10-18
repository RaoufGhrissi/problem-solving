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

            set<int> st;
            for (int i=0 ; i<n ; i++) {
                int x;
                cin>>x;
                st.insert(x);
            }

            int m = st.size();

            cout<<(m-1)*2 + 1<<endl;
        }
    }

    int main() {
        solve();
        return 0;
    }