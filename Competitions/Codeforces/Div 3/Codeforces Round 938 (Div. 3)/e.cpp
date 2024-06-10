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
        string s;

        cin>>n>>s;
       
        for (int k=n ; k>0 ; k--) {
            bool ok = 1;
            queue<int> q;
            for (int i=0 ; i<n ; i++) {
                while (!q.empty() && q.front() < i) {
                    q.pop();
                }

                char c = s[i];
                if (q.size()&1) c = c == '0' ? '1' : '0';

                if (c == '1') continue;

                if (i+k-1 >= n) {
                    ok = 0;
                    break;
                }

                q.push(i+k-1);
            }

            if (ok) {
                cout<<k<<endl;
                break;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}