#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long

using namespace std;

#define ll long long

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int n = bl.size();
        ll ans = 0;
        
        for (int i=0 ; i<n ; i++) {
            for (int j=i+1 ; j<n ; j++) {
                int x1 = bl[i][0];
                int y1 = bl[i][1];
                int x2 = tr[i][0];
                int y2 = tr[i][1];
                
                int a1 = bl[j][0];
                int b1 = bl[j][1];
                int a2 = tr[j][0];
                int b2 = tr[j][1];
                
                int xs = max(a1, x1);
                int xe = min(a2, x2);
                
                if (xs >= xe) continue;
                
                int ys = max(b1, y1);
                int ye = min(b2, y2);
                
                if (ys >= ye) continue;
                
                int dx = (xe-xs);
                int dy = (ye-ys);
                ll side = min(dx, dy);
                
                ans = max(ans, side*side);
                
            }
        }
        
        return ans;
    }
};