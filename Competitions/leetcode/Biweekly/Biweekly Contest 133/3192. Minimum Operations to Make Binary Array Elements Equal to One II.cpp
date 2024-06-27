#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& v) {
        int flips = 0;
        int ans = 0;
        
        for (int &c:v) {
            if ((!c && !(flips&1)) || (c && flips&1)) {
                ans++;
                flips++;
            }
        }
        
        return ans;
    }
};