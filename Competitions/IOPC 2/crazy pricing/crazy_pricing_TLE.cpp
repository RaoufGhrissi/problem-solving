#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pp pair<ll, string>

using namespace std;

vector<vector<string>> combinedModules;
vector<int> price, magicPrice;
map<string,int> idPerName;

ll rec(int i, int normalMask, int magicMask) {
    if (i==combinedModules.size())
        return 0;
    
    ll ans = 1e9;

    string m1 = combinedModules[i][0];
    string m2 = combinedModules[i][1];

    int id1 = idPerName[m1];
    int id2 = idPerName[m2];

    int mask1 = 1<<id1;
    int mask2 = 1<<id2;

    bool bought1Magic = magicMask&mask1;
    bool bought2Magic = magicMask&mask2;

    if (bought1Magic || bought2Magic) {
        ans = min(ans, rec(i+1, normalMask, magicMask));
    } else {
        // 1 magic
        ans = min(ans, magicPrice[id1] + rec(i+1, normalMask, magicMask | mask1));
        // 2 magic
        ans = min(ans, magicPrice[id2] + rec(i+1, normalMask, magicMask | mask2));
        // buy both not magic if not already done

        ll cost = 0; // cost to buy both
        bool bought1Normal = normalMask&mask1;
        bool bought2Normal = normalMask&mask2;
        if (!bought1Normal)
            cost += price[id1];
        if (!bought2Normal)
            cost += price[id2];

        ans = min(ans, cost + rec(i+1, normalMask | mask1 | mask2, magicMask));
    }

    return ans;
}

int main() {
    ll t,n;
    FAST;
    freopen("a.txt", "r", stdin);
    t = 1;
    //cin>>t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        string name[n];
        price.resize(n);
        magicPrice.resize(n);
        combinedModules.resize(m);

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

        cout<<rec(0, 0, 0)<<" ";
    }

    return 0;
}