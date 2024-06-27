#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
#define inf 1e18

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& v) {
        int flips = 0;
        int ans = 0;
        int n = v.size();
        
        for (int i=0 ; i<n-2 ; i++) {
            if (v[i]) continue;
            ans++;
            for (int j=0 ; j<3 ; j++) {
                v[i+j] = 1-v[i+j];
            }
        }
        
        for (int i=0 ; i<n ; i++) {
            if (!v[i]) return -1;
        }
        
        
        
        return ans;
    }
};