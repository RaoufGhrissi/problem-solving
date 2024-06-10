#include <bits/stdc++.h>
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& v, int k) {
        int mx = *max_element(v.begin(), v.end());
        int cum = 0, n = v.size();
        map<int,int> id;
        for (int i=0 ; i<n ; i++) {
            cum += v[i] == mx;
            if (!id.count(cum)) id[cum] = i;
        }

        cum = 0;
        long long ans = 0;
        for (int i=0 ; i<n ; i++) {
            int target = k + cum;
            if (id.count(target)) ans += n - id[target];
            cum += v[i] == mx;
        }

        return ans;
    }
};