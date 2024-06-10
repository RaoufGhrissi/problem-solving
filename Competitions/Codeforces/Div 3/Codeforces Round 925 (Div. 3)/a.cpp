#include <bits/stdc++.h>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        bool found = 0;

        for (int i=1 ; i<27 ; i++) {
            if (found) break;
            for (int j=1 ; j<27 ; j++) {
                if (found) break;
                for (int k=1 ; k<27 ; k++) {
                    int sm = i+j+k;
                    if (sm == n) {
                        string s = "";
                        s += char(i+'a'-1);
                        s += char(j+'a'-1);
                        s += char(k+'a'-1);
                        cout<<s<<endl;
                        found = 1;
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    solve();
    return 0;
}