#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& v) {
        int n = v.size();

        vector<int> mx(n); 

        for (int i=0 ; i<n ; i++) {
            mx[i] = 1; // max increasing subaary ending by i
            if (i && v[i] > v[i-1])
                mx[i] += mx[i-1]; // nafs logique LIS tfarej feha 
        }

        int prev = 0;
        int ans = 0;
        for (int i=n-1 ; i>-1 ; i--) {
            int actual = 1;

            if (i < n-1 && v[i] < v[i+1])
                actual += prev;

            if (i)
                ans = max(ans, min(mx[i-1], actual)); // max bin youfa eli 9abli increasing w yabda andi ena increasing
            
            prev = actual;
        }

        return ans;
    }
};
