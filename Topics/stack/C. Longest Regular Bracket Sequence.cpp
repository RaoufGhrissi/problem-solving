#include <bits/stdc++.h>
#define pp pair<char, int>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    string s;
    cin>>s;

    stack<pp> st;
    st.push({')', -1});

    int longest = 0;
    map<int,int> cnt;

    for (int i=0 ; i<s.size() ; i++) {
        if (s[i] == ')') {
            if (!st.empty() && st.top().first == '(') {
                st.pop();
            } else {
                st.push({s[i], i});
            }
        } else {
            st.push({s[i], i});
        }
    }

    st.push({')', s.size()});

    while(!st.empty()) {
        int e = st.top().second - 1;
        st.pop();

        if (!st.empty()) {
            int start = st.top().second + 1;
            int res = e - start + 1;

            if (res > 0) {
                cnt[res]++;
                longest = max(longest, res);
            }
        }
    }

    if (cnt.count(longest))
        cout<<longest<<" "<<cnt[longest]<<endl;
    else
        cout<<"0 1"<<endl;
}

int main() {
    solve();
    return 0;
}