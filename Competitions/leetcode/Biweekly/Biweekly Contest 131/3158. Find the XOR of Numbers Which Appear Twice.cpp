#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& v) {
        map<int,int> mp;
        
        for (auto &c:v)
                mp[c]++;
        
        int ans = 0;
        
        for (auto &c:mp) {
            if (c.second == 2)
                ans ^= c.first;
        }
        
        return ans;
    }
};