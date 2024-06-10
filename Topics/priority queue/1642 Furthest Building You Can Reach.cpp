#include <bits/stdc++.h>

//https://leetcode.com/problems/furthest-building-you-can-reach/description/
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& v, int b, int l) {
        int n = v.size();
        priority_queue<int> pq;
        for (int x=0 ; x<n-1 ; x++) {
            int diff = v[x+1]-v[x];
            if (diff <= 0)
                continue;

            pq.push(diff);
            b -= diff;

            if (b < 0) {
                b += pq.top();
                pq.pop();
                l--;   
            }
            
            if (l<0)
                return x;
        }

        return n-1;
    }
};


int findMax(int i, int l, int b, vector<int> &h) {
    if (i == h.size()-1)
        return i;

    int diff = h[i+1]-h[i];
    if (h[i+1] <= h[i]) {
        return findMax(i+1, l, b, h);
    }

    int ans = i;

    if (l>0) {
        ans = max(ans, findMax(i+1, l-1, b, h));
    }

    if (b>=diff) {
        ans = max(ans, findMax(i+1, l, b-diff, h));
    }

    return ans;
}



int main() {
    vector<int> v = {4,2,7,6,9,14,12};
    cout<<Solution().furthestBuilding(v, 5, 1);
    return 0;
}