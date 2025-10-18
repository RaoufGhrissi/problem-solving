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

        int cnt0 = 0, cnt1;

        for (char &c:s)
            cnt0 += c == '0';

        cnt1 = n - cnt0;

        int ng = n/2-k;

        if (cnt1 >= ng && cnt0 >= ng) {
            cnt1 -= ng;
            cnt0 -= ng;

            if (cnt1%2 == 0 && cnt0%2 == 0) {
                yes();  
            } else {
                no();
            }
        } else {
            no();
        }

        
    }
}

int main() {
    solve();
    return 0;
}