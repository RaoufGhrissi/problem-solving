#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

const int N = 1e5 + 1;
vector<int> divs[N];
vector<int> a[N];

int k, l, r;
void generateDivs() {
    for (int i=1 ; i<N ; i++) {
        for (int j=i ; j<N ; j+=i) {
            divs[j].push_back(i);
        }
    }
} 

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    generateDivs();

    while(t--) {
        int n, q;
        cin>>n>>q;

        for (int i=2 ; i<N ; i++)
            a[i].clear();

        vector<int> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            a[v[i]].push_back(i);
        }

        while(q--) {
            cin>>k>>l>>r;
            l--;
            r--;

            ll ans = 0;
            int prev = l;
            while(1) {
                int miId = r+1;
                for (int &div:divs[k]) {
                    int pos = lower_bound(a[div].begin(), a[div].end(), l) - a[div].begin();

                    if (pos < a[div].size()) {
                        miId = min(miId, a[div][pos]);
                    }
                }

                ans += k*(miId-prev);

                if (miId == r+1) break;

                while(k % v[miId] == 0) {
                    k /= v[miId];
                }

                prev = miId;
            }

            cout<<ans<<endl;
        }        
    }
}

int main() {
    solve();
    return 0;
}