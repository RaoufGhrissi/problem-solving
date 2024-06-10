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
        int n, m;
        cin>>n>>m;
        string a, b;
        cin>>a>>b;

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        cout<<i<<endl;
    }
}

int main() {
    solve();
    return 0;
}