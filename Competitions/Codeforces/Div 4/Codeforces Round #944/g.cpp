#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> v(n);
        map<int, set<int>> mp;

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            mp[v[i]].insert(i);
        }

        for (int i=0 ; i<n ; i++) {
            int x = v[i];

            int base = x;

            if (base&1) base--;
            if (base&(1<<1)) base -= 2;

            for (int j=0 ; j<4 ; j++) {
                int target = base|j;

                if (target >= x) continue;

                if (mp.count(target)) {
                    auto it = mp[target].rbegin();
                    int index = *it;

                    if (index < i) continue;
                    
                    mp[target].erase(*it);

                    if (mp[target].empty())
                        mp.erase(target);

                    mp[x].erase(*mp[x].find(i));
                    mp[x].insert(index);
                    
                    swap(v[i], v[index]);
                    break;
                }
            }
        }

        for (int i=0 ; i<n ; i++) cout<<v[i]<<" ";

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}