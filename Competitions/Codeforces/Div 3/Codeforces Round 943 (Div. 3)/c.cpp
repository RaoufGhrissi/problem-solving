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

        vector<int> v(n-1);
        vector<int> ans;

        for (int i=0 ; i<n-1 ; i++)
            cin>>v[i];

        bool found = 0;
        for (int start=1 ; start<100000 ; start++) {
            if (found) break;
            ans.clear();
            ans.push_back(start);
            found = 1;
            for (int i=0 ; i<n-1 ; i++) {
                int m = ans.size();
                int c = v[i] + ans[m-1];

                if ((c%ans[m-1]) != v[i]) {
                    found = 0;
                    break;
                }

                ans.push_back(c);
            }
        }

        for (auto &c:ans)
            cout<<c<<" ";

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}