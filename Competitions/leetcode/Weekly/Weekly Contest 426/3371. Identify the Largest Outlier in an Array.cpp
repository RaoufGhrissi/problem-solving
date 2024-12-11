#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int>& v) {
        map<int,int> mp;

        int n = v.size();
        int tot = 0;
        for (int i=0 ; i<n ; i++) {
            tot += v[i];
            mp[v[i]]++;
        }

        int ans = -1000;
        for (int i=0 ; i<n ; i++) {
            int rest = tot - 2*v[i];

            if (!mp.count(rest)) continue;

            if (rest == v[i] && mp[rest] == 1) continue;
            
            ans = max(ans, rest);
        }

        return ans;
    }
};