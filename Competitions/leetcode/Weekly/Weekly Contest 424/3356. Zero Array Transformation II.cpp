#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(int mid, int n, vector<int>& nums, vector<vector<int>>& q) {
        vector<int> v(n, 0);
        for (int x=0 ; x<mid ; x++) {
            int s = q[x][0];
            int e = q[x][1];
            int val = q[x][2];

            v[s] += val;
            
            if (e+1 < n)
                v[e+1] -= val;
        }

        for (int x=0 ; x<n ; x++) {
            if (x)
                v[x] += v[x-1];
            if (v[x] < nums[x]) {
                return 0;
            }
        }

        return 1;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int i = 0;
        int j = q.size();

        int n = nums.size();

        while(i<j) {
            int mid = (i+j)/2;

            if (check(mid, n, nums, q)) {
                j = mid;
            } else {
                i = mid+1;
            }
        }

        return check(i, n, nums, q) ? i : -1;
    }
};