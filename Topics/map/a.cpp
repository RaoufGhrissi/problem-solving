#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToPartition(vector<int>& v, int k) {
        int n = v.size();
        map<int,int> mp, mp2;
        vector<int> cum = v;
        vector<int> right(n, 0);
        int ans = 0;

        for (int i=0 ; i<n ; i++) {
            if (i)
                cum[i] += cum[i-1];

            if (i == n-1 && cum[n-1]%2 == 0)
                ans = mp[cum[n-1]/2];

            mp[cum[i]]++;
            mp2[cum[i]]++;      
        }

        for (int i=0 ; i<n ; i++) {
            if (v[i] == k) {
                mp[cum[i]]--;
                continue;
            }
            int target = cum[n-1] + v[i] - k;

            if (!(target&1) && mp.count(target/2)) {
                right[i] = mp[target/2];
                if (target/2 == cum[n-1])
                    right[i]--;
            }

            mp[cum[i]]--;
        }
        
        mp2[cum[n-1]]--;
        for (int i=n-2 ; i>-1 ; i--) {
            mp2[cum[i]]--;
            if (v[i] == k) continue;
            int target2 = cum[n-1] - v[i] + k;
            int l = 0;
            
            if (!(target2&1) && mp.count(target2/2)) {
                l = mp2[target2/2];
            }

            ans = max(ans, l+right[i]);
            
        }

        return ans; 
    }
};


int main() {
    vector<int> v = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70143,0,0};
    cout<<Solution().waysToPartition(v, 70143);   
}