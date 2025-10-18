#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pp pair<ll, string>

using namespace std;


int main() {
    ll t,n;
    FAST;
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif   
    t = 1;
    //cin>>t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        string name[n];
        map<string,int> idPerName;
        int price[n];
        int magicPrice[n];

        vector<vector<string>> combinedModules(m);

        for (int i=0 ; i<n ; i++) {
            cin>>name[i]>>price[i]>>magicPrice[i];
            idPerName[name[i]] = i;
        }

        for (int i=0 ; i<m ; i++) {
            string combinedName;
            cin>>combinedName;

            int sz = combinedName.size();
            string ch = "";
            for (char &c:combinedName) {
                if (c == '_') {
                    combinedModules[i].push_back(ch);
                    ch = "";
                } else {
                    ch += c;
                }
            }

            combinedModules[i].push_back(ch);
        }

        int ans = 1e9;

        vector<string> reprs;
        for (int mask=0 ; mask<(1<<n) ; mask++) {
            string rep = "";
            for (int i=0 ; i<n ; i++) {
                int _mask = 1<<i;
                if (mask&_mask) {
                    rep += '1';
                } else {
                    rep += '0';
                }
            }
            reprs.push_back(rep);
        }
        
        
        string correct;
        vector<bool> usedNormal(n, 0);
        for (string repr:reprs) {
            int tot = 0;

            // reset to 0
            for (int i=0 ; i<n ; i++)
                usedNormal[i] = 0;

            for (int i=0 ; i<m ; i++) {
                string m1 = combinedModules[i][0];
                string m2 = combinedModules[i][1];

                int id1 = idPerName[m1];
                int id2 = idPerName[m2];

                if (repr[id1] == '1' || repr[id2] == '1') { // one of them is magic => get the combined
                    continue;
                } {
                    // both not magic => get them in normal way if possible
                    usedNormal[id1] = 1;
                    usedNormal[id2] = 1;
                }
            }

            for (int i=0 ; i<n ; i++) {
                char c = repr[i];
                if (c == '1') tot += magicPrice[i];
                else if (usedNormal[i]) tot += price[i];
            }

            if (tot < ans) {
                ans = tot;
                correct = repr;
            }
        }

        cout<<ans;
    }

    return 0;
}