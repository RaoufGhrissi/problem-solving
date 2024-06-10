#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(), h.end(), greater<int>());
        ll ans = 0;
        for (int i=0 ; i<k ; i++) {
            ans += max(0, h[i]-i);
        }
        
        return ans;
    }
};