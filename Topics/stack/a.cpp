#include <bits/stdc++.h>
#define pp pair<char, int>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    string s;
    cin>>s;

    int n = s.size();
    vector<int> occ(26, 0);
    
    for (int i=0 ; i<n ; i++) {
        occ[s[i]-'a']++;
    }

    stack<int> t;
    string u = "";

    for (int i=0 ; i<n ; i++) {
        while(!t.empty()) {
            bool lesser = false;
            int order = s[t.top()] - 'a';
            for (int i=0 ; i<order ; i++) {
                if (occ[i] > 0) {
                    lesser = true;
                    break;
                }
            }

            if (lesser) {
                break;
            }

            u += s[t.top()];
            t.pop();
        }

        t.push(i);
        occ[s[i] - 'a']--;
    }

    while(!t.empty()) {
        u += s[t.top()];
        t.pop();
    }

    cout<<u<<endl;
}

int main() {
    solve();
    return 0;
}