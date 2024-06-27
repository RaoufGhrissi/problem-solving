#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& v, int limit) {
        deque<int> mx, mi;
        int ans = 0, i = 0, j = 0, n = v.size();

        while(j<n) {
            if (mi.empty() || (max(mx.front(), v[j])  - min(mi.front(), v[j]) <= limit)) {
                while(!mx.empty() && mx.back() < v[j])
                    mx.pop_back();
                mx.push_back(v[j]);
                
                while(!mi.empty() && mi.back() > v[j])
                    mi.pop_back();
                mi.push_back(v[j]);
                j++;
            } else {
                ans = max(ans, j-i);

                if (!mx.empty() && mx.front() == v[i])
                    mx.pop_front();

                if (!mi.empty() && mi.front() == v[i])
                    mi.pop_front();

                i++;
            }
        }

        return max(ans, j-i);
    }
};