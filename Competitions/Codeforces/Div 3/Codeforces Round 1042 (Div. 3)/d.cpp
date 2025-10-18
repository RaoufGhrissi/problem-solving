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

            vector<int> in(n, 0);
            vector<int> graph[n];

            for (int i=0 ; i<n-1 ; i++) {
                int a, b;
                cin>>a>>b;

                a--;
                b--;

                in[a]++;
                in[b]++;

                graph[a].push_back(b);
                graph[b].push_back(a);            
            }

            if (n==2) {
                cout<<0<<endl;
                continue;
            }

            int tot = 0;

            for (int i=0 ; i<n ; i++) {
                tot += in[i] == 1;
            }

            int ans = 0;

            for (int i=0 ; i<n ; i++) {
                int cnt = 0;
                for (int &child:graph[i]) {
                    cnt += in[child] == 1;
                }

                ans = max(ans, cnt);
            }

            cout<<tot-ans<<endl;
        }
    };

    int main() {
        solve();
        return 0;
    }