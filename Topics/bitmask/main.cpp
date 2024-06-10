#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& v) {
        int tr = 1e5;
        int N = 2*tr;
        vector<ll> mask(N, 0);
        int n = v.size();

        for (int i=0 ; i<n ; i++) {
            for (auto &a:v[i]) {
                int tt = a+tr;
                mask[tt] |= 1ll<<i;
            }
        }

        vector<int> occ(n, 0);
        int i=0;
        int j=0;
        ll x=0;
        ll t = (1ll<<n)-1;

        int s=0, e=1e9;

        while(j<N) {
            if (x < t) {
                for (int b=0 ; b<n ; b++) {
                    int msk = 1ll<<b;
                    if (msk&mask[j]) {
                        occ[b]++;
                    }
                }

                x |= mask[j];
                j++;
            } else {
                if (e-s > j-1-i) {
                    e = j-1;
                    s = i;
                }

                for (int b=0 ; b<n ; b++) {
                    int msk = 1ll<<b;
                    if (msk&mask[i]) {
                        occ[b]--;
                        if (!occ[b]) {
                            x ^= msk;
                        }
                    }
                }

                i++;
            }
        }

        //while(i<j) later
        
        return {s-tr, e-tr};
    }
};

int main() {
    vector<vector<int>> v = {{10, 10}, {11, 11}};// {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    auto a = Solution().smallestRange(v);
}