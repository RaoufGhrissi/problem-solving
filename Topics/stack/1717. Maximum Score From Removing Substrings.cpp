#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int comp(string &s, int x, char x1, char x2, stack<char> &st) {
        int ans = 0;
        for (char &c:s) {
            if (c == x2 && !st.empty() && st.top() == x1) {
                st.pop();
                ans += x;
            } else {
                st.push(c);
            }
        }
        return ans;
    }
    
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = comp(s, max(x, y), x>=y ? 'a' : 'b', x>=y ? 'b' : 'a', st);

        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());
        return ans + comp(s, min(x, y), x>=y ? 'b' : 'a', x>=y ? 'a' : 'b', st);
    }
};

int main() {
    cout<<Solution().maximumGain("cdbcbbaaabab", 4, 5);
}