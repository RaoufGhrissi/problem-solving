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

string s;

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n, m;
        cin>>n>>m;

        map<int, vector<int>> mp;

        for (int i=0 ; i<m ; i++) {
            int x;
            cin>>x;

            s = to_string(x);

            s.pop_back();
            s.pop_back();

            mp[stoi(s)].push_back(x);
        }

        vector<int> v;

        for (auto &a:mp) {
            for (auto &x:a.second) {
                v.push_back(x);
            }
        }

        vector<pp> pairs;
        for (int i=0 ; i<m ; i++) {
            pairs.push_back({v[i], v[m-1-i]});
        }

        int p = 0;
        for (int i=0 ; i<n ; i+=2) {
            for (int x=0 ; x<3 ; x++)
                cout<<pairs[p].first<<" "<<pairs[p].second<<" ";

            cout<<endl;

            if (i==n-1) break;

            for (int x=0 ; x<3 ; x++)
                cout<<pairs[p].second<<" "<<pairs[p].first<<" ";

            cout<<endl;
            p++;
        }
    }
}

int main() {
    solve();
    return 0;
}