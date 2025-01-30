#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& v, int k) {
        queue<int> limits;
        int ans = 0;
        int n = v.size();

        for (int i=0 ; i<n ; i++) {
            while(!limits.empty() && limits.front() < i) // fetni maach y2ather 3leya
                limits.pop();

            int flips = limits.size();
            if ((v[i] && !(flips&1)) || (!v[i] && flips&1)) continue;

            if (i+k-1 > n-1) return -1;
            ans++;
            limits.push(i+k-1); // limite l flip jdida
        }

        return ans;
    }
};