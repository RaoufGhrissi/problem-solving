#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int mod = 1e9 + 7;

    int get_cnt(int n, int mid, vector<int> &v) {
        int cnt = 0;
        for (int i=0 ; i<n ; i++) {
            int t = mid;
            if (i) t += v[i-1];
            int pos = lower_bound(v.begin(), v.end(), t) - v.begin();
            if (pos == n || v[pos] > t)
                pos--;

            if (pos >= i)
                cnt += pos-i+1;
        }
        return cnt;
    }

    int rangeSum(vector<int>& v, int n, int left, int right) {
        for (int i=1 ; i<n ; i++)
            v[i] += v[i-1];

        for (int i=0 ; i<n ; i++)
            cout<<v[i]<<" ";

        cout<<endl;

        vector<int> cum = v;
        for (int i=1 ; i<n ; i++)
            cum[i] += cum[i-1];

        for (int i=0 ; i<n ; i++)
            cout<<cum[i]<<" ";

        cout<<endl;

        int s=0;
        int e=100;

        while(s<e) {
            int mid = (s+e)/2;

            int cnt = get_cnt(n, mid, v);
            if (cnt < left) {
                s = mid+1;
            } else {
                e = mid;
            }
        }

        int l = s;
        s=0;
        e=100;

        while(s<e) {
            int mid = (s+e+1)/2;
            int cnt = get_cnt(n, mid, v);
            if (cnt <= right) {
                s = mid;
            } else {
                e = mid-1;
            }
        }

        int r = s;
        int mi = 1e9;
        int mx = 0;
        int ans = 0;

        for (int i=0 ; i<n ; i++) {
            int t1 = l;
            int t2 = r;

            if (i) {
                t1 += v[i-1];
                t2 += v[i-1];
            }

            int posL = lower_bound(v.begin(), v.end(), t1) - v.begin();

            if (posL == n)
                continue;

            int posR = upper_bound(v.begin(), v.end(), t2) - v.begin();

            if (posR == n || v[posR] > t2) {
                posR--;
            }

            if (posR < 0)
                continue;

            int res = cum[posR];
            if (posL)
                res -= cum[posL-1];

            int sz = posR-posL+1;

            if (i)
                res -= v[i-1]*sz;
            
            ans += res%mod;
            
            mi = min(mi, i ? v[posL] - v[i-1] : v[posL]);
            mx = max(mx, i ? v[posR] - v[i-1] : v[posR]);
        }

        int rest = left - get_cnt(n, mi-1, v) - 1;

        while(rest > 0) {
            ans -= mi;
            rest--;
        }

        rest = get_cnt(n, mx, v) - right;

        while(rest > 0) {
            ans -= mx;
            rest--;
        }

        return ans;
    }
};

int main() {
    vector<int> v = {7,5,8,5,6,4,3,3};
    cout<<Solution().rangeSum(v, 8, 2, 6);
}