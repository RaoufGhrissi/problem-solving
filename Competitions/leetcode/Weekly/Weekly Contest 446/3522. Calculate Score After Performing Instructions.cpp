#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    long long calculateScore(vector<string>& v, vector<int>& values) {
        int n = v.size();
        vector<bool> vis(n, 0);
        ll ans = 0;
        
        int i = 0;
        while(i<n && i>-1 && !vis[i]) {
            vis[i] = 1;
            if (v[i] == "add") ans += values[i++];
            else i += values[i];
        }
        
        return ans;
    }
};