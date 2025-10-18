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

        string s;
        cin>>s;

        vector<int> alice, bob;

        for (int i=0 ; i<n ; i++) {
            if (s[i] == 'A') {
                alice.push_back(i+1);
            } else
                bob.push_back(i+1);
        }

        if (alice.empty()) {
            cout<<"Bob";
        } else if (bob.empty()) {
            cout<<"Alice";
        } else {
            bool aliceWin = 0;
            for (int &a:alice) {
                bool win = 1;
                for (auto &b:bob) {
                    if (a==1) {
                        if (b<n) win = 0;
                    } else if (a == n) {
                        if (b == 1) win = 0;
                    } else {
                        if (b>a) win = 0;
                    }
                }

                if (win) {
                    aliceWin = 1;
                }
            }

            if (aliceWin) {
                cout<<"Alice";
            } else {
                cout<<"Bob";
            }
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}