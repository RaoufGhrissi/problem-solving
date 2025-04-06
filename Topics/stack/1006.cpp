#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int clumsy(int n) {
        int op = 0; // 0 *, 1 /, 2 +, 3 -
        stack<int> st; // + = -1, - = -2
        st.push(n);
        for (int i=n-1 ; i>0 ; i--) {
            if (op == 0) {
                st.top() *= i;
            } else if (op == 1) {
                st.top() /= i;
            } else {
                st.push(op == 2 ? -1 : -2);
                st.push(i);
            }
            op = (op + 1) % 4;
        }

        int ans = 0;

        while(!st.empty()) {
            int t = st.top();
            st.pop();

            if (!st.empty()) {
                int sign = st.top();
                ans += sign == -1 ? t : -t;
                st.pop();
            } else {
                ans += t;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.clumsy(4) << endl;
    return 0;
}   