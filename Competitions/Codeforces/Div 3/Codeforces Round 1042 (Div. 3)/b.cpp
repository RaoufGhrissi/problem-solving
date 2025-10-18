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

                if (n&1) {
                    for (int i=0 ; i<n ; i+=2) {
                        cout<<-1<<" ";
                        if (i+1<n)
                            cout<<3<<" ";
                    }
                } else {
                    for (int i=0 ; i<n ; i+=2) {
                        cout<<-1<<" ";
                        if (i+1==n-1)
                            cout<<2<<" ";
                        else
                            cout<<3<<" ";
                    }
                }

                cout<<endl;
                
            }
        }

        int main() {
            solve();
            return 0;
        }