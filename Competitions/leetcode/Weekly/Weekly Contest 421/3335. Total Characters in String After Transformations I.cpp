#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

#define ll long long

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<ll> fq(26, 0);
        const ll mod = 1e9 + 7;
        ll res = s.size();
        
        for(char &c:s)
            fq[c-'a']++;

        while(t--) {
            ll z = fq[25];
            
            res += z;
            res %= mod;
            
            for(int i=25; i>=1 ;i--)
                fq[i]=fq[i-1];
            
            fq[0] = z;
            fq[1] += z;
            fq[1] %= mod;
        }
        return res;
    }
};