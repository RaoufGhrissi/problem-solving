#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
        int i = 0;
        int inf = 1e9 + 1;
        int j = inf;
        int n = v.size();

        while(i<j) {
            int mid = (i+j)/2;

            int groups = 0;
            int size = 0;
            for (int x=0 ; x<n ; x++) {
                if (v[x] <= mid) {
                    size++;
                } else {
                    size=0;
                }

                if (size == k) {
                    groups++;
                    size = 0;
                }
            }

            if (groups >= m) {
                j = mid;
            } else {
                i = mid+1;
            }
        }


        return i==inf ? -1 : i;
    }
};