#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

ll search_element(int col0, int col1, int row0, int row1, ll start, ll end, ll &i, ll &j) {
    if (start == end) return start;

    ll tot = end-start+1;
    ll partSize = tot/4;
    
    // part 1
    ll s = start;
    ll e = s + partSize - 1;
    
    int c0 = col0, c1 = (col0+col1)/2;
    int r0 = row0, r1 = (row0+row1)/2;

    if (i >= r0 && i<=r1 && j>=c0 && j<=c1) {
        return search_element(c0, c1, r0, r1, s, e, i, j);
    }

    // part 2
    s += partSize;
    e = s + partSize - 1;

    c0 = (col0+col1)/2 + 1, c1 = col1, r0 = (row0+row1)/2 + 1, r1 = row1;

    if (i >= r0 && i<=r1 && j>=c0 && j<=c1) {
        return search_element(c0, c1, r0, r1, s, e, i, j);
    }

    // part 3
    s += partSize;
    e = s + partSize - 1;

    c0 = col0, c1 = (col0+col1)/2, r0 = (row0+row1)/2 + 1, r1 = row1;

    if (i >= r0 && i<=r1 && j>=c0 && j<=c1) {
        return search_element(c0, c1, r0, r1, s, e, i, j);
    }

    // part 4
    s += partSize;
    e = s + partSize - 1;
    
    c0 = (col0+col1)/2 + 1, c1 = col1, r0 = row0, r1 = (row0+row1)/2;

    if (i >= r0 && i<=r1 && j>=c0 && j<=c1) {
        return search_element(c0, c1, r0, r1, s, e, i, j);
    }

    return -1;
}

pp search_pos(int col0, int col1, int row0, int row1, ll start, ll end, ll &target) {
    if (start == end) return {row0, col0};

    ll tot = end-start+1;
    ll partSize = tot/4;
    
    ll s = start;
    ll e = s + partSize - 1;
    for (int part=1 ; part<=4 ; part++) {
        if (target >= s && target <= e) {
            if (part == 1) {
                return search_pos(col0, (col0+col1)/2, row0, (row0+row1)/2, s, e, target);
            } else if (part == 2) {
                return search_pos((col0+col1)/2 + 1, col1, (row0+row1)/2 + 1, row1, s, e, target);
            } else if (part == 3) {
                return search_pos(col0, (col0+col1)/2, (row0+row1)/2 + 1, row1, s, e, target);
            } else {
                return search_pos((col0+col1)/2 + 1, col1, row0, (row0+row1)/2, s, e, target);
            }
        }
        
        s += partSize;
        e = s + partSize - 1;
    }

    return {-1, -1};
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    string s;
    ll i, j;

    while(t--) {
        ll n,q;
        cin>>n>>q;

        ll tot = 1<<n;

        while(q > 0) {
            cin>>s;

            if (s == "->") {
                cin>>i>>j;
                i--;
                j--;

                cout<<search_element(0, tot-1, 0, tot-1, 1, tot*tot, i, j)<<endl;
            } else {
                cin>>i;
                pp x = search_pos(0, tot-1, 0, tot-1, 1, tot*tot, i);

                cout<<x.first+1<<" "<<x.second+1<<endl;
            }

            q--;
        }
    }
}

int main() {
    solve();
    return 0;
}