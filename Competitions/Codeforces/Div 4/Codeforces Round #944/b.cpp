#include <bits/stdc++.h>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int n;
    cin>>n;

    while(n--) {
        string s;
        cin>>s;

        int i = 1;
        
        int n = s.size();
        while(i<n && s[i] == s[0])
            i++;

        if (i == n) {
            cout<<"NO";
        } else {
            cout<<"YES"<<endl;
            cout<<s.substr(i, n-i) + s.substr(0, i);
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}