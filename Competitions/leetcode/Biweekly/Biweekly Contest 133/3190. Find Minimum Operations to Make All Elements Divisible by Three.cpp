#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int ans = 0;
        
        for (auto &c:v) {
            int prev = c/3 * 3;
            int next = (c/3 + 1) * 3;
            ans += min(c-prev, next-c);
        }
        
        return ans;
    }
};