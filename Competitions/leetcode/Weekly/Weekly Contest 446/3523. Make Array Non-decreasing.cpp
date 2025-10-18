#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int maximumPossibleSize(vector<int>& v) {
        int n = v.size();
        
        int ans = n;
        
        for (int i=1 ; i<n ; i++) {
            if (v[i] < v[i-1]) {
                ans--;
                v[i] = v[i-1];
            }
        }       
        
        return ans;
    }
};