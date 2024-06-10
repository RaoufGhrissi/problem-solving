#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define pp pair<char,int>

#define ll long long

class Solution {
public:
    long long numberOfPairs(vector<int>& v1, vector<int>& v2, int k) {
        unordered_map<int,int> occ;
        for (auto &a:v2)
            occ[a]++;
        
        ll ans = 0;
        
        for (auto &a:v1) {
            for (int i=1 ; i<=sqrt(a) ; i++) {
                if (a%i == 0) {
                    int q = a/i;
                    if (q>=k && (q%k == 0) && occ.count(i)) {
                        ans += occ[i];
                    }
                    
                    if (i != q && i>=k && (i%k == 0) && occ.count(q)) {
                        ans += occ[q];
                    }
                }
                
            }    
        }
        
        return ans;
    }
};