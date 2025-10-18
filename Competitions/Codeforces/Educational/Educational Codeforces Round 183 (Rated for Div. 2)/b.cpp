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
        int n, k;
        cin>>n>>k;

        string s;
        cin>>s;

        if (n==k) {
            for (int i=0 ; i<n ; i++)
                cout<<"-";
        } else {
            string res = "";
            for (int i=0 ; i<n ; i++)
                res += "+";

            int back = 0, front = 0, unk = 0;
            for (char &c:s) {
                back += c=='1';
                front += c=='0';
                unk += c=='2';
            }

            for (int i=0 ; i<front ; i++) {
                res[i] = '-';
            }

            int i = front;
            int x = unk;
            while(x>0 && i<n) {
                res[i] = '?';
                i++;
                x--;
            }

            i=n-1;
            int b = back;
            while(b>0) {
                res[i] = '-';
                b--;
                i--;
            }
            x = unk;
            while(x>0 && i>-1) {
                res[i] = '?';
                i--;
                x--;
            }

            cout<<res;
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}