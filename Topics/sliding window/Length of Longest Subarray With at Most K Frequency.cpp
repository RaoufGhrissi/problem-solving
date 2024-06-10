#include <bits/stdc++.h>
//https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& v, int k) {
        int n = v.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        map<int,int> occ;

        while(j<n) {
            if (occ[v[j]] + 1 <= k) ++occ[v[j++]];
            else --occ[v[i++]];
            ans = max(ans, j-i);
        }

        return ans;
    }
};

int main() {
    vector<int> v = {1,2,3,1,2,3,1,2};
    cout<<Solution().maxSubarrayLength(v, 2);
}