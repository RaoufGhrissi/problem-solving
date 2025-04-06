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
        ll n, x, k;
        cin>>n>>x>>k;

        string s;
        cin>>s;

        int i = 0;
        bool reached = 0;
        for (int i=0 ; i<n ; i++) {
            if (s[i] == 'L') x--;
            else x++;

            k--;

            if (x == 0) {
                reached = 1;
                break;
            }
        }

        if (!reached)
            cout<<0<<endl;
        else {
            //find cycle length
            ll l = -1;
            for (int i=0 ; i<n ; i++) {
                if (s[i] == 'L') x--;
                else x++;

                if (x == 0) {
                    l = i+1;
                    break;
                }
            }

            if (l == -1) {
                cout<<1<<endl;
                continue;
            }
            
            cout<<1 + k/l<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}