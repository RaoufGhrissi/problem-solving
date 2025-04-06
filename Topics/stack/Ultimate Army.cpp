#include <bits/stdc++.h>
#define pp pair<char, int>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int n;
    cin>>n;

    string s;
    cin>>s;

    stack<int> st;
    vector<int> parent(n+1, 0);

    for (int i=0 ; i<s.size() ; i++) {
        if (s[i] == ')') {
            int num = st.top();
            st.pop();
            st.pop();
            parent[num] = st.top();
        } else if (s[i] == '(') {
            st.push(0);
        } else {
            int t = 0;
            if (!st.empty() && st.top() > 0) {
                t = st.top();
                st.pop();
            }

            st.push(t*10 + (s[i]-'0'));
        }
    }

    for (int i=1 ; i<=n ; i++) {
        cout<<parent[i]<<" ";
    }
}

int main() {
    solve();
    return 0;
}