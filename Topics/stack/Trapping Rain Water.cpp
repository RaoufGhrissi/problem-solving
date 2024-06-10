#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        stack<int> st;
        vector<int> nearest(n, -1);
        vector<int> bigger(n, -1);
        vector<int> cum = v;
        
        for (int i=0 ; i<n ; i++) {
            if (i) cum[i] += cum[i-1];
            while(!st.empty() && v[i] >= v[st.top()]) {
                nearest[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int mx = n-1;
        for (int i=n-2 ; i>-1 ; i--) {
            bigger[i] = mx;
            if (v[i] >= v[mx])
                mx = i;
        }

        int i = 0;
        int ans = 0;
        while(i<n-1) {
            if (!v[i]) i++;
            else {
                if (nearest[i] == -1) {
                    int j = bigger[i];
                    ans += v[j]*(j-i-1) - (cum[j-1] - cum[i]);
                    i = j;
                    continue;
                }
                int j = nearest[i];
                ans += v[i]*(j-i-1) - (cum[j-1] - cum[i]);
                i = j;
            }
        }

        return ans;
    }
};