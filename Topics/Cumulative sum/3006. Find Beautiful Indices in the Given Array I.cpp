#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {       
        int na = a.size();
        int n = s.size();
        int nb = b.size();
        
        vector<int> posA;
        vector<int> cum(n, 0);
        for (int i=0 ; i < n ; i++) {
                string ch = s.substr(i, na);
                if (ch == a) posA.push_back(i);
            
            
                ch = s.substr(i, nb);
                if (ch == b)
                    cum[i] = 1;
            
        }
        
        
        
        for (int i=1 ; i<n ; i++) {
            cum[i] += cum[i-1];
        }
        
        vector<int> ans;
        for (auto &id:posA) {
            int j1 = id-k;
            int j2 = id+k;
            
            
            int sm = cum[min(n-1, j2)];
            if (j1 > 0) {
                sm -= cum[j1-1];
            }
            
            if (sm)
                ans.push_back(id);
        }
        
        
        return ans;
        
    }
};