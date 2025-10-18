#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pp pair<ll, string>

using namespace std;

void ternary_representation(string &curr, int &n, vector<string> &ans) {
    if (curr.size() == n) {
        ans.push_back(curr);
        return;
    }

    for (char c='0' ; c<='2' ; c++) {
        curr.push_back(c);
        ternary_representation(curr, n, ans);
        curr.pop_back();
    }
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
        string curr = "";
        ternary_representation(curr, n, reprs);
        
        string correct;
        for (string &repr:reprs) {
            int tot = 0;

            for (int i=0 ; i<m ; i++) {
                string m1 = combinedModules[i][0];
                string m2 = combinedModules[i][1];

                int id1 = idPerName[m1];
                int id2 = idPerName[m2];

                if (
                    (repr[id1] != '2' && repr[id2] != '2') // both not magic
                    && 
                    (repr[id1] != '1' or repr[id2] != '1') // both not bough
                ) {
                    tot = -1;
                    break;
                }
            }

            if (tot != -1) {
                for (int i=0 ; i<n ; i++) {
                    char c = repr[i];
                    if (c == '0') continue;
                    if (c == '1') tot += price[i];
                    if (c == '2') tot += magicPrice[i];
                }

                if (tot < ans) {
                    ans = tot;
                    correct = repr;
                }
            }
        }

        cout<<ans;
    }

    return 0;
}