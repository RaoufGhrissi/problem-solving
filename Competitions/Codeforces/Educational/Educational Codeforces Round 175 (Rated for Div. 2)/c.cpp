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

        string s;
        cin>>s;

        vector<int> p(n);

        for (int i=0 ; i<n ; i++)
            cin>>p[i];

        int start = 0;
        int end = 1e9;

        while(start<end) {
            int mid = (start+end)/2;

            int cnt = 0;
            bool flip = 0;
            for (int i=0 ; i<n ; i++) {
                if (p[i] <= mid) continue;
                if (s[i] == 'R') {
                    // shouldn't flip
                    if (flip) {
                        flip = 0;
                        cnt++;
                    }
                } else {
                    // should flip
                    flip = 1;
                }
            }

            cnt += flip;

            if (cnt <= k) {
                end = mid;
            } else {
                start = mid+1;
            }
        }

        cout<<start<<endl;
    }
}

int main() {
    solve();
    return 0;
}