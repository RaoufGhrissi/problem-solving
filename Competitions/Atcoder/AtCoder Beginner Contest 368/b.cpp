#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t = 1;
    //cin>>t;

    while(t--) {
        ll n; 
        cin>>n;

        priority_queue<int> a;

        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;

            a.push(x);
        }

        int op = 0;
        while (a.size() > 1) {
            int t = a.top();
            a.pop();
            
            int t2 = a.top();
            a.pop();

            if (t-1>0)
                a.push(t-1);

            if (t2-1>0)
                a.push(t2-1);

            op++;
        }

        cout<<op<<endl;
    }
}

int main() {
    solve();
    return 0;
}