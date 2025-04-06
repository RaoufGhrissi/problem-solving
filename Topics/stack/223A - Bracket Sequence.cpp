#include <bits/stdc++.h>
#define pp pair<char, int>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    string s;
    cin>>s;

    int n = s.size();
    vector<int> cum(n, 0);

    for (int i=0 ; i<n ; i++) {
        if (s[i] == '[')
            cum[i] = 1;

        if (i > 0)
            cum[i] += cum[i-1];
    }

    stack<pp> st;
    
    int ans = 0;
    int ansStart, ansEnd;

    for (int i=0 ; i<s.size() ; i++) {
        if (s[i] == ']') {
            if (!st.empty() && st.top().first == '[') {
                st.pop();
                int end = i;
                int start = st.empty() ? 0 : st.top().second + 1;
                int res = cum[end];
                if (start > 0)
                    res -= cum[start-1];

                if (res > ans) {
                    ans = res;
                    ansStart = start;
                    ansEnd = end;
                }
            } else {
                st.push({s[i], i});
            }
        } else if (s[i] == ')') {
            if (!st.empty() && st.top().first == '(') {
                st.pop();
                int end = i;
                int start = st.empty() ? 0 : st.top().second + 1;
                int res = cum[end];
                if (start > 0)
                    res -= cum[start-1];

                if (res > ans) {
                    ans = res;
                    ansStart = start;
                    ansEnd = end;
                }
            } else {
                st.push({s[i], i});
            }
        } else {
            st.push({s[i], i});
        }
    }

    cout<<ans<<endl;
    if (ans == 0)
        cout<<""<<endl;
    else
        cout<<s.substr(ansStart, ansEnd-ansStart+1)<<endl;
}

int main() {
    solve();
    return 0;
}