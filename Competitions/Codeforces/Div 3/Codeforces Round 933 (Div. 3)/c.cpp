#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long

using namespace std;


void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m, k;
        cin>>n;

        string s; cin>>s;

        int ans = 0;

        for (int i=0 ; i<n-2 ; i++) {
            if (s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p') {
                ans++;
                s[i+2] = 'x';
            }
        }
        
        for (int i=0 ; i<n-2 ; i++) {
            if (s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e') {
                ans++;
                s[i+2] = 'x';
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}