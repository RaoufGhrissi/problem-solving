#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

#define ll long long
class Solution {
public:
    ll maximumValueSum(vector<int>& v, int k, vector<vector<int>>& edges) {
        ll tot = 0, totPos = 0;
        vector<ll> pos;
        vector<ll> neg;
        
        for (auto &a:v) {
            tot += a;
            int x = a^k;
            if (x > a) {
                pos.push_back(x-a);
                totPos += x-a;
            } else
                neg.push_back(a-x);
        }
        
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        int n = pos.size();
                
        if (!n)
            return tot;
        
        if (n&1) {
            int minPos = pos[0];
            if (!neg.size()) {
                return tot+totPos-minPos;
            }
            
            int minNeg = neg[0];
                        
            if (minPos > minNeg) {
                return tot+totPos-minNeg;
            }
            
            return tot+totPos-minPos;
        } else {
            return tot+totPos;
        }
    }
};