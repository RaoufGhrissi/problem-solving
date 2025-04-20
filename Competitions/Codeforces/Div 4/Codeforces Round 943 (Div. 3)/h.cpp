#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

const int N = 1e5 + 1;
vector<int> divs[N];

void generateDivs(int k) {
    for (int i=2 ; i*i<=k ; i++) {
        if (k%i == 0) {
            divs[k].push_back(i);
            divs[k].push_back(k/i);
        }
    }

    divs[k].push_back(k);
} 

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    for (int i=2 ; i<N ; i++) {
        generateDivs(i);
    }

    while(t--) {
        int n,q;
        cin>>n>>k;

        
        vector<int> cum(n, 0);
        for(n) {
            int s = 0;
            int e = 16;

            while(s<e) {
                int mid = (s+e)/2;

                int d = power(v[i], mid, k);

                if (d == k+1) {
                    e = mid-1;
                } else {
                    if (k%d == 0) {
                        s = mid;
                    } else {
                        e = mid-1;
                    }
                }
            }

            cum[i] = k/power(v[i], s, k);
        }

        for(n) {
            if (i) cum[i] += cum[i-1];
        }

        
    }
}

int main() {
    solve();
    return 0;
}