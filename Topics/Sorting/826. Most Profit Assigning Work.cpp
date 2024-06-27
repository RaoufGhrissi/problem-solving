#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>
class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pp> v;
        int n = d.size();
        for (int i=0 ; i<n ; i++)
            v.push_back({d[i], p[i]});
        sort(v.begin(), v.end());
        int ans = 0;
        sort(w.begin(), w.end());
        int mx = 0;
        int i = 0;
        for (auto &a:w) {
            while(i<n && v[i].first <= a) {
                mx = max(mx, v[i].second);
                i++;
            }

            ans += mx;
        }    
    
        return ans;
    }
};