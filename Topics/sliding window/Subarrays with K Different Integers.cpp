#include <bits/stdc++.h>
//https://leetcode.com/problems/subarrays-with-k-different-integers/description/
using namespace std;

class Solution {
public:
    int lowerOrEqual(vector<int> &v, int k) {
        int i = 0;
        int j = 0;
        int n = v.size();
        int ans = 0;
        map<int,int> occ;

        while(j<n) {
            if (occ.count(v[j]) || occ.size() < k) {
                ++occ[v[j++]];
            } else {
                ans += j-i;
                --occ[v[i]];
                if (!occ[v[i]]) occ.erase(v[i++]);
            }
        }

        return ans + (j-i);
    }

    int subarraysWithKDistinct(vector<int>& v, int k) {
        return lowerOrEqual(v, k) - lowerOrEqual(v, k-1);   
    }
};

int main() {
    vector<int> v = {1,2,1,2,3};
    cout<<Solution().lowerOrEqual(v, 2);
}