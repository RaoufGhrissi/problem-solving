#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& v) {
        int n = v.size();
        
        set<int> st;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (i==j) continue;
                for (int k=0 ; k<n ; k++) {
                    if (k==j) continue;
                    if (k==i) continue;
                    
                    if (v[i]%2 == 0 && v[k]) {
                        st.insert(v[i]+10*v[j]+100*v[k]);
                    }
                }
            }
        }
        
        return st.size();
    }
};