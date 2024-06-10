#include <bits/stdc++.h>
//https://leetcode.com/problems/subarray-product-less-than-k/description/
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        int n = v.size();
        int ans = 0;
        int prod = 1;

        int i = 0;
        int j = 0;

        while(j<n) {
            if (i==j && v[i] >= k) {
                i++;
                j++;
                continue;
            }

            if (prod*v[j] < k) {
                prod *= v[j];
                j++;
            } else {
                ans += j-i+1;
                prod /= v[i];
                i++;
            }
        }

        if (prod < k) {
            int nn = j-i;
            ans += nn*(nn+1)/2;
        }

        return ans;
    }
};


int main() {
    vector<int> v = {10, 5, 2, 6};
    cout<<Solution().numSubarrayProductLessThanK(v, 100);
}