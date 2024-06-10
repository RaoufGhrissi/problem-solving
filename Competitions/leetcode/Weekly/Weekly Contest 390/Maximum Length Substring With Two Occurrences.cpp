#include <bits/stdc++.h>

using namespace std;

#define pp pair<string, int>

class Solution {
public:
    int maximumLengthSubstring(string v) {
        int n = v.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        map<int,int> occ;

        while(j<n){
            if (!occ.count(v[j]) || occ[v[j]] == 1) {
                ++occ[v[j++]];
            } else {
                ans = max(ans, j-i);
                --occ[v[i]];
                if (!occ[v[i]]) occ.erase(v[i]);
                i++;
            }
        }

        return max(ans, j-i);
    }
};