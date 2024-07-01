#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxHeightOfTriangle(int r, int b) {
        int l = 1;
        bool blue = 1;
        int rr = r;
        int bb = b;
        while(1) {
            if (blue) {
                if (b >= l) {
                    b -= l;
                    l++;
                } else {
                    break;
                }
            } else {
                if (r >= l) {
                    r -= l;
                    l++;
                } else {
                    break;
                }
            }
            
            blue = !blue;
        }
        
        int ans = l-1;
        
        l = 1;
        r = rr;
        b = bb;
        blue = 0;
        while(1) {
            if (blue) {
                if (b >= l) {
                    b -= l;
                    l++;
                } else {
                    break;
                }
            } else {
                if (r >= l) {
                    r -= l;
                    l++;
                } else {
                    break;
                }
            }
            
            blue = !blue;
        }
        
        return max(ans, l-1);
    }
};
