#include <bits/stdc++.h>
#define  ll long long
#define pp pair<int,int>
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
        int n, q;
        cin>>n>>q;

        vector<int> ones(n);
        vector<int> succOnes(n, 0);
        vector<int> succZeros(n, 0);

        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;
            
            ones[i] = x;
            if (x)
                succOnes[i] = 1;
            else    
                succZeros[i] = 1;

            if (i) {
                ones[i] += ones[i-1];
                if (x)
                    succOnes[i] += succOnes[i-1];
                else    
                    succZeros[i] += succZeros[i-1];
            }
        }

        for (int i=0 ; i<n ; i++) {
            succOnes[i] = succOnes[i] > 1 ? 1 : 0;
            succZeros[i] = succZeros[i] > 1 ? 1 : 0;

            if (!i) continue;
            succOnes[i] += succOnes[i-1];
            succZeros[i] += succZeros[i-1];
        }

        while(q--) {
            int l, r;
            cin>>l>>r;

            l--;
            r--;

            int length = r-l+1;

            if (length % 3) {
                cout<<-1<<endl;
                continue;
            }

            int o = ones[r];
            if (l)
                o -= ones[l-1];

            if (o % 3) {
                cout<<-1<<endl;
                continue;
            }

            int cnt = (succZeros[r]-succZeros[l]) + (succOnes[r]-succOnes[l]);

            if (cnt == 0)
                cout<<length/3 + 1<<endl;
            else
                cout<<length/3<<endl;
        }

    }
}

int main() {
    solve();
    return 0;
}