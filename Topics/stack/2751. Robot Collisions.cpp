#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        vector<vector<int>> v;
        int n = p.size();
        for (int i=0 ; i<n ; i++)
            v.push_back({p[i], h[i], d[i]=='R', i});
        
        sort(v.begin(), v.end());
        
        stack<vector<int>> st;
        for (int i=0 ; i<n ; i++) {
            if (v[i][2])
                st.push(v[i]);
            else {
                bool rightKilled = 0;
                while(!st.empty() && st.top()[1] <= v[i][1]) {
                    if (v[i][1] == st.top()[1]) {
                        st.pop();
                        v[i][1] = 0;
                        rightKilled = 1;
                        break;
                    }

                    st.pop();
                    v[i][1]--;
                    if (!v[i][1]) {
                        rightKilled = 1;
                        break;
                    }
                }

                if (!st.empty()) {
                    if (rightKilled) continue;
                    st.top()[1]--;
                    if (!st.top()[1])
                        st.pop();
                } else if (v[i][1])
                    st.push(v[i]);
            }
        }
        
        vector<int> res(n, -1), ans;
        while(!st.empty()) {
            res[st.top()[3]] = st.top()[1];
            st.pop();
        }
        
        for (int i=0 ; i<n ; i++)
        {
            if (res[i] != -1)
                ans.push_back(res[i]);
        }
        
        return ans;
    }
};

int main() {
    vector<int> p = {3,5,2,6}, h = {10,10,15,12};
    auto a = Solution().survivedRobotsHealths(p, h, "RLRL");
}