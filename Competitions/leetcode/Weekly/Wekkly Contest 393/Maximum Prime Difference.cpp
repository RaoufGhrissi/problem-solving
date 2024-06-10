#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Sieve {
    public:
        const static int N = 1e6;
        bool prime[N];
    
        Sieve() {
            memset(prime, 1, sizeof prime); // optimized (dp, barcha dp, kol mara lezem tarja3 -1)
            prime[0] = 0;
            prime[1] = 0;
            for (int i=2 ; i<=sqrt(N) ; i++) {
                if (!prime[i]) continue;
                int x = 2*i;
                while(x<N) {
                    prime[x] = 0;
                    x += i;
                }
            }
        }
};

class Solution {
public:
    int maximumPrimeDifference(vector<int>& v) {
        Sieve s = Sieve(); // preprocessing

        int mi = 1e6;
        int mx = 0;

        int n = v.size();
        for (int i=0 ; i<n ; i++) {
            if (s.prime[v[i]]) { // o(1)
                mi = min(mi, i);
                mx = max(mx, i);
            }
        }
        return mx-mi;
    }
};