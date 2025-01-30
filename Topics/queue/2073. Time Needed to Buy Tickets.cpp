#include <bits/stdc++.h>

using namespace std;

class Solution {    
public:
    int timeRequiredToBuy(vector<int>& v, int k) {
        // without queue (one pass)
        int ans = 0;

        int n = v.size();
        for (int i=0 ; i<n ; i++) {
            if (i<k) {
                ans += min(v[i], v[k]);
            } else if (i > k) {
                ans += min(v[i], v[k]-1);
            }
        }

        //return ans + v[k];

        // simulation with queue

        queue<int> q;
        ans = 0;

        for (int i=0 ; i<n ; i++) {
            q.push(i);
        }

        while(v[k] > 0) { // tant que mezel andou mayechri
            int f = q.front();
            q.pop();

            v[f]--; // ncharih f ticket
            ans++; // chra ticket = kle seconda

            if (v[f]) // ken mezel andou mayechri nraj3ou fil ekher saf
                q.push(f);
        }

        return ans; // total secondet
    }
};