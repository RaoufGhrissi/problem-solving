#include <bits/stdc++.h>

// tags: segTree / prefix sum / binary search / lower bound / upper bound / monotonie
// nice educational problem

using namespace std;

#define ll long long

class PrefixAnd {
    public:
        int cum[100][30];

    PrefixAnd(vector<int> &v) {
        memset(cum, 0, sizeof cum);
        int n = v.size();
        for (int i=0 ; i < n ; i++) {
            for (int x=0 ; x<30 ; x++) {
                int mask = 1<<x;
                if (!(v[i]&mask)) {
                    cum[i][x] = 1;
                }

                if (i) cum[i][x] += cum[i-1][x];
            }
        }
    }

    int get(int l, int r) {
        int ans = 0;

        for (int x=0 ; x<30 ; x++) {
            int zeros = cum[r][x];
            if (l)
                zeros -= cum[l-1][x];

            if (!zeros)
                ans |= (1<<x);
        }

        return ans;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& v, int k) {
        PrefixAnd prefixAnd = PrefixAnd(v);
        int ans = 0;

        int n = v.size();
        for (int i=0 ; i<n ; i++) {
            //lower_bound
            int l = i;
            int r = n-1;

            while(l<r) {
                int mid = (l+r)/2;
                int _and = prefixAnd.get(i, mid);

                if (_and > k)
                    l = mid+1;
                else if (_and < k)
                    r = mid-1;
                else
                    r = mid;
            }

            if (prefixAnd.get(i, l) != k)
                continue;

            int _l = l;

            //upper_bound
            l = i;
            r = n-1;

            while(l<r) {
                int mid = (l+r+1)/2;
                int _and = prefixAnd.get(i, mid);

                if (_and > k)
                    l = mid + 1;
                else if (_and < k)
                    r = mid - 1;
                else
                    l = mid;
            }

            ans += r-_l+1;
        }

        return ans;
    }
};

int main() {
    vector<int> v = {1, 1, 2};
    int k = 1;
    cout<<Solution().countSubarrays(v, k);
}