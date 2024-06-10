#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s, int k) {
        map<char,int> occ;
        for (auto &c:s) occ[c]++;
        int tot = 0;
        
        vector<int> v;
        for (auto &a:occ)
            v.push_back(a.second);

        sort(v.begin(), v.end());
        int n = v.size();

        vector<int> cum = v;
        for (int i=1 ; i<n ; i++)
            cum[i] += cum[i-1];
        
        int i = 0;
        int j = 0;
        int ans = 1e9;

        while (j<n) {
            if (v[j]-v[i] <= k) {
                j++;
            } else {
                int del = 0;
                if (i) del += cum[i-1];
                int cnt = n-j;
                del += (cum[n-1] - cum[j-1]) - cnt*(v[i]+k);
                ans = min(del, ans);
                i++;
            }
        }

        int del = 0;
        if (i) del += cum[i-1];
        int cnt = n-j;
        del += (cum[n-1] - cum[j-1]) - cnt*(v[i]+k);
        ans = min(del, ans);

        return ans; 
    }
};

int main() {
    cout<<Solution().minimumDeletions("dabdcbdcdcd", 2);
    return 0;
}