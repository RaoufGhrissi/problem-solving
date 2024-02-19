#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    ll maximumSubarraySum(vector<int>& v, int k) {
        map<int,ll> mi;
        
        int n = v.size();
        vector<ll> cum(n);
        ll ans = -1e15;
        
        for (int i=0 ; i<n ; i++) {
            cum[i] = v[i];
            if (i)
                cum[i] += cum[i-1];
            
            int target1 = v[i]-k;
            int target2 = v[i]+k;
            
            if (mi.count(target1)) {
                ans = max(ans, cum[i]-mi[target1]);
            }
            
            if (mi.count(target2)) {
                ans = max(ans, cum[i]-mi[target1]);
            }
            
            if (mi.count(v[i]))
                mi[v[i]] = min(mi[v[i]], i ? cum[i-1] : 0);
            else
                mi[v[i]] = i ? cum[i-1] : 0;
        }
        
        return ans == -1e15 ? 0 : ans;
    }
};