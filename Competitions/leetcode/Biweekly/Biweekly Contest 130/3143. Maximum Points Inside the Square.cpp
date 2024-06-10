#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& pp, string s) {
        ll i = 0;
        ll j = 1e9;
        
        int n = pp.size();
        while(i<j) {
            ll mid = (i+j+1)/2;
            ll x1 = -mid;
            ll x2 = mid;
            ll y1 = -mid;
            ll y2 = mid;
            set<char> st;
            
            bool ok = 1;
            for (int dd=0 ; dd<n ; dd++) {
                ll x = pp[dd][0];
                ll y = pp[dd][1];
                
                if (x>=x1 && x<=x2 && y>=y1 && y<=y2) {
                    if (st.count(s[dd])) {
                        ok = 0;
                        break;
                    }
                    
                    st.insert(s[dd]);
                }
            }
            
            if (ok) {
                i = mid;
            } else {
                j = mid-1;
            }
        }
        
        ll x1 = -i;
            ll x2 = i;
            ll y1 = -i;
            ll y2 = i;
            set<char> st;
            for (int dd=0 ; dd<n ; dd++) {
                ll x = pp[dd][0];
                ll y = pp[dd][1];
                
                if (x>=x1 && x<=x2 && y>=y1 && y<=y2) {
                    
                    st.insert(s[dd]);
                }
            }
        
        return st.size();
    }
};