#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n1, n2, m1, m2;
    cin>>n1>>n2>>m1>>m2;

    set<string> likes1;
    set<string> likes2;
    set<string> hates1;
    set<string> hates2;

    for (int i=0 ; i<n1 ; i++) {
        string s;
        cin>>s;
        likes1.insert(s);
    }

    for (int i=0 ; i<n2 ; i++) {
        string s;
        cin>>s;
        likes2.insert(s);
    }

    for (int i=0 ; i<m1 ; i++) {
        string s;
        cin>>s;
        hates1.insert(s);
    }

    for (int i=0 ; i<m2 ; i++) {
        string s;
        cin>>s;
        hates2.insert(s);
    }

    set<string> ans;

    for (auto &name:likes1) {
        if (hates1.count(name)) continue;
        if (hates2.count(name)) continue;
        if (!likes2.count(name)) continue;

        ans.insert(name);
    }
    
    for (auto &a:ans)
        cout<<a<<endl;
}

int main() {
    solve();
    return 0;
}