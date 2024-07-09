#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& v, int m) {
        sort(v.begin(), v.end());
        int n = v.size();
        int lastPos = -1e9;
        
        int i = 0;
        int j = 1e9;

        while(i<j) {
            int mid = (i+j+1)/2;
            int mm = m;
            int prev = -1e9;

            for (int x=0 ; x<n; x++) {
                if (v[x]-prev >= mid) {
                    prev=v[x];
                    mm--;
                }
            }

            if (mm<=0) {
                i = mid;
            } else {
                j = mid-1;
            }
        }



        return i;
    }
};