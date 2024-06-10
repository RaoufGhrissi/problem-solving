#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        sort(c.begin(), c.end(), greater<int>());
        int sm = 0;
        for (auto &x:a) sm += x;
        
        int ans = 0;
        for (auto &x:c) {
            sm -= x;
            ans++;
            if (sm <= 0)
                break;
        }
        
        return ans;
    }
};