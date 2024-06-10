#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& v1, vector<int>& v2) {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        int n = v1.size(), m = v2.size();
        
        int ans = 1e5;
        for (int x1=0 ; x1<n ; x1++) {
            for (int x2=0 ; x2<n ; x2++) {
                if (x1 == x2) continue;
                
                int i = 0;
                int j = 0;
                
                int prev = -100000;
                
                while(j<m) {
                    if (i == x1) i++;
                    if (i == x2) i++;
                    
                    int diff = v2[j] - v1[i];
                    if (prev != -100000 && diff != prev) { prev = -100000; break; }
                    prev = diff;
                    
                    i++;
                    j++;
                }
                
                if (prev != -100000)
                    ans = min(ans, prev);
            }
        }
        
        return ans;
    }
};