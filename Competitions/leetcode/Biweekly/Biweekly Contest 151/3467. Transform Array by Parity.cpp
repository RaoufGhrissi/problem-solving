#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& v) {
        int n = v.size();
        for (int i=0 ; i<n ; i++) {
            if (v[i] % 2 == 0) v[i] = 0;
        }
        
        for (int i=0 ; i<n ; i++) {
            if (v[i] % 2) v[i] = 1;
        }
        
        sort(v.begin(), v.end());
        
        return v;
    }
};