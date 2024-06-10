#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int ans = 0;
        for (auto &a:v) {
            if (a<k)
                ans++;
        }
        
        return ans;
    }
};
