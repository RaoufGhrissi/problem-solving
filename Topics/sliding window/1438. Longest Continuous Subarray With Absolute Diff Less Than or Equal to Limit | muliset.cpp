#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& v, int limit) {
        multiset<int> taken;
        int ans = 0, i = 0, j = 0, n =v.size();

        while(j<n) {
            if (taken.empty() || (max(*taken.rbegin(), v[j])  - min(*taken.begin(), v[j]) <= limit))
                taken.insert(v[j++]);
            else
                ans = max(ans, j-i), taken.erase(taken.lower_bound(v[i++]));
        }

        return max(ans, j-i);
    }
};