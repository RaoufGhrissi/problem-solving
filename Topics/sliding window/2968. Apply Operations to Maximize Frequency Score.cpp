#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Solution {
public:
    ll comp(vector<ll> &cum, vector<int> &v, int &mid, int &j, int &i) {
        ll kmid = cum[j]-cum[mid] - v[mid]*(j-mid);

        if (mid)
            kmid += v[mid]*(mid-i);

        ll ded = 0;

        if (mid) {
            ded = cum[mid-1];
            if (i)
                ded -= cum[i-1];
        }

        return kmid - ded;
    }
    int maxFrequencyScore(vector<int>& v, long long k) {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<ll> cum(n, 0);

        for (int i=0 ; i<n ; i++) {
            cum[i] = v[i];
            if (i)
                cum[i] +=  cum[i-1];
        }

        int ans = 0;
        int i = 0;
        int j = 0;

        while(j<n) {
            int d = (j-i+1);
            int mid = (i+j)/2;

            ll kmid = comp(cum, v, mid, j, i);

            if (kmid <= k) {
                j++;
                ans = max(ans, d);
                continue;
            }

            if (d > 2 && !(d&1)) {
                int mid2 = mid+1;
                if (comp(cum, v, mid2, j, i) <= k) {
                    ans = max(ans, d);
                    j++;
                    continue;
                }
            }

            i++;

        }

        return ans;
    }
};

int main() {
    vector<int> v= {1,2,6,4};
    cout<<Solution().maxFrequencyScore(v, 3);
}