#include <bits/stdc++.h>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        string s;

        int l1 = 0;
        int l2 = 0;
        bool stop = 0;
        for (int i=0 ; i<n ; i++) {
            int cnt = 0;
            cin>>s;

            if (stop)
                continue;

            for (auto &c:s)
                cnt += c-'0';

            if (!cnt)
                continue;

            if (!l1) {
                l1 = cnt;
            } else {
                l2 = cnt;
            }

            if (l1 && l2) {
                stop = 1;
                if (l1 == l2)
                    cout<<"SQUARE";
                else
                    cout<<"TRIANGLE";

                cout<<endl;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}