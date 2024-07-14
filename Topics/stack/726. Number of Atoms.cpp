#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countOfAtoms(string f) {
        string ans = "";
        stack<pair<string, int>> st;
        int i = 0, n = f.size();

        while(i<n) {
            char c = f[i];
            if (islower(c)) {
                st.top().first += c;
                i++;
            } else if (c == ')') {
                i++;
                int cnt = 0;
                while(i<n && isdigit(f[i])) {
                    cnt = cnt*10 + f[i]-'0';
                    i++;
                }

                stack<pair<string, int>> inter;

                while (!st.empty() && st.top().first != "(") {
                    st.top().second *= cnt;
                    inter.push(st.top());
                    st.pop();
                }

                st.pop();

                while(!inter.empty()) {
                    st.push(inter.top());
                    inter.pop();
                }
            } else if (isdigit(c)) {
                int cnt = 0;
                while(i<n && isdigit(f[i])) {
                    cnt = cnt*10 + f[i]-'0';
                    i++;
                }
                st.top().second = cnt;
            } else {
                ans = "";
                ans += c;
                st.push({ans, 1});
                i++;
            }
        }

        map<string, int> count;
        while(!st.empty()) {
            count[st.top().first] += st.top().second;
            st.pop();
        }

        ans = "";
        for (auto &a:count) {
            ans += a.first;
            if (a.second > 1)
                ans += to_string(a.second);
        }

        return ans;
    }
};  

int main() {
    cout<<Solution().countOfAtoms("K4(ON(SO3)2)2");
}