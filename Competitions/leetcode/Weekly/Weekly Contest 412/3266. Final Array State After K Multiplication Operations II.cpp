#include <bits/stdc++.h>

using namespace std;


#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;

    long long binpow(long long a, long long b) {
        //https://cp-algorithms.com/algebra/binary-exp.html
        long long res = 1;
        while (b > 0) {
            if (b & 1) {
                res = res * a;
                res %= mod;
            }

            a = a * a;
            a %= mod;
            b >>= 1;
        }

        return res;
    }

    vector<int> getFinalState(vector<int>& v, int k, int m) {
        if(m == 1) return v;

        int n = v.size();
        ll mx = *max_element(v.begin(), v.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0 ; i<n ; i++){
            pq.push({v[i], i});
        }

        while (k && m*1ll*pq.top()[0] <= mx) {
            pq.push({m*pq.top()[0], pq.top()[1]});
            pq.pop();
            k--;
        }

        ll pow = binpow(m, k/n);
        ll rest = k%n;
        while (!pq.empty()) {
            int val = pq.top()[0];
            int id = pq.top()[1];
            pq.pop();

            if (rest > 0) {
                rest--;
                v[id] = ((m*1ll*pow)%mod * val)%mod; 
            } else {
                v[id] = (pow*1ll*val)%mod;
            }
        }
        return v;
    }
};