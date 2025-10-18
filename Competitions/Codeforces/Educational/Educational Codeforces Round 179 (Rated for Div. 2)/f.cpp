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

string x, y;

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n, q;
        cin>>n>>q;

        string s;
        cin>>s;

        map<string, set<int>> ids;

        for (int i=0 ; i<q ; i++) {
            cin>>x>>y;

            x += y;

            ids[x].insert(i);
        }

        for (int i=0 ; i<n ; i++) {
            if (s[i] == 'a') continue;

            if (s[i] == 'c') {
                if (ids.count("ca")) {
                    ids["ca"].erase(ids["ca"].begin());
                    if (ids["ca"].empty()) {
                        ids.erase("ca");
                    }

                    s[i] = 'a';
                } else if (ids.count("cb")) {
                    int index = *ids["cb"].begin();
                    s[i] = 'b';
                    ids["cb"].erase(index);
                   
                    if (ids["cb"].empty())
                        ids.erase("cb");
                    
                    if (!ids.count("ba")) continue;

                    auto it = ids["ba"].lower_bound(index);
                    if (it != ids["ba"].end()) {
                        s[i] = 'a';

                        ids["ba"].erase(*it);
                        if (ids["ba"].empty())
                            ids.erase("ba");
                    }


                }
            } else {
                if (ids.count("ba")) {
                    ids["ba"].erase(ids["ba"].begin());
                    if (ids["ba"].empty()) {
                        ids.erase("ba");
                    }

                    s[i] = 'a';
                } else if (ids.count("bc") && ids.count("ca")) {
                    int index = *ids["bc"].begin();
                    auto it = ids["ca"].lower_bound(index);

                    if (it != ids["ca"].end()) {
                        s[i] = 'a';
                        ids["bc"].erase(index);
                        ids["ca"].erase(*it);

                        if (ids["bc"].empty())
                            ids.erase("bc");

                        if (ids["ca"].empty())
                            ids.erase("ca");
                    }
                }
            }
        }

        cout<<s<<endl;
    }
}

int main() {
    solve();
    return 0;
}