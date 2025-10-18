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
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        vector<int> occ(10, 0);
        for (char &c:s)
            occ[c-'0']++;

        string ans = "";
        for (int i=1 ; i<=10 ; i++) {
            int mi = 10-i;

            for (int x=mi ; x<10 ; x++) {
                if (occ[x] > 0) {
                    ans += x+'0';
                    occ[x]--;
                    break;
                }
            }
        }

        cout<<ans<<endl;

        

    }
}

int main() {
    solve();
    return 0;
}