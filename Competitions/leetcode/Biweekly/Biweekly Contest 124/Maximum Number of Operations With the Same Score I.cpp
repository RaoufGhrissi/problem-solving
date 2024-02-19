#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& v) {
        int n = v.size();
        int ans = 1;
        
        for (int i=2 ; i<n ; i+=2) {
            if (i+1 < n && v[i]+v[i+1] == v[0]+v[1]) {
                ans++;
            } else
                break;
        }
        return ans;
    }
};