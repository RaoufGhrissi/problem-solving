#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

vector<int> v = {0, 1, 0, 3, 2, 0, 2, 5};

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    map<int,int> copy;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);

        for (int i=0 ; i<n ; i++) {
            cin>>a[i];
        }

        multiset<int> st(v.begin(), v.end());

        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            if (st.count(a[i])) {
                st.erase(st.lower_bound(a[i]));
            }

            if (st.empty()) {
                ans = i+1;
                break;
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}