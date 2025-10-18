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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        bool pal = 1;
        for (int i=0 ; i<n/2 ; i++) {
            if (s[i] < s[n-1-i]) {
                cout<<"YES"<<endl;
                pal = 0;
                break;
            }

            if (s[i] > s[n-1-i]) {
                pal = 0;
                if (k>0) {
                    cout<<"YES"<<endl;
                } else {
                    cout<<"NO"<<endl;
                }

                break;
            }
        }

        if (pal) {
            for (int i=1 ; i<n ; i++) {
                if (k>0 && (s[i] < s[i-1])) {
                    pal = 0;
                    break;
                }
            }
            if (!pal) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}