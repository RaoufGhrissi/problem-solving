        #include <bits/stdc++.h>
        #define ll long long
        #define pp pair<int,int>

        using namespace std;

        class Sieve {
            public:
                const static int N = 1e6;
                bool prime[N];
            
                Sieve() {
                    memset(prime, 1, sizeof prime);
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
    const static int D = 8;
    int dx[D] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[D] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    bool safe(int i, int j, int n, int m) {
        return i>-1 && j>-1 && i<n && j<m;
    }
    
    void traverse(int i, int j, int &di, int &dj, int &n, int &m, int &num, vector<vector<int>>& v, Sieve &sieve, vector<int> &occ) {
        if (!safe(i, j, n, m))
            return ;
        
        num = num*10 + v[i][j];
        
        if ( num > 10 && sieve.prime[num]) {
            occ[num]++;
        }
        
        return traverse(i+di, j+dj, di, dj, n, m, num, v, sieve, occ);
    }
    
    int mostFrequentPrime(vector<vector<int>>& v) {
        Sieve sieve = Sieve();
        int n = v.size();
        int m = v[0].size();
        int ans = 0;
        const int N = 1e6;
        vector<int> occ(N, 0);
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                for (int dd=0 ; dd<D ; dd++) {
                    int num = 0;
                    traverse(i, j, dx[dd], dy[dd], n, m, num, v, sieve, occ);
                }        
            }
        }
    
        for (int i=1 ; i<N ; i++) {
            if (occ[i] >= occ[ans]) {
                ans = i;
            }
        }
        
        return occ[ans] ? ans : -1;
    }
};