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
        int n;
        cin>>n;

        map<int, vector<int>, greater<int>> mp;

        vector<int> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            mp[v[i]].push_back(i);
        }

        priority_queue<pp> pq;
        vector<int> clone(n, 0);

        int ans = 0;

        for (auto &a:mp) {
            for (int &id:a.second) {
                int state = (id && clone[id-1]) || (id+1<n && clone[id+1]);
                pq.push({state, id});
            }

            while(!pq.empty()) {
                pp top = pq.top();
                pq.pop();

                int index = top.second;
                int state = top.first;

                if (clone[index]) continue;

                if (!state) {
                    ans++;
                }

                clone[index] = 1;
                int id = index+1;
                //expand right
                while (id < n && !clone[id] && v[id] == v[index]) {
                    clone[id++] = 1;
                }

                id = index-1;
                //expand left
                while (id > -1 && !clone[id] && v[id] == v[index]) {
                    clone[id--] = 1;
                }
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}