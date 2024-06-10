#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool static compare(vector<int> p1, vector<int> p2) {
        if (p1[0] == p2[0])
            return p1[1] > p2[1];

        return p1[0] < p2[0];
    }

    int numberOfPairs(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), compare);

        stack<vector<int>> st;
        int ans = 0;
        for (auto &a:v) {
            while(!st.empty() && st.top()[1] >= a[1]) {
                st.pop();
                ans++;
            }
            
            st.push(a);
        }

        return ans;
    }
};