#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    vector<ll> mid;
    int n, x;

    ll dp[100005][16];

    ll rec(int i, int k) {
        if (k == 0) {
            return 0;
        }

        if (i+x-1 >= n) return 1e14;

        ll &ans = dp[i][k];

        if (ans != -1)
            return ans;

        return ans = min(rec(i+1, k), mid[i] + rec(i+x, k-1));
    }
    
    ll minOperations(vector<int>& v, int _x, int k) {
        multiset<ll> left, right;
        x = _x;
        
        bool even = !(x&1);
        n = v.size();
        int cap = even ? x/2 : x/2 + 1;
        ll smLeft = 0, smRight = 0;
            
        for (int i=0 ; i<x ; i++) {
            if (left.size() < cap) {
                left.insert(v[i]);
                smLeft += v[i];
            } else {
                int mx = *left.rbegin();
                
                if (mx < v[i]) {
                    right.insert(v[i]);
                    smRight += v[i];
                } else {
                    right.insert(mx);
                    left.erase(left.lower_bound(mx));
                    left.insert(v[i]);
                    
                    smRight += mx;
                    smLeft += v[i];
                    smLeft -= mx;
                }
            }
        }
        
        mid.clear();
        mid.push_back(0);
        
        if (even) {
            // try first mid
            int prev = x/2 - 1;
            int next = x/2;
            
            int median = *left.rbegin();
            mid[0] = prev*median - (smLeft - median) + smRight - next*median; 
                
            // try second mid
            
            prev++;
            next--;
            median = *right.begin();
            
            mid[0] = min(mid[0], prev*median - smLeft + (smRight - median) - next*median);
        } else {
            int prev = x/2;
            int next = x/2;
            
            ll median = *left.rbegin();
            mid[0] = prev*median - (smLeft - median) + smRight - next*median;
        }
        
        int i = 1;
        int j = x;
        
        while(j<n) {
            if (left.count(v[i-1])) {
                left.erase(left.lower_bound(v[i-1]));
                smLeft -= v[i-1];
            } else {
                right.erase(right.lower_bound(v[i-1]));
                smRight -= v[i-1];
            }

            if (left.size() < cap) {
                left.insert(v[j]);
                smLeft += v[j];
            } else {
                right.insert(v[j]);
                smRight += v[j];
            }

            int mx = *left.rbegin();
            int mi = *right.begin(); 
            if (mx > mi) {
                // swap
                left.erase(left.lower_bound(mx));
                smLeft -= mx;

                left.insert(mi);
                smLeft += mi;

                right.erase(right.lower_bound(mi));
                smRight -= mi;

                right.insert(mx);
                smRight += mx;
            }

            if (even) {
                // try first mid
                int prev = x/2 - 1;
                int next = x/2;
                
                int median = *left.rbegin();
                ll res = prev*median - (smLeft - median) + smRight - next*median; 
                    
                // try second mid
                
                prev++;
                next--;
                median = *right.begin();
                
                res = min(res, prev*median - smLeft + (smRight - median) - next*median);
                mid.push_back(res);
            } else {
                int prev = x/2;
                int next = x/2;
                
                ll median = *left.rbegin();
                mid.push_back(prev*median - (smLeft - median) + smRight - next*median);
            }
            j++;
            i++;
        }

        memset(dp, -1, sizeof dp);

        return rec(0, k);
    }
};