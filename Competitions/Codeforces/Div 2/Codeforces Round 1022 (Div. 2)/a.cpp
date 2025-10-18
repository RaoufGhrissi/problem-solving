#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

// bool vis[501];
// set<int> st;

// void backtrack(int &tot, int &l) {
//     if (l == n) {
//         st.insert(tot);
//         return;
//     }

//     for (int i=1 ; i<=n ; i++) {
//         if (vis[i]) continue;
//         vis[i] = 1;
//         l++;
//         tot += abs(i-l);

//         backtrack(tot, l);

//         vis[i] = 0;
//         tot -= abs(i-l);
//         l--;
//     }
// }

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    ll ans[501];
    ans[1] = 1;
    for (int i=2 ; i<501 ; i++) {
        ans[i] = ans[i-1] + i/2;
    }
    
    while(t--) {
        int n;
        cin>>n;

        cout<<ans[n]<<endl;     

        // set<int> copy;
        // for (int i=1 ; i<20 ; i++) {
        //     int tot = 0;
        //     int l = 0;
        //     n = i;
        //     st = copy;
        //     backtrack(tot, l);
        //     cout<<i<<" :";
        //     for (auto &s:st)
        //         cout<<s<<" ";

        //     cout<<endl;
        // }
        // cout<<st.size()<<endl;
    }
}

int main() {
    solve();
    return 0;
}