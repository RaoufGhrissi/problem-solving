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

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        string s;
        cin>>s;

        int ans = 0;
        int occA = 0;
        int occB = 0;

        // prefix
        for (int i=0 ; i<n ; i++) {
            occA += s[i] == 'a';
            occB += s[i] == 'b';
        }

        if (occA == occB) {
            cout<<0<<endl;
            continue;
        }

        int ta = 0, tb = 0;
        for (int i=0 ; i<n-2 ; i++) {
            ta += s[i] == 'a';
            tb += s[i] == 'b';

            if ((occA-ta) == (occB - tb)) {
                ans = max(ans, n-1-i);
                break;
            }
        }

        // suffix
        ta = 0, tb = 0;
        for (int i=n-1 ; i>1 ; i--) {
            ta += s[i] == 'a';
            tb += s[i] == 'b';

            if ((occA-ta) == (occB - tb)) {
                ans = max(ans, i);
                break;
            }
        }

        // 9asa fil west
        vector<int> v1(n);
        vector<int> v2(n);

        int a = 0, b = 0;
        for (int i=0 ; i<n ; i++) {
            a += s[i] == 'a';
            b += s[i] == 'b';

            v1[i] = a-b;
        }

        a = 0, b = 0;
        for (int i=n-1 ; i>-1 ; i--) {
            a += s[i] == 'a';
            b += s[i] == 'b';

            v2[i] = b-a;
        }


        map<int, int> last;

        for (int i=0 ; i<n ; i++) {
            if (last.count(v2[i])) {
                ans = max(ans, last[v2[i]]+1+n-i);
            }

            last[v1[i]] = i;
        }

        if (ans == 0) {
            cout<<-1<<endl;
        } else {
            cout<<n-ans<<endl;
        }
        
    }
}

int main() {
    solve();
    return 0;
}