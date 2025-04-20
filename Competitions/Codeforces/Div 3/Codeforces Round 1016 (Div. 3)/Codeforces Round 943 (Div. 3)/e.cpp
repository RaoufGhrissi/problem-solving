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
        int n, k;
        cin>>n>>k;

        vector<int> v(n);

        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        int s = 0;
        int e = 1e9;

        while(s<e) {
            int mid = (s+e+1)/2;

            int cnt = 0;
            priority_queue<int, vector<int>, greater<int>> pq;
            int mex = 0;

            for (int i=0 ; i<n ; i++) {
                pq.push(v[i]);

                while (!pq.empty() && mex >= pq.top()) {
                    int tp = pq.top();
                    pq.pop();
                    if (tp == mex) mex++;
                }

                if (mex >= mid && i<n-1) {
                    cnt++;
                    mex = 0;
                    while(!pq.empty()) {
                        pq.pop();
                    }
                }
            }

            bool ok = 0;
            int kk = k-1;

            if (cnt > kk) ok = 1;
            else if (cnt < kk) ok = 0;
            else {
                if (mex >= mid) ok = 1;
                else ok = 0;
            }

            if (ok) {
                s = mid;
            } else {
                e = mid-1;
            }
        }

        cout<<s<<endl;
    }
}

int main() {
    solve();
    return 0;
}