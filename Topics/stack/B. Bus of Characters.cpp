#include <bits/stdc++.h>
#define pp pair<int, int>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t = 1;

    while(t--) {
        int n;
        cin>>n;

        vector<pp> v(n);
        for (int i=0 ; i<n ; i++) {
            cin>>v[i].first;
            v[i].second = i;
        }

        sort(v.begin(), v.end());
        stack<int> st;

        string s;
        cin>>s;
        
        int i=0;
        for (char &c:s) {
            if (c == '0') {
                cout<<v[i].second + 1<<" ";
                st.push(v[i].second);
                i++;
            } else {
                cout<<st.top() + 1<<" ";
                st.pop();
            }
        }
    }
}

int main() {
    solve();
    return 0;
}


