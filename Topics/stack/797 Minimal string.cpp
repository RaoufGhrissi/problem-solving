#include <bits/stdc++.h>
#define pp pair<char, int>

using namespace std;

void solve() {
    //freopen("a.txt", "r", stdin);
    string s;
    cin>>s;

    int n = s.size();

    vector<int> nearest(n, n);
    stack<int> t;
    stack<int> st;
    string u = "";
    
    for (int i=0 ; i<n ; i++) {
        while(!st.empty() && s[st.top()] > s[i]) {
            nearest[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    for (int i=0 ; i<n ; i++) {
        if (nearest[i] == n) {
            u += s[i];
        } else {
            if (t.empty() || s[t.top()] > nearest[i]) {
                t.push(i);
            } else {
                u += s[t.top()];
                t.pop();
            }
        }
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