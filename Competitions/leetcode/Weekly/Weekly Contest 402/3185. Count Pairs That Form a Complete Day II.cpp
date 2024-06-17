#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& v) {
        vector<long long> mod24(24, 0);
        
        long long ans = 0;
        
        for (auto &a:v) {
            ans += mod24[a%24];
            long long m = -a%24;
            mod24[m<0 ? 24+m : m]++;
        }
        
        return ans;
    }
};