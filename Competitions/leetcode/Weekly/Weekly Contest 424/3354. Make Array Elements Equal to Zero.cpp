#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans = 0;
    int n;

    void backtrack(int i, int step, vector<int>& v, int &sm) { // i: actual position, step = +-1
        if (i < 0 || i>=n) {
            if (!sm) ans++;
            return;
        }
        
        if (!sm) { // stoping condition
            ans++;
            return;
        }

        if (!v[i]) {
            backtrack(i+step, step, v, sm);
        } else {
            v[i]--;
            sm--;
            int s = step > 0 ? -1 : 1;
            backtrack(i+s, s, v, sm);
            v[i]++; // rollback leli 3maltou, nraja3 l vector kima ken mel awel
            sm++; // 
        }
    }

    int countValidSelections(vector<int>& v) {
        n = v.size();
        int sm = 0;

        for (int i=0 ; i<n ; i++)
            sm += v[i]; 

        for (int i=0 ; i<n ; i++) {
            if (v[i]) continue;
            backtrack(i, 1, v, sm);
            backtrack(i, -1, v, sm);
        }

        return ans;
    }
};