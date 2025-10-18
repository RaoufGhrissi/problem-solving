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
        int n;
        cin>>n;

        vector<int> v[n];
        map<int, vector<pp>> cols;
        int mxK = 0;

        for (int i=0 ; i<n ; i++) {
            int k;
            cin>>k;

            mxK = max(k, mxK);

            for (int j=0 ; j<k ; j++) {
                int x;
                cin>>x;

                v[i].push_back(x);
                cols[j].push_back({x, i});
            }
        }

        set<int> possiblePrev;
        bool start = 1;
        for (int col=0 ; col<mxK ; col++) {
            int mi = 1e9;

            for (auto &[num, index]:cols[col]) {
                if (start || possiblePrev.count(index)) {
                    mi = min(mi, num);
                }
            }

            bool last = 0;
            set<int> nxt;

            for (auto &[num, index]:cols[col]) {
                if ((start || possiblePrev.count(index)) && mi == num) {
                    nxt.insert(index);
                    if (!last) {
                        last = (col+1) == v[index].size();
                    }
                }
            }

            cout<<mi<<" ";
            if (last) {
                start = 1;
            } else {
                start = 0;
                possiblePrev = nxt;
            }
        }

        cout<<endl;


    }
}

int main() {
    solve();
    return 0;
}