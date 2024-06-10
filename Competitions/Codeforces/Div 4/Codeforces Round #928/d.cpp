#include <bits/stdc++.h>

using namespace std;

int getComp(int n) {
    int ans = 0;

    for (int i=30 ; i>-1 ; i--) {
        int mask = (1<<i);
        if (mask & n) continue;

        ans += mask;
    }

    return ans;
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        
        map<int, int> cnt;
        int gr = 0;
        
        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;

            cnt[x]++;
        }

        set<int> used;

        for (auto &a:cnt) {
            int x = a.first;
            if (used.count(x)) continue;
            int y = a.second;
            int c = getComp(a.first);
            if (!cnt.count(c)) {
                gr += y;
            } else {
                gr += max(y, cnt[c]);
                used.insert(c);
            }
        }

        cout<<gr<<endl;
    }
}

int main() {
    solve();
    return 0;
}