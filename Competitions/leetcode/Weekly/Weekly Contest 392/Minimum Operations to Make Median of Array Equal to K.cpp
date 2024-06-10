#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int n = v.size();
        int mid = n/2;

        if (v[mid] == k) return 0;
        else if (v[mid] < k) {
            long long ans = 0;
            while(mid < n && v[mid] < k) {
                ans += k-v[mid];
                mid++;
            }
            return ans;
        } else {
            long long ans = 0;
            while(mid > -1 && v[mid] > k) {
                ans += v[mid]-k;
                mid--;
            }
            return ans;
        }
    }
};