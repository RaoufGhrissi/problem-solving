#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int smallestDistancePair(vector<int>& v, int k) {
        sort(v.begin(), v.end());

        int s=0, e=1e6, n=v.size(); 

        while(s<e) {
            int mid = (s+e)/2;

            int cnt = 0;
            int i=0;
            int j=1;

            while(j<n) {
                if (v[j]-v[i] <= mid) {
                    j++;
                } else {
                    cnt += j-i-1;
                    i++;
                }
            }

            while(i<n) {
                cnt += j-i-1;
                i++;
            }

            if (cnt < k)
                s = mid+1;
            else
                e = mid;
        }

        return s;
    }
};