#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bs(int n, int m, int mx) {
        int s=1;
        int e=m;

        while(s<e) {
            int mid = (s+e+1)/2;

            int x = n*mid;
            if (x == mx)
                return mid;
            else if (x < mx)
                s = mid;
            else
                e = mid-1;
        }

        return s;
    }

    int findKthNumber(int n, int m, int k) {
        int s = 0;
        int e = 1e9;

        while(s<e) {
            int mid = (s+e)/2;

            int cnt = 0;
            for (int i=1 ; i<=n ; i++) {
                if (i > mid) break;
                cnt += bs(i, m, mid);
            }

            if (cnt >= k)
                e = mid;
            else
                s = mid+1;
        }

        return s;
    }
};