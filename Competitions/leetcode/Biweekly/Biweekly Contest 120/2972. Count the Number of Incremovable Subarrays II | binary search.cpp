#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    bool can(int i, int m, int n, int mid, vector<int> &cum, vector<int> &v) {
        ll cnt = cum[m-1];
        ll length = n-1-mid;
        ll left = m-1-length;
        if (left >= 0)
            cnt -= cum[left];
        
        bool ok = cnt == length; // is right strictly increasing
        if (ok && i) {
            ok &= v[mid] > v[i-1]; 
        }

        return ok;
    }

    long long incremovableSubarrayCount(vector<int>& v) {
        ll n = v.size();
        int m = n-1;
        vector<int> cum(m, 0);

        int p = 0;
        for (int i=1 ; i<n ; i++) {
            if (v[i] > v[i-1])
                cum[p] = 1;

            if (p)
                cum[p] += cum[p-1];
            
            p++;
        }

        ll ans = 0;
        for (int i=0 ; i<n ; i++) {
            if (i>1 && cum[i-2] != i-1)
                continue; // pre non strictly increasing

            if (!can(i, m, n, n-1, cum, v)) {
                ans++;
                continue;
            }

            ll s = i+1;
            ll e = n-1;

            while(s<e) {
                int mid = (s+e)/2;

                if (can(i, m, n, mid, cum, v)) {
                    e = mid;
                } else {
                    s = mid+1;
                }
            }

            ans += n-s+1;
        }   

        return ans;
    }
};

int main() {
    vector<int> v = {1, 5};
    cout<<Solution().incremovableSubarrayCount(v);
}