#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int x = 0;
        int ans = 0;
        for (auto &a:nums) {
            x += a;
            if (!x)
                ans++;
        }
        
        return ans;
    }
};